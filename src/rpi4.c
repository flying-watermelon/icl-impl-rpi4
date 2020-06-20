#include "context.h"
#include "data.h"
#include "utilities.h"

#include <ICL/ICL_impl_rpi4.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

void _initializeI2c();
void _finalizeI2c();

void _initializeSpi();
void _finalizeSpi();

int icl_rpi4_initialize(unsigned int initializeFlags) {
    int memFd;
    void *memMap;

    if ((memFd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        return ICL_RPI4_INITIALIZATION_ERROR;
    }

    memMap = mmap(
        NULL,
        PERI_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        memFd,
        PERI_BASE);

    close(memFd);

    if (memMap == MAP_FAILED) {
        return ICL_RPI4_INITIALIZATION_ERROR;
    }

    periBase = (volatile unsigned char *)memMap;

    gpioBase = periBase + GPIO_BASE;

    if (initializeFlags | ICL_RPI4_INITIALIZE_I2C) {
        _initializeI2c();
    }

    if (initializeFlags | ICL_RPI4_INITIALIZE_SPI) {
        _initializeSpi();
    }

    return 0;
}

int icl_rpi4_finalize() {
    if (i2cBase != NULL) {
        _finalize_i2c();
    }

    if (spiBase != NULL) {
        _finalize_spi();
    }

    munmap((void *)periBase, PERI_SIZE);

    return 0;
}

void _initializeI2c() {
    i2cBase = periBase + I2C_BASE;

    selectGpioPinFunction(I2C_PIN_SDA, GPIO_FSEL_ALT0);
    selectGpioPinFunction(I2C_PIN_SCL, GPIO_FSEL_ALT0);
}

void _finalizeI2c() {
    selectGpioPinFunction(I2C_PIN_SDA, GPIO_FSEL_INPUT);
    selectGpioPinFunction(I2C_PIN_SCL, GPIO_FSEL_INPUT);
}

void _initializeSpi() {
    spiBase = periBase + SPI_BASE;

    volatile unsigned char *cs = spiBase + SPI_CS;

    selectGpioPinFunction(SPI_PIN_CE0, GPIO_FSEL_ALT0);
    selectGpioPinFunction(SPI_PIN_CE1, GPIO_FSEL_ALT0);
    selectGpioPinFunction(SPI_PIN_SCLK, GPIO_FSEL_ALT0);
    selectGpioPinFunction(SPI_PIN_MOSI, GPIO_FSEL_ALT0);
    selectGpioPinFunction(SPI_PIN_MISO, GPIO_FSEL_ALT0);

    writeRegister(cs, 0);
    writeRegisterMasked(cs, SPI_CS_CLEAR, SPI_CS_CLEAR);
}

void _finalizeSpi() {
    selectGpioPinFunction(SPI_PIN_CE0, GPIO_FSEL_INPUT);
    selectGpioPinFunction(SPI_PIN_CE1, GPIO_FSEL_INPUT);
    selectGpioPinFunction(SPI_PIN_SCLK, GPIO_FSEL_INPUT);
    selectGpioPinFunction(SPI_PIN_MOSI, GPIO_FSEL_INPUT);
    selectGpioPinFunction(SPI_PIN_MISO, GPIO_FSEL_INPUT);
}

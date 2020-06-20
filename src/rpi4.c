#include "context.h"
#include "data.h"
#include "utilities.h"

#include <ICL/ICL_impl_rpi4.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

void _initialize_i2c();
void _finalize_i2c();

void _initialize_spi();
void _finalize_spi();

int icl_rpi4_initialize(unsigned int initialize_flags) {
    int mem_fd;
    void *mem_map;

    if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        return ICL_RPI4_INITIALIZATION_ERROR;
    }

    mem_map = mmap(
        NULL,
        PERI_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        mem_fd,
        PERI_BASE);

    close(mem_fd);

    if (mem_map == MAP_FAILED) {
        return ICL_RPI4_INITIALIZATION_ERROR;
    }

    peri_base = (volatile unsigned char *)mem_map;

    gpio_base = peri_base + GPIO_BASE;

    if (initialize_flags | ICL_RPI4_INITIALIZE_I2C) {
        _initialize_i2c();
    }

    if (initialize_flags | ICL_RPI4_INITIALIZE_SPI) {
        _initialize_spi();
    }

    return 0;
}

int icl_rpi4_finalize() {
    if (i2c_base != NULL) {
        _finalize_i2c();
    }

    if (spi_base != NULL) {
        _finalize_spi();
    }

    munmap((void *)peri_base, PERI_SIZE);

    return 0;
}

void _initialize_i2c() {
    i2c_base = peri_base + I2C_BASE;

    select_gpio_pin_function(I2C_PIN_SDA, GPIO_FSEL_ALT0);
    select_gpio_pin_function(I2C_PIN_SCL, GPIO_FSEL_ALT0);
}

void _finalize_i2c() {
    select_gpio_pin_function(I2C_PIN_SDA, GPIO_FSEL_INPUT);
    select_gpio_pin_function(I2C_PIN_SCL, GPIO_FSEL_INPUT);
}

void _initialize_spi() {
    spi_base = peri_base + SPI_BASE;

    volatile unsigned char *cs = spi_base + SPI_CS;

    select_gpio_pin_function(SPI_PIN_CE0, GPIO_FSEL_ALT0);
    select_gpio_pin_function(SPI_PIN_CE1, GPIO_FSEL_ALT0);
    select_gpio_pin_function(SPI_PIN_SCLK, GPIO_FSEL_ALT0);
    select_gpio_pin_function(SPI_PIN_MOSI, GPIO_FSEL_ALT0);
    select_gpio_pin_function(SPI_PIN_MISO, GPIO_FSEL_ALT0);

    write_register(cs, 0);
    write_register_masked(cs, SPI_CS_CLEAR, SPI_CS_CLEAR);
}

void _finalize_spi() {
    select_gpio_pin_function(SPI_PIN_CE0, GPIO_FSEL_INPUT);
    select_gpio_pin_function(SPI_PIN_CE1, GPIO_FSEL_INPUT);
    select_gpio_pin_function(SPI_PIN_SCLK, GPIO_FSEL_INPUT);
    select_gpio_pin_function(SPI_PIN_MOSI, GPIO_FSEL_INPUT);
    select_gpio_pin_function(SPI_PIN_MISO, GPIO_FSEL_INPUT);
}

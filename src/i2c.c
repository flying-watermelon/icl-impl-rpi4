#include "ICL/ICL.h"
#include "context.h"
#include "data.h"
#include "utilities.h"

int icl_i2c_setBaudRate(int baud) {
    unsigned divider = CORE_CLOCK_HZ / baud;
    if (divider > 0xFFFF) {
        divider = 0;
    }
    if (divider < 0x0002) {
        divider = 0x0002;
    }
    writeRegister(i2cBase + I2C_DIV, divider);

    return ICL_NO_ERROR;
}

int icl_i2c_writeBytes(uint16_t slaveAddress, size_t count, const uint8_t *bytes) {
    volatile unsigned char *const address = i2cBase + I2C_A;
    volatile unsigned char *const control = i2cBase + I2C_C;
    volatile unsigned char *const status = i2cBase + I2C_S;
    volatile unsigned char *const dlen = i2cBase + I2C_DLEN;
    volatile unsigned char *const fifo = i2cBase + I2C_FIFO;

    writeRegister(address, slaveAddress);
    writeRegisterMasked(control, I2C_C_CLEAR_2, I2C_C_CLEAR_2);
    writeRegister(status, I2C_S_CLKT | I2C_S_ERR | I2C_S_DONE);
    writeRegister(dlen, count);

    size_t currentByteIndex = 0;
    size_t remainingBytes = count;

    while (remainingBytes > 0 && readRegisterMasked(status, I2C_S_TXD)) {
        writeRegister(fifo, bytes[currentByteIndex]);
        currentByteIndex++;
        remainingBytes--;
    }

    writeRegister(control, I2C_C_I2CEN | I2C_C_ST);

    while (remainingBytes > 0) {
        while (remainingBytes > 0 && readRegisterMasked(status, I2C_S_TXD)) {
            writeRegister(fifo, bytes[currentByteIndex]);
            currentByteIndex++;
            remainingBytes--;
        }
    }

    while (!readRegisterMasked(status, I2C_S_DONE))
        ;

    return ICL_NO_ERROR;
}

int icl_i2c_readBytes(uint16_t slaveAddress, size_t count, uint8_t *bytes) {
    volatile unsigned char *const address = i2cBase + I2C_A;
    volatile unsigned char *const control = i2cBase + I2C_C;
    volatile unsigned char *const status = i2cBase + I2C_S;
    volatile unsigned char *const dlen = i2cBase + I2C_DLEN;
    volatile unsigned char *const fifo = i2cBase + I2C_FIFO;

    writeRegister(address, slaveAddress);
    writeRegisterMasked(control, I2C_C_CLEAR_2, I2C_C_CLEAR_2);
    writeRegister(status, I2C_S_CLKT | I2C_S_ERR | I2C_S_DONE);
    writeRegister(dlen, count);
    writeRegister(control, I2C_C_I2CEN | I2C_C_ST | I2C_C_READ);

    size_t currentByteIndex = 0;
    size_t remainingBytes = count;

    while (!readRegisterMasked(status, I2C_S_DONE)) {
        while (remainingBytes > 0 && readRegisterMasked(status, I2C_S_RXD)) {
            bytes[currentByteIndex] = readRegister(fifo);
            currentByteIndex++;
            remainingBytes--;
        }
    }

    while (remainingBytes > 0 && readRegisterMasked(status, I2C_S_RXD)) {
        bytes[currentByteIndex] = readRegister(fifo);
        currentByteIndex++;
        remainingBytes--;
    }

    return ICL_NO_ERROR;
}

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

    return 0;
}

int icl_i2c_writeBytes(uint16_t slaveAddress, size_t count, const uint8_t *bytes) {
    return 0;
}

int icl_i2c_readBytes(uint16_t slaveAddress, size_t count, uint8_t *byte) {
    return 0;
}

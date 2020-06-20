#ifndef __UTILITIES_H__
#define __UTILITIES_H__

static inline void writeRegister(volatile unsigned char *addr, unsigned value) {
    *((volatile unsigned *)addr) = value;
}

static inline unsigned readRegister(volatile unsigned char *addr) {
    return *((volatile unsigned *)addr);
}

static inline void writeRegisterMasked(volatile unsigned char *addr, unsigned value, unsigned mask) {
    unsigned oldValue = readRegister(addr);
    unsigned newValue = (oldValue & ~mask) | (value & mask);
    writeRegister(addr, newValue);
}

static inline unsigned readRegisterMasked(volatile unsigned char *addr, unsigned mask) {
    return readRegister(addr) & mask;
}

void selectGpioPinFunction(int pin, unsigned function);

#endif
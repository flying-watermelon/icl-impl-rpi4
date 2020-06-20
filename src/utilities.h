#ifndef __REGISTER_H__
#define __REGISTER_H__

static inline void write_register(volatile unsigned char *addr, unsigned value) {
    *((volatile unsigned *)addr) = value;
}

static inline unsigned read_register(volatile unsigned char *addr) {
    return *((volatile unsigned *)addr);
}

static inline void write_register_masked(volatile unsigned char *addr, unsigned value, unsigned mask) {
    unsigned old_value = read_register(addr);
    unsigned new_value = (old_value & ~mask) | (value & mask);
    write_register(addr, new_value);
}

static inline unsigned read_register_masked(volatile unsigned char *addr, unsigned mask) {
    return read_register(addr) & mask;
}

void select_gpio_pin_function(int pin, unsigned function);

#endif
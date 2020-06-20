#include "utilities.h"
#include "context.h"
#include "data.h"

void select_gpio_pin_function(int pin, unsigned function) {
    unsigned shift = (pin % 10) * 3;
    write_register_masked(
        gpio_base + GPIO_FSEL0 + (pin / 10) * 4,
        GPIO_FSEL_ALT0 << shift,
        0x7 << shift);
}
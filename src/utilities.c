#include "utilities.h"

#include "context.h"
#include "data.h"

void selectGpioPinFunction(int pin, unsigned function) {
    unsigned shift = (pin % 10) * 3;
    writeRegisterMasked(
        gpioBase + GPIO_FSEL0 + (pin / 10) * 4,
        GPIO_FSEL_ALT0 << shift,
        0x7 << shift);
}
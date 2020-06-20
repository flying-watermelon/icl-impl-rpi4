#include "context.h"

#include <stddef.h>

volatile unsigned char *periBase = NULL;
volatile unsigned char *gpioBase = NULL;
volatile unsigned char *i2cBase = NULL;
volatile unsigned char *spiBase = NULL;
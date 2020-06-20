#include "context.h"

#include <stddef.h>

volatile unsigned char *peri_base = NULL;
volatile unsigned char *gpio_base = NULL;
volatile unsigned char *i2c_base = NULL;
volatile unsigned char *spi_base = NULL;
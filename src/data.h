#ifndef __DATA_H__
#define __DATA_H__

#define PERI_BASE 0xFE000000
#define PERI_SIZE 0x01800000

#define GPIO_BASE        0x200000
#define GPIO_FSEL0       0x00
#define GPIO_FSEL_INPUT  0x0
#define GPIO_FSEL_OUTPUT 0x1
#define GPIO_FSEL_ALT0   0x4
#define GPIO_FSEL_ALT1   0x5
#define GPIO_FSEL_ALT2   0x6
#define GPIO_FSEL_ALT3   0x7
#define GPIO_FSEL_ALT4   0x3
#define GPIO_FSEL_ALT5   0x2

#define I2C_PIN_SDA 2
#define I2C_PIN_SCL 3

#define I2C_BASE 0x804000

#define SPI_PIN_CE0  8
#define SPI_PIN_CE1  7
#define SPI_PIN_SCLK 11
#define SPI_PIN_MOSI 10
#define SPI_PIN_MISO 9

#define SPI_BASE        0x204000
#define SPI_CS          0x00
#define SPI_CS_CLEAR    0x00000030
#define SPI_CS_CLEAR_RX 0x00000020
#define SPI_CS_CLEAR_TX 0x00000010

#endif
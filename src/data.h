#ifndef __DATA_H__
#define __DATA_H__

#define PERI_BASE 0xFE000000
#define PERI_SIZE 0x01800000

#define CORE_CLOCK_HZ 1500000000

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

#define I2C_BASE      0x804000
#define I2C_C         0x00
#define I2C_C_I2CEN   0x8000
#define I2C_C_INTR    0x0400
#define I2C_C_INTT    0x0200
#define I2C_C_INTD    0x0100
#define I2C_C_ST      0x0080
#define I2C_C_CLEAR   0x0030
#define I2C_C_CLEAR_2 0x0020
#define I2C_C_CLEAR_1 0x0010
#define I2C_C_READ    0x0001
#define I2C_S         0x04
#define I2C_S_CLKT    0x200
#define I2C_S_ERR     0x100
#define I2C_S_RXF     0x080
#define I2C_S_TXE     0x040
#define I2C_S_RXD     0x020
#define I2C_S_TXD     0x010
#define I2C_S_RXR     0x008
#define I2C_S_TXW     0x004
#define I2C_S_DONE    0x002
#define I2C_S_TA      0x001
#define I2C_DLEN      0x08
#define I2C_A         0x0C
#define I2C_FIFO      0x10
#define I2C_DIV       0x14

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
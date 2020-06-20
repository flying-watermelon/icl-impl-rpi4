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
#define SPI_CS_LEN_LONG 0x02000000
#define SPI_CS_DMA_LEN  0x01000000
#define SPI_CS_CSPOL2   0x00800000
#define SPI_CS_CSPOL1   0x00400000
#define SPI_CS_CSPOL0   0x00200000
#define SPI_CS_RXF      0x00100000
#define SPI_CS_RXR      0x00080000
#define SPI_CS_TXD      0x00040000
#define SPI_CS_RXD      0x00020000
#define SPI_CS_DONE     0x00010000
#define SPI_CS_TE_EN    0x00008000
#define SPI_CS_LMONO    0x00004000
#define SPI_CS_LEN      0x00002000
#define SPI_CS_REN      0x00001000
#define SPI_CS_ADCS     0x00000800
#define SPI_CS_INTR     0x00000400
#define SPI_CS_INTD     0x00000200
#define SPI_CS_DMAEN    0x00000100
#define SPI_CS_TA       0x00000080
#define SPI_CS_CSPOL    0x00000040
#define SPI_CS_CLEAR    0x00000030
#define SPI_CS_CLEAR_RX 0x00000020
#define SPI_CS_CLEAR_TX 0x00000010
#define SPI_CS_CPOL     0x00000008
#define SPI_CS_CPHA     0x00000004
#define SPI_CS_CS       0x00000003
#define SPI_CS_CS_NONE  0x00000003
#define SPI_CS_CS_CHIP2 0x00000002
#define SPI_CS_CS_CHIP1 0x00000001
#define SPI_CS_CS_CHIP0 0x00000000
#define SPI_FIFO        0x04
#define SPI_CLK         0x08
#define SPI_DLEN        0x0C
#define SPI_LTOH        0x10
#define SPI_DC          0x14

#endif
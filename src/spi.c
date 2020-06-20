#include "ICL/ICL.h"
#include "context.h"
#include "data.h"
#include "utilities.h"

int icl_spi_setSpeed(int hz) {
    unsigned divider = CORE_CLOCK_HZ / hz;
    if (divider > 0xFFFF) {
        divider = 0;
    }
    if (divider < 0x0002) {
        divider = 0x0002;
    }
    writeRegister(spiBase + SPI_CLK, divider);
}

int icl_spi_transferBytes(int chip, size_t count, uint8_t *send, uint8_t *received) {
    volatile unsigned char *cs = spiBase + SPI_CS;
    volatile unsigned char *fifo = spiBase + SPI_FIFO;

    size_t sentBytes = 0;
    size_t receivedBytes = 0;

    writeRegisterMasked(cs, SPI_CS_CLEAR, SPI_CS_CLEAR);
    writeRegisterMasked(cs, SPI_CS_TA, SPI_CS_TA);

    while ((sentBytes < count) || (receivedBytes < count)) {
        while (readRegisterMasked(cs, SPI_CS_TXD) && (sentBytes < count)) {
            writeRegister(fifo, send[sentBytes]);
            sentBytes++;
        }

        while (readRegisterMasked(cs, SPI_CS_RXD) && (receivedBytes < count)) {
            received[receivedBytes] = readRegister(fifo);
            receivedBytes++;
        }
    }

    while (!readRegisterMasked(cs, SPI_CS_DONE))
        ;

    writeRegisterMasked(cs, 0, SPI_CS_TA);

    return 0;
}

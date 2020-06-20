#include <ICL/ICL.h>
#include <ICL/ICL_impl_rpi4.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    icl_rpi4_initialize(ICL_RPI4_INITIALIZE_SPI);

    icl_spi_setSpeed(50000);

    char buf[24] = "hello world, hello spi.";
    icl_spi_transferBytes(0, 23, (uint8_t *)buf, (uint8_t *)buf);

    icl_rpi4_finalize();

    return 0;
}

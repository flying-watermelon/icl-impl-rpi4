#include <ICL/ICL.h>
#include <ICL/ICL_impl_rpi4.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    icl_rpi4_initialize(ICL_RPI4_INITIALIZE_SPI);

    icl_rpi4_finalize();

    return 0;
}

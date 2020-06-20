#include <ICL/ICL.h>
#include <ICL/ICL_impl_rpi4.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (icl_rpi4_initialize(ICL_RPI4_INITIALIZE_SPI) != 0) {
        fprintf(stderr, "Cannot initialize ICL");
        exit(EXIT_FAILURE);
    }

    icl_rpi4_finalize();

    return 0;
}

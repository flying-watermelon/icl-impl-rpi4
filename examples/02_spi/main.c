#include <ICL\ICL.h>
#include <ICL\ICL_impl_rpi4.h>

int main() {
    icl_rpi4_initialize(ICL_RPI4_INITIALIZE_SPI);

    icl_rpi4_finalize();

    return 0;
}

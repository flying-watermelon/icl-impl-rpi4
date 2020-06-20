#include <ICL/ICL.h>
#include <ICL/ICL_impl_rpi4.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%s\n", icl_info_getVersion());
    printf("%s\n", icl_info_getImplementation());

    return 0;
}

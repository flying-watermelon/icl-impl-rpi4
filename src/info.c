#include <ICL/ICL.h>

const char *icl_version = "1.0";
const char *icl_implementation = "rpi4:1.0";

const char *icl_info_getVersion() {
    return icl_version;
}

const char *icl_info_getImplementation() {
    return icl_implementation;
}

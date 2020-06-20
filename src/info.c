#include <ICL/ICL.h>

const char *iclVersion = "1.0";
const char *iclImplementation = "rpi4:1.0";

const char *icl_info_getVersion() {
    return iclVersion;
}

const char *icl_info_getImplementation() {
    return iclImplementation;
}

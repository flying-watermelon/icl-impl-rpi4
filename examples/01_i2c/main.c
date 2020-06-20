#include <ICL/ICL.h>
#include <ICL/ICL_impl_rpi4.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _read();
void _write();
void _printUsageAndExit();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printUsageAndExit();
    }

    char *action = argv[1];

    if (strcmp(action, "write") == 0) {
        write();
    } else if (strcmp(action, "read") == 0) {
        read();
    } else {
        printUsageAndExit();
    }

    return 0;
}

void _read() {
    icl_rpi4_initialize(ICL_RPI4_INITIALIZE_I2C);

    icl_i2c_setBaudRate(10000000);
    char buf[24];
    icl_i2c_readBytes(0x04, 23, buf);
    printf("%s\n", buf);

    icl_rpi4_finalize();
}

void _write() {
    icl_rpi4_initialize(ICL_RPI4_INITIALIZE_I2C);

    icl_i2c_setBaudRate(10000000);
    char buf[24] = "hello world, hello i2c.";
    icl_i2c_writeBytes(0x04, 23, buf);

    icl_rpi4_finalize();
}

void _printUsageAndExit() {
    printf("Usage: sudo ./main {read|write}\n");
    exit(EXIT_FAILURE);
}

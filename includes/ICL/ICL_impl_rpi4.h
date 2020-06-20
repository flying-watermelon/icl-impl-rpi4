#ifndef __ICL_IMPL_RPI4_H__
#define __ICL_IMPL_RPI4_H__

#define ICL_RPI4_INITIALIZATION_ERROR 1

#define ICL_RPI4_INITIALIZE_I2C 0x1
#define ICL_RPI4_INITIALIZE_SPI 0x2

#ifdef __cplusplus
extern "C" {
#endif

int icl_rpi4_initialize();

int icl_rpi4_finalize();

#ifdef __cplusplus
} // extern "C"
#endif

#endif

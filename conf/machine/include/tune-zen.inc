# Settings for the GCC(1) cpu-type "znver2":
#
#     Zen 1
#     AMD Family 17h core based CPUs with x86-64 instruction set support.
#
#     Supported instructions:
#
#       BMI, BMI2, F16C, FMA, FSGSBASE, AVX, AVX2, ADCX, RDSEED, MWAITX, SHA, 
#       CLZERO, AES, PCLMUL, CX16, MOVBE, MMX, SSE, SSE2, SSE3, SSE4A, SSSE3, 
#       SSE4.1, SSE4.2, ABM, XSAVEC, XSAVES, CLFLUSHOPT, POPCNT
#

DEFAULTTUNE ?= "zen-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/tune-corei7.inc

# Extra tune features
TUNEVALID[zen] = "Enable zen specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'zen', ' -march=znver1 -mfpmath=sse', '', d)}"

# Extra tune selections
AVAILTUNES += "zen-32"
TUNE_FEATURES_tune-zen-32 = "${TUNE_FEATURES_tune-x86} zen"
BASE_LIB_tune-zen-32 = "lib"
TUNE_PKGARCH_tune-zen-32 = "zen-32"
PACKAGE_EXTRA_ARCHS_tune-zen-32 = "${PACKAGE_EXTRA_ARCHS_tune-core2-32} zen-32"
#QEMU_EXTRAOPTIONS_zen-32 = " -cpu ,check=false"

AVAILTUNES += "zen-64"
TUNE_FEATURES_tune-zen-64 = "${TUNE_FEATURES_tune-x86-64} zen"
BASE_LIB_tune-zen-64 = "lib64"
TUNE_PKGARCH_tune-zen-64 = "zen-64"
PACKAGE_EXTRA_ARCHS_tune-zen-64 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64} zen-64"
#QEMU_EXTRAOPTIONS_zen-64 = " -cpu ,check=false"

AVAILTUNES += "zen-64-x32"
TUNE_FEATURES_tune-zen-64-x32 = "${TUNE_FEATURES_tune-x86-64-x32} zen"
BASE_LIB_tune-zen-64-x32 = "libx32"
TUNE_PKGARCH_tune-zen-64-x32 = "zen-64-x32"
PACKAGE_EXTRA_ARCHS_tune-zen-64-x32 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64-x32} zen-64-x32"
#QEMU_EXTRAOPTIONS_zen-64-x32 = " -cpu ,check=false"

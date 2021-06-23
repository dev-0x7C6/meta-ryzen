# Settings for the GCC(1) cpu-type "znver2":
#
#     Zen 2
#     AMD Family 17h core based CPUs with x86-64 instruction set support.
#
#     Supported instructions:
#
#       BMI, BMI2, CLWB, F16C, FMA, FSGSBASE, AVX, AVX2, ADCX, RDSEED, MWAITX, 
#       SHA, CLZERO, AES, PCLMUL, CX16, MOVBE, MMX, SSE, SSE2, SSE3, SSE4A, SSSE3, 
#       SSE4.1, SSE4.2, ABM, XSAVEC, XSAVES, CLFLUSHOPT, POPCNT, RDPID, WBNOINVD
#
#
DEFAULTTUNE ?= "zen2-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/tune-corei7.inc

# Extra tune features
TUNEVALID[zen2] = "Enable zen2 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'zen2', ' -march=znver2 -mfpmath=sse -msse4.2', '', d)}"

# Extra tune selections
AVAILTUNES += "zen2-32"
TUNE_FEATURES_tune-zen2-32 = "${TUNE_FEATURES_tune-x86} zen2"
BASE_LIB_tune-zen2-32 = "lib"
TUNE_PKGARCH_tune-zen2-32 = "zen2-32"
PACKAGE_EXTRA_ARCHS_tune-zen2-32 = "${PACKAGE_EXTRA_ARCHS_tune-core2-32} zen2-32"
QEMU_EXTRAOPTIONS_zen2-32 = " -cpu Haswell,check=false"

AVAILTUNES += "zen2-64"
TUNE_FEATURES_tune-zen2-64 = "${TUNE_FEATURES_tune-x86-64} zen2"
BASE_LIB_tune-zen2-64 = "lib64"
TUNE_PKGARCH_tune-zen2-64 = "zen2-64"
PACKAGE_EXTRA_ARCHS_tune-zen2-64 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64} zen2-64"
QEMU_EXTRAOPTIONS_zen2-64 = " -cpu Haswell,check=false"

AVAILTUNES += "zen2-64-x32"
TUNE_FEATURES_tune-zen2-64-x32 = "${TUNE_FEATURES_tune-x86-64-x32} zen2"
BASE_LIB_tune-zen2-64-x32 = "libx32"
TUNE_PKGARCH_tune-zen2-64-x32 = "zen2-64-x32"
PACKAGE_EXTRA_ARCHS_tune-zen2-64-x32 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64-x32} zen2-64-x32"
QEMU_EXTRAOPTIONS_zen2-64-x32 = " -cpu Haswell,check=false"

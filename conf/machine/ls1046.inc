#@TYPE: Machine inc.
#@NAME: nxp-ls1046 layer

DEFAULTTUNE = "cortexa72"
require conf/machine/include/arm/armv8a/tune-cortexa72.inc

MACHINE_FEATURES += "usbhost jffs2 ext2 alsa vfat"

KERNEL_IMAGETYPE = "Image"
KERNEL_DEVICETREE = "freescale/fsl-ls1046a-rdb-sdk.dtb freescale/fsl-ls1046a-rdb-usdpaa.dtb"

SERIAL_CONSOLE = "115200 ttyS0"

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"
WKS_FILE = "nxp-ls1046-sdimage.wks"
IMAGE_INSTALL:append = " kernel-devicetree kernel-image-image"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= " Image fsl-ls1046a-rdb-sdk.dtb fsl-ls1046a-rdb-usdpaa.dtb"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE:virtclass-multilib-lib32 ?= "armv7athf-neon"

# it's used by many recipes in meta-freescale
MACHINE_SOCARCH = "${TUNE_PKGARCH}"

# pull in the meta-freescale layer.
BSP_NXP_DERIVED:append:nxp-ls1046  = " nxp-ls1046"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "5.15%"
PREFERRED_VERSION_dpdk = "21.11"

NON_MULTILIB_RECIPES:append = " rcw"


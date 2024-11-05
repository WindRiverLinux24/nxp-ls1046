COMPATIBLE_MACHINE:nxp-ls1046 = "nxp-ls1046"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"
SRC_URI:nxp-ls1046 = "git://github.com/nxp-qoriq/dpdk;protocol=https;nobranch=1"
SRC_URI:append:nxp-ls1046 = " \
            file://0001-meson.build-march-and-mcpu-already-passed-by-Yocto.patch \
"

MESON_BUILDTYPE:nxp-ls1046 = "release"

PACKAGECONFIG:append:nxp-ls1046 ??= "openssl"
PACKAGECONFIG[openssl] = ",,openssl"

DPDK_EXAMPLES:nxp-ls1046 = "all"
EXTRA_OEMESON:append:nxp-ls1046 = " \
		-Doptimization=3 \
		--cross-file ${S}/config/arm/arm64_poky_linux_gcc \
		-Denable_driver_sdk=true \
		${@bb.utils.contains('DISTRO_FEATURES', 'vpp', '-Dc_args="-Ofast -fPIC -ftls-model=local-dynamic"', '', d)} \
"

RDEPENDS:${PN}:append:nxp-ls1046 = " bash python3-pyelftools"
RDEPENDS:${PN}:remove:nxp-ls1046 = "kernel-module-dpdk-extras"
DEPENDS:nxp-ls1046 = "python3-pyelftools-native"

inherit pkgconfig

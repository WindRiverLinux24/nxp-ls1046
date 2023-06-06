COMPATIBLE_MACHINE:nxp-ls1046 = "nxp-ls1046"

SRC_URI:nxp-ls1046 = "git://github.com/nxp-qoriq/dpdk;protocol=https;nobranch=1"
SRC_URI:append:nxp-ls1046 = " \
            file://0001-Makefile-add-makefile.patch \
"
SRCREV:nxp-ls1046 = "eb28c02bc1221e788688f0de9ff5b2bb1a062006"

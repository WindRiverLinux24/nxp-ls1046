FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append:nxp-ls1046 = "\
    file://enable_pcie.cfg \
"

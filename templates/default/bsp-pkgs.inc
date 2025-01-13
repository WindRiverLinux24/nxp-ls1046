IMAGE_INSTALL += "\
	linuxptp \
	fmc \
"

IMAGE_INSTALL += "\
	${@bb.utils.contains('CUSTOMER_BUILD_BOOTLOADER', '1', \
						'optee-os-qoriq \
						 optee-test-qoriq \
						 optee-client-qoriq \
						 optee-os-qoriq-tadevkit', '', d)} \
"

require conf/make_nxp_ls1046_wic.inc

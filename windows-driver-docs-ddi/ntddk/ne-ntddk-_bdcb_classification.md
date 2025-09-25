# _BDCB_CLASSIFICATION enumeration

## Description

The BDCB_CLASSIFICATION enumeration lists different classifications of boot start images.

## Constants

### `BdCbClassificationUnknownImage`

The boot start image has not been inspected by anti-malware or anti-malware does not have enough information to determine whether the binary is malware.

### `BdCbClassificationKnownGoodImage`

The boot start image has been inspected by anti-malware and found not to be malware.

### `BdCbClassificationKnownBadImage`

The boot start image has been inspected by anti-malware and found to be malware.

### `BdCbClassificationKnownBadImageBootCritical`

The boot start image has been inspected by anti-malware and found to be malware, but the anti-malware boot-start driver also knows it to be critical to the success of the boot.

### `BdCbClassificationEnd`

Do not use. Reserved for future use.

## See also

[BDCB_IMAGE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_bdcb_image_information)

[BOOT_DRIVER_CALLBACK_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback)
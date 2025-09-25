# _TEXTUAL_LEAF structure

## Description

The TEXTUAL_LEAF structure describes the device description that can be stored in the Configuration ROM of devices that satisfy the PC 98 or PC 99 specifications.

## Members

### `TL_CRC`

Specifies the CRC of the text string.

### `TL_Length`

Specifies the length of the text string, in bytes.

### `TL_Spec_Id`

Specifies which specification describes the meaning of the **TL_Language_ID** member.

### `TL_Language_Id`

Specifies the language of the **TL_Data** member.

### `TL_Data`

Specifies a vendor-specified textual description of the device.

## See also

[REQUEST_GET_CONFIGURATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)
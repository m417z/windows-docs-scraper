# DISPLAYCONFIG_SET_TARGET_PERSISTENCE structure

## Description

The DISPLAYCONFIG_SET_TARGET_PERSISTENCE structure contains information about setting the display.

## Members

### `header`

A [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that contains information for setting the target persistence. The **type** member of DISPLAYCONFIG_DEVICE_INFO_HEADER is set to DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE. DISPLAYCONFIG_DEVICE_INFO_HEADER also contains the adapter and target identifiers of the target to set the persistence for. The **size** member of DISPLAYCONFIG_DEVICE_INFO_HEADER is set to at least the size of the DISPLAYCONFIG_SET_TARGET_PERSISTENCE structure.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.bootPersistenceOn`

A UINT32 value that specifies whether the [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig) function should enable or disable boot persistence for the specified target.

Setting this member is equivalent to setting the first bit of the 32-bit **value** member (0x00000001).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **value** member to zeros.

### `DUMMYUNIONNAME.value`

A member in the union that DISPLAYCONFIG_SET_TARGET_PERSISTENCE contains that can hold a 32-bit value that identifies information about setting the display.

## See also

[DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header)

[SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig)
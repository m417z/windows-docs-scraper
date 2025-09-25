# DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS structure

## Description

The **DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS** structure contains information about a target device.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.friendlyNameFromEdid`

A UINT32 value that indicates that the string in the **monitorFriendlyDeviceName** member of the [DISPLAYCONFIG_TARGET_DEVICE_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name) structure was constructed from the manufacture identification string in the extended display identification data (EDID).

Setting this member is equivalent to setting the first bit of the 32-bit **value** member (0x00000001).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.friendlyNameForced`

A UINT32 value that indicates that the target is forced with no detectable monitor attached and the **monitorFriendlyDeviceName** member of the [DISPLAYCONFIG_TARGET_DEVICE_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name) structure is a NULL-terminated empty string.

Setting this member is equivalent to setting the second bit of the 32-bit **value** member (0x00000002).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.edidIdsValid`

A UINT32 value that indicates that the **edidManufactureId** and **edidProductCodeId** members of the [DISPLAYCONFIG_TARGET_DEVICE_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name) structure are valid and were obtained from the EDID.

Setting this member is equivalent to setting the third bit of the 32-bit **value** member (0x00000004).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 29 bits (0xFFFFFFF8) of the 32-bit **value** member to zeros.

### `DUMMYUNIONNAME.value`

A member in the union that DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS contains that can hold a 32-bit value that identifies information about the device.

## See also

[DISPLAYCONFIG_TARGET_DEVICE_NAME](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name)
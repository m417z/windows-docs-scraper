# DISPLAYCONFIG_TARGET_DEVICE_NAME structure

## Description

The DISPLAYCONFIG_TARGET_DEVICE_NAME structure contains information about the target.

## Members

### `header`

A [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that contains information about the request for the target device name. The caller should set the **type** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME and the **adapterId** and **id** members of DISPLAYCONFIG_DEVICE_INFO_HEADER to the target for which the caller wants the target device name. The caller should set the **size** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to at least the size of the DISPLAYCONFIG_TARGET_DEVICE_NAME structure.

### `flags`

A [DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name_flags) structure that identifies, in bit-field flags, information about the target.

### `outputTechnology`

A value from the [DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_video_output_technology) enumeration that specifies the target's connector type.

### `edidManufactureId`

 The manufacture identifier from the monitor extended display identification data (EDID). This member is set only when the **edidIdsValid** bit-field is set in the **flags** member.

### `edidProductCodeId`

 The product code from the monitor EDID. This member is set only when the **edidIdsValid** bit-field is set in the **flags** member.

### `connectorInstance`

The one-based instance number of this particular target only when the adapter has multiple targets of this type. The connector instance is a consecutive one-based number that is unique within each adapter. If this is the only target of this type on the adapter, this value is zero.

### `monitorFriendlyDeviceName`

A NULL-terminated WCHAR string that is the device name for the monitor. This name can be used with *SetupAPI.dll* to obtain the device name that is contained in the installation package.

### `monitorDevicePath`

A NULL-terminated WCHAR string that is the path to the device name for the monitor. This path can be used with *SetupAPI.dll* to obtain the device name that is contained in the installation package.

## Remarks

Extended display identification data (EDID) is a set of data that is provided by a display to describe its capabilities to a graphics adapter. EDID data allows a computer to detect the type of monitor that is connected to it. EDID data includes the manufacturer name, the product type, the timings that are supported by the display, the display size, as well as other display characteristics. EDID is defined by a standard published by the Video Electronics Standards Association (VESA).

A named device object has a path and name of the form *\Device\DeviceName*. This is known as the *device name* of the device object.

If an application calls the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function to obtain the monitor name and **DisplayConfigGetDeviceInfo** either cannot get the monitor name or the target is forced without a monitor connected, the string in the **monitorFriendlyDeviceName** member of the DISPLAYCONFIG_TARGET_DEVICE_NAME structure is a **NULL** string and none of the bit-field flags in the [DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name_flags) structure are set.

## See also

[DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header)

[DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_device_name_flags)

[DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_video_output_technology)

[DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo)
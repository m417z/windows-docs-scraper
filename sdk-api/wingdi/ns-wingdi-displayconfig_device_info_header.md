# DISPLAYCONFIG_DEVICE_INFO_HEADER structure

## Description

The DISPLAYCONFIG_DEVICE_INFO_HEADER structure contains display information about the device.

## Members

### `type`

A [DISPLAYCONFIG_DEVICE_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_device_info_type) enumerated value that determines the type of device information to retrieve or set. The remainder of the packet for the retrieve or set operation follows immediately after the DISPLAYCONFIG_DEVICE_INFO_HEADER structure.

### `size`

The size, in bytes, of the device information that is retrieved or set. This size includes the size of the header and the size of the additional data that follows the header. This device information depends on the request type.

### `adapterId`

A locally unique identifier (LUID) that identifies the adapter that the device information packet refers to.

### `id`

The source or target identifier to get or set the device information for. The meaning of this identifier is related to the type of information being requested. For example, in the case of DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME, this is the source identifier.

## Remarks

The [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function uses the DISPLAYCONFIG_DEVICE_INFO_HEADER structure for retrieving display configuration information about the device, and the [DisplayConfigSetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfigsetdeviceinfo) function uses the DISPLAYCONFIG_DEVICE_INFO_HEADER structure for setting display configuration information for the device.

## See also

[DISPLAYCONFIG_DEVICE_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_device_info_type)

[DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo)

[DisplayConfigSetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfigsetdeviceinfo)
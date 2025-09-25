# DISPLAYCONFIG_TARGET_BASE_TYPE structure

## Description

Specifies base output technology info for a given target ID.

## Members

### `header`

A [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that contains info about the request for the target device name. The caller should set the **type** member of **DISPLAYCONFIG_DEVICE_INFO_HEADER** to **DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_BASE_TYPE** and the **adapterId** and **id** members of **DISPLAYCONFIG_DEVICE_INFO_HEADER** to the target for which the caller wants the target device name.

 The caller should set the **size** member of [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) to at least the size of the **DISPLAYCONFIG_TARGET_BASE_TYPE** structure.

### `baseOutputTechnology`

The base output technology, given as a constant value of the [DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_video_output_technology) enumeration, of the adapter and the target specified by the **header** member. See Remarks.

## Remarks

For a Miracast display device, a call to the [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) function always returns a value of [DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_video_output_technology).**DISPLAYCONFIG_OUTPUT_TECHNOLOGY_MIRACAST**, regardless of what the Miracast sink reports as the connector type.

## See also

[DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header)

[DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_video_output_technology)

[DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo)
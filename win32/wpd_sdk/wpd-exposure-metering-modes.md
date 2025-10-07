# WPD\_EXPOSURE\_METERING\_MODES enumeration

The **WPD\_EXPOSURE\_METERING\_MODES** enumeration type describes the metering mode to use when estimating exposure for still image capture by a device.

## Constants

**WPD\_EXPOSURE\_METERING\_MODE\_UNDEFINED**

The metering mode is undefined.

**WPD\_EXPOSURE\_METERING\_MODE\_AVERAGE**

Use averaged exposure across the full image.

**WPD\_EXPOSURE\_METERING\_MODE\_CENTER\_WEIGHTED\_AVERAGE**

Use an averaged exposure, with the center of the image given more weight.

**WPD\_EXPOSURE\_METERING\_MODE\_MULTI\_SPOT**

Use a multi-spot averaging technique.

**WPD\_EXPOSURE\_METERING\_MODE\_CENTER\_SPOT**

Use a center-spot averaging technique.

## Remarks

Indicates the metering mode of the device. This enumeration is used by the [WPD\_STILL\_IMAGE\_EXPOSURE\_METERING\_MODE](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) property.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)


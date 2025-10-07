# WPD\_EXPOSURE\_PROGRAM\_MODES enumeration

The **WPD\_EXPOSURE\_PROGRAM\_MODES** enumeration type describes an exposure mode to use when capturing images with a device.

## Constants

**WPD\_EXPOSURE\_PROGRAM\_MODE\_UNDEFINED**

The exposure mode has not been specified.

**WPD\_EXPOSURE\_PROGRAM\_MODE\_MANUAL**

The application should specify all exposure settings.

**WPD\_EXPOSURE\_PROGRAM\_MODE\_AUTO**

Use a device-defined automatic exposure mode.

**WPD\_EXPOSURE\_PROGRAM\_MODE\_APERTURE\_PRIORITY**

An automated exposure mode that indicates that the lens aperture value should remain fixed, but shutter speed should be determined by the device.

**WPD\_EXPOSURE\_PROGRAM\_MODE\_SHUTTER\_PRIORITY**

An automated exposure mode that indicates that the shutter speed should remain fixed, but that lens aperture should be determined by the device.

**WPD\_EXPOSURE\_PROGRAM\_MODE\_CREATIVE**

An automated exposure mode that tries to maximize the depth of field.

**WPD\_EXPOSURE\_PROGRAM\_MODE\_ACTION**

An automated exposure mode that tries to maximize the shutter speed.

**WPD\_EXPOSURE\_PROGRAM\_MODE\_PORTRAIT**

An automated exposure mode that specifies a relatively shallow depth of field.

## Remarks

Indicates the exposure program mode of the device. This enumeration is used by the [WPD\_STILL\_IMAGE\_EXPOSURE\_PROGRAM\_MODE](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) property.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)


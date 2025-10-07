# WPD\_WHITE\_BALANCE\_SETTINGS enumeration

The **WPD\_WHITE\_BALANCE\_SETTINGS** enumeration type describes how a video or image device weights color channels to achieve a proper white balance.

## Constants

**WPD\_WHITE\_BALANCE\_UNDEFINED**

This value has not been defined.

**WPD\_WHITE\_BALANCE\_MANUAL**

The white balance is set explicitly by using the [WPD\_STILL\_IMAGE\_RGB\_GAIN](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) property and will not change by itself.

**WPD\_WHITE\_BALANCE\_AUTOMATIC**

The device will set the white balance.

**WPD\_WHITE\_BALANCE\_ONE\_PUSH\_AUTOMATIC**

The device will set the white balance, but only when the user pushes the device's capture button while aiming the device at a white field.

**WPD\_WHITE\_BALANCE\_DAYLIGHT**

The device will use white balance numbers appropriate for use in most daylight settings.

**WPD\_WHITE\_BALANCE\_TUNGSTEN**

The device will use white balance numbers appropriate for use in most indoor, incandescent lighting settings.

**WPD\_WHITE\_BALANCE\_FLASH**

The device will use white balance numbers appropriate for use with a flash.

## Remarks

This enumeration is used by the [WPD\_STILL\_IMAGE\_WHITE\_BALANCE](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) property.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)


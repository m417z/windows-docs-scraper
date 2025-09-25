# tagWPD_WHITE_BALANCE_SETTINGS enumeration

## Description

The **WPD_WHITE_BALANCE_SETTINGS** enumeration type describes how a video or image device weights color channels to achieve a proper white balance.

## Constants

### `WPD_WHITE_BALANCE_UNDEFINED`

This value has not been defined.

### `WPD_WHITE_BALANCE_MANUAL`

The white balance is set explicitly by using the [WPD_STILL_IMAGE_RGB_GAIN](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) property and will not change by itself.

### `WPD_WHITE_BALANCE_AUTOMATIC`

The device will set the white balance.

### `WPD_WHITE_BALANCE_ONE_PUSH_AUTOMATIC`

The device will set the white balance, but only when the user pushes the device's capture button while aiming the device at a white field.

### `WPD_WHITE_BALANCE_DAYLIGHT`

The device will use white balance numbers appropriate for use in most daylight settings.

### `WPD_WHITE_BALANCE_FLORESCENT`

### `WPD_WHITE_BALANCE_TUNGSTEN`

The device will use white balance numbers appropriate for use in most indoor, incandescent lighting settings.

### `WPD_WHITE_BALANCE_FLASH`

The device will use white balance numbers appropriate for use with a flash.

## Remarks

This enumeration is used by the [WPD_STILL_IMAGE_WHITE_BALANCE](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) property.

## See also

[Structures and Enumeration Types](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597672(v=vs.85))
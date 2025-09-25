# GetScaleFactorForDevice function

## Description

Gets the preferred scale factor for a display device.

**Note** This function is not supported as of Windows 8.1. Use [GetScaleFactorForMonitor](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getscalefactorformonitor) instead.

## Parameters

### `deviceType` [in]

Type: **[DISPLAY_DEVICE_TYPE](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-display_device_type)**

The value that indicates the type of the display device.

## Return value

Type: **[DEVICE_SCALE_FACTOR](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-device_scale_factor)**

A value that indicates the scale factor that should be used with the specified [DISPLAY_DEVICE_TYPE](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-display_device_type).

| Return code/value | Description |
| --- | --- |
| **SCALE_100_PERCENT**<br><br>100 | Use a scale factor of 1x. |
| **SCALE_140_PERCENT**<br><br>140 | Use a scale factor of 1.4x. |
| **SCALE_180_PERCENT**<br><br>180 | Use a scale factor of 1.8x. |

## Remarks

The default [DEVICE_SCALE_FACTOR](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-device_scale_factor) is [SCALE_100_PERCENT](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-device_scale_factor).

Use the scale factor that is returned to scale point values for fonts and pixel values.

## See also

[GetScaleFactorForMonitor](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getscalefactorformonitor)

[RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent)

[UnregisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-unregisterscalechangeevent)
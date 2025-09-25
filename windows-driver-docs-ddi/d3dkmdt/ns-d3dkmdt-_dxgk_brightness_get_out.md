# _DXGK_BRIGHTNESS_GET_OUT structure

## Description

Contains the output parameters for the [DxgkBrightnessGet3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_3) callback function.

## Members

### `CurrentBrightnessMillinits`

The current brightness level in millinits of the display.

### `TargetBrightnessMillinits`

The brightness level in millinits that the display is currently transitioning to. If not in a transition, this should equal the current brightness.
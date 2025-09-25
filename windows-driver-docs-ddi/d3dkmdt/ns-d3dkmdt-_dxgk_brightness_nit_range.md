# _DXGK_BRIGHTNESS_NIT_RANGE structure

## Description

This structure represents a linear range of supported millinit levels. If the driver has not set [DXGK_BRIGHTNESS_CAPS.NitsBrightness](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps), then all values represent brightness level in uncalibrated thousandths of a percent.

## Members

### `MinimumLevelMillinit`

Lowest level in this range. Calibrated data provided to the Display Driver by OEMs should be taken with an On Pixel Ratio (OPR) percentage of 100% where each pixel is set to an RGB value of (255, 255, 255) or floating point equivalent.

### `MaximumLevelMillinit`

Highest level in this range. Can be equal to MinimumLevelMillinit to represent a range with just one level. For example, this could support a display with just one boost level. Calibrated data provided to the Display Driver by OEMs should be taken with an On Pixel Ratio (OPR) percentage of 100% where each pixel is set to an RGB value of (255, 255, 255) or floating point equivalent.

### `StepSizeMillinit`

The size of steps between valid brightness levels in the range. Minimum + StepSize * n is considered a valid level for non-negative n, where the level is equal to or below maximum. (Maximum – Minimum) % StepSize should always be zero. If MinimumLevelMillinit == MaximumLevelMillinit, then this should be zero.
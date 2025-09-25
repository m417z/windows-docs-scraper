# BRIGHTNESS_NIT_RANGE structure

## Description

A **BRIGHTNESS_NIT_RANGE** structure contains a linear range of supported millinit levels.

## Members

### `MinLevelInMillinit`

Lowest level in this range. Calibrated data provided to the display driver by OEMs should be taken with an On Pixel Ratio (OPR) percentage of 100% where each pixel is set to an RGB value of (255, 255, 255) or floating point equivalent.

### `MaxLevelInMillinit`

Highest level in this range. Can be equal to **MinimumLevelInMillinit** to represent a range with just one level. For example, this could support a display with just one boost level. Calibrated data provided to the display driver by OEMs should be taken with an On Pixel Ratio (OPR) percentage of 100% where each pixel is set to an RGB value of (255, 255, 255) or floating point equivalent.

### `StepSizeInMillinit`

The size of steps between valid brightness levels in the range. Minimum + StepSize * n is considered a valid level for non-negative n, where the level is equal to or below maximum. (Maximum – Minimum) % StepSize should always be zero. If **MinLevelInMillinit** == **MaxLevelInMillinit**, then this should be zero.

## See also

[**IOCTL_PANEL_QUERY_BRIGHTNESS_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_panel_query_brightness_ranges)

[**PANEL_QUERY_BRIGHTNESS_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_panel_query_brightness_ranges)
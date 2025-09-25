# _DXGK_BRIGHTNESS_GET_NIT_RANGES_OUT structure

## Description

Contains the output parameters for the [DxgkBrightnessGetNitRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgk_brightness_get_nit_ranges) callback function.

## Members

### `NormalRangeCount`

The number of ranges that are not boost level ranges.

### `RangeCount`

The number of supported ranges, including boost level ranges.

### `PreferredMaximumBrightness`

An OEM-preferred level to correspond with 100% brightness. If there is no OEM preference, the value should be zero.

### `SupportedRanges`

A list of supported ranges. Ranges should be in strictly increasing order by brightness, with normal ranges coming before boost ranges.
# DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAGS enumeration

## Description

Identifies YUV range and conversion info that describes a multiplane overlay.

## Constants

### `DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE`

YUV values range from 16 to 235, inclusive, instead of the default range of 0 to 255, inclusive.

### `DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709`

YUV values should be converted using the BT.709 standard, instead of the default BT.601 conversion.

### `DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC`

YUV values contain xvYCC data, instead of conventional YCbCr data.

## Remarks

For more info on how YUV ranges are defined and converted, see [YUV format ranges in Windows 8.1](https://learn.microsoft.com/windows-hardware/drivers/display/yuv-format-ranges).
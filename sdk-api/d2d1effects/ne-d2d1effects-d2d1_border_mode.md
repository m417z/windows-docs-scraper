# D2D1_BORDER_MODE enumeration

## Description

Specifies how the [Crop effect](https://learn.microsoft.com/windows/desktop/Direct2D/crop) handles the crop rectangle falling on fractional pixel coordinates.

## Constants

### `D2D1_BORDER_MODE_SOFT:0`

 If the crop rectangle falls on fractional pixel coordinates, the effect applies antialiasing which results in a soft edge.

### `D2D1_BORDER_MODE_HARD:1`

If the crop rectangle falls on fractional pixel coordinates, the effect clamps which results in a hard edge.

### `D2D1_BORDER_MODE_FORCE_DWORD:0xffffffff`
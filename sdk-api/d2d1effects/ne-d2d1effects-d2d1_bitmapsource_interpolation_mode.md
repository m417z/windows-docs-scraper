# D2D1_BITMAPSOURCE_INTERPOLATION_MODE enumeration

## Description

The interpolation mode used to scale the image in the [Bitmap source effect](https://learn.microsoft.com/windows/desktop/Direct2D/bitmap-source).If the mode disables the mipmap, then BitmapSouce will cache the image at the resolution determined by the Scale and EnableDPICorrection properties.

## Constants

### `D2D1_BITMAPSOURCE_INTERPOLATION_MODE_NEAREST_NEIGHBOR:0`

Samples the nearest single point and uses that. Doesn't generate a mipmap.

### `D2D1_BITMAPSOURCE_INTERPOLATION_MODE_LINEAR:1`

Uses a four point sample and linear interpolation. Doesn't generate a mipmap.

### `D2D1_BITMAPSOURCE_INTERPOLATION_MODE_CUBIC:2`

Uses a 16 sample cubic kernel for interpolation. Doesn't generate a mipmap.

### `D2D1_BITMAPSOURCE_INTERPOLATION_MODE_FANT:6`

Uses the WIC fant interpolation, the same as the IWICBitmapScaler interface. Doesn't generate a mipmap.

### `D2D1_BITMAPSOURCE_INTERPOLATION_MODE_MIPMAP_LINEAR:7`

Generates mipmap chain in system memory using bilinear interpolation. For each mipmap the effect scales to the nearest multiple of 0.5 using bilinear interpolation
and then scales the remaining amount using linear interpolation.

### `D2D1_BITMAPSOURCE_INTERPOLATION_MODE_FORCE_DWORD:0xffffffff`
# D2D1_3DTRANSFORM_INTERPOLATION_MODE enumeration

## Description

The interpolation mode the [3D transform effect](https://learn.microsoft.com/windows/desktop/Direct2D/3d-transform) uses on the image. There are 5 scale modes that range in quality and speed.

## Constants

### `D2D1_3DTRANSFORM_INTERPOLATION_MODE_NEAREST_NEIGHBOR:0`

Samples the nearest single point and uses that. This mode uses less processing time, but outputs the lowest quality image.

### `D2D1_3DTRANSFORM_INTERPOLATION_MODE_LINEAR:1`

Uses a four point sample and linear interpolation. This mode uses more processing time than the nearest neighbor mode, but outputs a higher quality image.

### `D2D1_3DTRANSFORM_INTERPOLATION_MODE_CUBIC:2`

Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time, but outputs a higher quality image.

### `D2D1_3DTRANSFORM_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR:3`

Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is good for scaling down by small amounts on images with few pixels.

### `D2D1_3DTRANSFORM_INTERPOLATION_MODE_ANISOTROPIC:4`

Uses anisotropic filtering to sample a pattern according to the transformed shape of the bitmap.

### `D2D1_3DTRANSFORM_INTERPOLATION_MODE_FORCE_DWORD:0xffffffff`
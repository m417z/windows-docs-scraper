# D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE enumeration

## Description

The interpolation mode to be used with the 2D affine transform effect to scale the image. There are 6 scale modes that range in quality and speed.

## Constants

### `D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE_NEAREST_NEIGHBOR:0`

Samples the nearest single point and uses that. This mode uses less processing time, but outputs the lowest quality image.

### `D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE_LINEAR:1`

Uses a four point sample and linear interpolation. This mode uses more processing time than the nearest neighbor mode, but outputs a higher quality image.

### `D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE_CUBIC:2`

Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time, but outputs a higher quality image.

### `D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR:3`

Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is good for scaling down by small amounts on images with few pixels.

### `D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE_ANISOTROPIC:4`

Uses anisotropic filtering to sample a pattern according to the transformed shape of the bitmap.

### `D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE_HIGH_QUALITY_CUBIC:5`

Uses a variable size high quality cubic kernel to perform a pre-downscale the image if downscaling is involved in the transform matrix. Then uses the cubic interpolation mode for the final output.

### `D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE_FORCE_DWORD:0xffffffff`
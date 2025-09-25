# D2D1_GAUSSIANBLUR_PROP enumeration

## Description

Identifiers for properties of the [Gaussian blur effect](https://learn.microsoft.com/windows/desktop/Direct2D/gaussian-blur).

## Constants

### `D2D1_GAUSSIANBLUR_PROP_STANDARD_DEVIATION:0`

The amount of blur to be applied to the image. You can compute the blur radius of the kernel by multiplying the standard deviation by 3.
The units of both the standard deviation and blur radius are DIPs. A value of zero DIPs disables this effect entirely.

The type is FLOAT.

The default value is 3.0f.

### `D2D1_GAUSSIANBLUR_PROP_OPTIMIZATION:1`

The optimization mode.

The type is [D2D1_GAUSSIANBLUR_OPTIMIZATION](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_gaussianblur_optimization).

The default value is D2D1_GAUSSIANBLUR_OPTIMIZATION_BALANCED.

### `D2D1_GAUSSIANBLUR_PROP_BORDER_MODE:2`

The mode used to calculate the border of the image, soft or hard.

The type is [D2D1_GAUSSIANBLUR_OPTIMIZATION](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_gaussianblur_optimization).

The default value is D2D1_BORDER_MODE_SOFT.

### `D2D1_GAUSSIANBLUR_PROP_FORCE_DWORD:0xffffffff`
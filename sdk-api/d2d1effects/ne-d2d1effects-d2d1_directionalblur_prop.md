# D2D1_DIRECTIONALBLUR_PROP enumeration

## Description

Identifiers for properties of the [Directional blur effect](https://learn.microsoft.com/windows/desktop/Direct2D/directional-blur).

## Constants

### `D2D1_DIRECTIONALBLUR_PROP_STANDARD_DEVIATION:0`

The amount of blur to be applied to the image. You can compute the blur radius of the kernel by multiplying the standard deviation by 3.
The units of both the standard deviation and blur radius are DIPs. A value of 0 DIPs disables this effect.

The type is FLOAT.

The default value is 3.0f.

### `D2D1_DIRECTIONALBLUR_PROP_ANGLE:1`

The angle of the blur relative to the x-axis, in the counterclockwise direction. The units are specified in degrees.

The blur kernel is first generated using the same process as for the Gaussian blur effect. The kernel values are then transformed according to the blur angle.

The type is FLOAT.

The default value is 0.0f.

### `D2D1_DIRECTIONALBLUR_PROP_OPTIMIZATION:2`

The optimization mode. See Optimization modes for more info.

The type is [D2D1_DIRECTIONALBLUR_OPTIMIZATION](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_directionalblur_optimization).

The default value is D2D1_DIRECTIONALBLUR_OPTIMIZATION_BALANCED.

### `D2D1_DIRECTIONALBLUR_PROP_BORDER_MODE:3`

The mode used to calculate the border of the image, soft or hard. See Border modes for more info.

The type is [D2D1_BORDER_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_border_mode).

The default value is D2D1_BORDER_MODE_SOFT.

### `D2D1_DIRECTIONALBLUR_PROP_FORCE_DWORD:0xffffffff`
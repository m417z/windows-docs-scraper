# D2D1_SHADOW_PROP enumeration

## Description

Identifiers for properties of the [Shadow effect](https://learn.microsoft.com/windows/desktop/Direct2D/drop-shadow).

## Constants

### `D2D1_SHADOW_PROP_BLUR_STANDARD_DEVIATION:0`

The amount of blur to be applied to the alpha channel of the image. You can compute the blur radius of the kernel by multiplying the standard deviation by 3.
The units of both the standard deviation and blur radius are DIPs.

This property is the same as the Gaussian Blur standard deviation property.

The type is FLOAT.

The default value is 3.0f.

### `D2D1_SHADOW_PROP_COLOR:1`

The color of the drop shadow. This property is a D2D1_VECTOR_4F defined as: (R, G, B, A). You must specify this color in straight alpha.

The type is [D2D1_VECTOR_4F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_4f).

The default value is {0.0f, 0.0f, 0.0f, 1.0f}.

### `D2D1_SHADOW_PROP_OPTIMIZATION:2`

The level of performance optimization.

The type is [D2D1_SHADOW_OPTIMIZATION](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_shadow_optimization).

The default value is D2D1_SHADOW_OPTIMIZATION_BALANCED.

### `D2D1_SHADOW_PROP_FORCE_DWORD:0xffffffff`
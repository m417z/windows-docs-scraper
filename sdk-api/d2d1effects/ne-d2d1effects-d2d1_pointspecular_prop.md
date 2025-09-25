# D2D1_POINTSPECULAR_PROP enumeration

## Description

Identifiers for properties of the [Point-specular lighting effect](https://learn.microsoft.com/windows/desktop/Direct2D/point-specular).

## Constants

### `D2D1_POINTSPECULAR_PROP_LIGHT_POSITION:0`

The light position of the point light source. The property is a D2D1_VECTOR_3F defined as (x, y, z). The units are in device-independent pixels (DIPs) and the values are unitless and unbounded.

The type is D2D1_VECTOR_3F.

The default value is {0.0f, 0.0f, 0.0f}.

### `D2D1_POINTSPECULAR_PROP_SPECULAR_EXPONENT:1`

The exponent for the specular term in the Phong lighting equation. A larger value corresponds to a more reflective surface. This value is unitless and must be between 1.0 and 128.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_POINTSPECULAR_PROP_SPECULAR_CONSTANT:2`

The ratio of specular reflection to the incoming light. The value is unitless and must be between 0 and 10,000.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_POINTSPECULAR_PROP_SURFACE_SCALE:3`

The scale factor in the Z direction for generating a height map. The value is unitless and must be between 0 and 10,000.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_POINTSPECULAR_PROP_COLOR:4`

The color of the incoming light. This property is exposed as a [D2D1_VECTOR_3F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_3f) – (R, G, B) and used to compute LR, LG, LB.

The type is [D2D1_VECTOR_3F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_3f).

The default value is {1.0f, 1.0f, 1.0f}.

### `D2D1_POINTSPECULAR_PROP_KERNEL_UNIT_LENGTH:5`

The size of an element in the Sobel kernel used to generate the surface normal in the X and Y directions. This property maps to the dx and dy values in the Sobel gradient.
This property is a [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f)(Kernel Unit Length X, Kernel Unit Length Y) and is defined in (DIPs/Kernel Unit).
The effect uses bilinear interpolation to scale the bitmap to match size of kernel elements.

The type is [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f).

The default value is {1.0f, 1.0f}.

### `D2D1_POINTSPECULAR_PROP_SCALE_MODE:6`

The interpolation mode the effect uses to scale the image to the corresponding kernel unit length. There are six scale modes that range in quality and speed.

The type is [D2D1_POINTSPECULAR_SCALE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_pointspecular_scale_mode).

The default value is D2D1_POINTSPECULAR_SCALE_MODE_LINEAR.

### `D2D1_POINTSPECULAR_PROP_FORCE_DWORD:0xffffffff`
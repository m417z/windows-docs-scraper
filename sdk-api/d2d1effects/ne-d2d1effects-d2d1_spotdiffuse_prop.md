# D2D1_SPOTDIFFUSE_PROP enumeration

## Description

Identifiers for properties of the [Spot-diffuse lighting effect](https://learn.microsoft.com/windows/desktop/Direct2D/diffuse-lighting).

## Constants

### `D2D1_SPOTDIFFUSE_PROP_LIGHT_POSITION:0`

The light position of the point light source. The property is a D2D1_VECTOR_3F defined as (x, y, z). The units are in device-independent pixels (DIPs) and are unbounded.

The type is [D2D1_VECTOR_3F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_3f).

The default value is {0.0f, 0.0f, 0.0f}.

### `D2D1_SPOTDIFFUSE_PROP_POINTS_AT:1`

Where the spot light is focused. The property is exposed as a D2D1_VECTOR_3F with – (x, y, z). The units are in DIPs and the values are unbounded.

The type is [D2D1_VECTOR_3F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_3f).

The default value is {0.0f, 0.0f, 0.0f}.

### `D2D1_SPOTDIFFUSE_PROP_FOCUS:2`

The focus of the spot light. This property is unitless and is defined between 0 and 200.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_SPOTDIFFUSE_PROP_LIMITING_CONE_ANGLE:3`

The cone angle that restricts the region where the light is projected. No light is projected outside the cone. The limiting cone angle is the angle between the spot light axis (the axis between the LightPosition and PointsAt properties) and the spot light cone. This property is defined in degrees and must be between 0 to 90 degrees.

The type is FLOAT.

The default value is 90.0f.

### `D2D1_SPOTDIFFUSE_PROP_DIFFUSE_CONSTANT:4`

The ratio of diffuse reflection to amount of incoming light. This property must be between 0 and 10,000 and is unitless.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_SPOTDIFFUSE_PROP_SURFACE_SCALE:5`

The scale factor in the Z direction. The surface scale is unitless and must be between 0 and 10,000.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_SPOTDIFFUSE_PROP_COLOR:6`

The color of the incoming light. This property is exposed as a Vector 3 – (R, G, B) and used to compute LR, LG, LB.

The type is [D2D1_VECTOR_3F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_3f).

The default value is {1.0f, 1.0f, 1.0f}

### `D2D1_SPOTDIFFUSE_PROP_KERNEL_UNIT_LENGTH:7`

The size of an element in the Sobel kernel used to generate the surface normal in the X and Y direction. This property maps to the dx and dy values in the Sobel gradient.
This property is a [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f)(Kernel Unit Length X, Kernel Unit Length Y) and is defined in (DIPs/Kernel Unit).
The effect uses bilinear interpolation to scale the bitmap to match size of kernel elements.

The type is [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f).

The default value is {1.0f, 1.0f}.

### `D2D1_SPOTDIFFUSE_PROP_SCALE_MODE:8`

The interpolation mode the effect uses to scale the image to the corresponding kernel unit length. There are six scale modes that range in quality and speed.

The type is [D2D1_SPOTDIFFUSE_SCALE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_spotdiffuse_scale_mode).

The default value is D2D1_SPOTDIFFUSE_SCALE_MODE_LINEAR.

### `D2D1_SPOTDIFFUSE_PROP_FORCE_DWORD:0xffffffff`
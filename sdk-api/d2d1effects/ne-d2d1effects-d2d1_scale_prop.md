# D2D1_SCALE_PROP enumeration

## Description

Identifiers for properties of the [Scale effect](https://learn.microsoft.com/windows/desktop/Direct2D/high-quality-scale).

## Constants

### `D2D1_SCALE_PROP_SCALE:0`

The scale amount in the X and Y direction as a ratio of the output size to the input size.

This property a [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f) defined as: (X scale, Y scale).
The scale amounts are FLOAT, unitless, and must be positive or 0.

The type is [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f).

The default value is {1.0f, 1.0f}.

### `D2D1_SCALE_PROP_CENTER_POINT:1`

The image scaling center point. This property is a [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f) defined as: (point X, point Y). The units are in DIPs.

Use the center point property to scale around a point other than the upper-left corner.

The type is [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f).

The default value is {0.0f, 0.0f}.

### `D2D1_SCALE_PROP_INTERPOLATION_MODE:2`

The interpolation mode the effect uses to scale the image. There are 6 scale modes that range in quality and speed.

The type is [D2D1_SCALE_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_scale_interpolation_mode).

The default value is D2D1_SCALE_INTERPOLATION_MODE_LINEAR.

### `D2D1_SCALE_PROP_BORDER_MODE:3`

The mode used to calculate the border of the image, soft or hard.

The type is [D2D1_BORDER_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_border_mode).

The default value is D2D1_BORDER_MODE_SOFT.

### `D2D1_SCALE_PROP_SHARPNESS:4`

In the high quality cubic interpolation mode, the sharpness level of the scaling filter as a float between 0 and 1. The values are unitless.
You can use sharpness to adjust the quality of an image when you scale the image down.

The sharpness factor affects the shape of the kernel. The higher the sharpness factor, the smaller the kernel.

**Note** This property affects only the high quality cubic interpolation mode.

The type is FLOAT.

The default value is 0.0f.

### `D2D1_SCALE_PROP_FORCE_DWORD:0xffffffff`
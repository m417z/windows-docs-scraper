# D2D1_3DTRANSFORM_PROP enumeration

## Description

Identifiers for properties of the [3D transform effect](https://learn.microsoft.com/windows/desktop/Direct2D/3d-transform).

## Constants

### `D2D1_3DTRANSFORM_PROP_INTERPOLATION_MODE:0`

The interpolation mode the effect uses on the image. There are 5 scale modes that range in quality and speed.

Type is D2D1_3DTRANSFORM_INTERPOLATION_MODE.

Default value is D2D1_3DTRANSFORM_INTERPOLATION_MODE_LINEAR.

### `D2D1_3DTRANSFORM_PROP_BORDER_MODE:1`

The mode used to calculate the border of the image, soft or hard. See Border modes for more info.

Type is D2D1_BORDER_MODE.

Default value is D2D1_BORDER_MODE_SOFT.

### `D2D1_3DTRANSFORM_PROP_TRANSFORM_MATRIX:2`

A 4x4 transform matrix applied to the projection plane. The following matrix calculation is used to map points from one 3D coordinate system
to the transformed 2D coordinate system.

![3D Depth Matrix](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/3d_transform_matrix1.png)
Where:

X, Y, Z = Input projection plane coordinates

Mx,y = Transform Matrix elements

X’, Y’, Z’ =Output projection plane coordinates

The individual matrix elements are not bounded and are unitless.

Type is D2D1_MATRIX_4X4_F.

Default value is Matrix4x4F(1, 0, 0, 0,
0, 1, 0, 0,
0, 0, 1, 0,
0, 0, 0, 1).

### `D2D1_3DTRANSFORM_PROP_FORCE_DWORD:0xffffffff`
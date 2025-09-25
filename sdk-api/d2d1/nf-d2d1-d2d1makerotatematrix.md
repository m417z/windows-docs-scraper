# D2D1MakeRotateMatrix function

## Description

Creates a rotation transformation that rotates by the specified angle about the specified point.

## Parameters

### `angle` [in]

Type: **FLOAT**

The clockwise rotation angle, in degrees.

### `center` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The point about which to rotate.

### `matrix` [out]

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

When this method returns, contains the new rotation transformation. You must allocate storage for this parameter.

## Remarks

Rotation occurs in the plane of the 2-D surface.
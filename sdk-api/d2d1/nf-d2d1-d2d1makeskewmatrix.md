# D2D1MakeSkewMatrix function

## Description

Creates a skew transformation that has the specified x-axis angle, y-axis angle, and center point.

## Parameters

### `angleX` [in]

Type: **FLOAT**

The x-axis skew angle, which is measured in degrees counterclockwise from the y-axis.

### `angleY` [in]

Type: **FLOAT**

The y-axis skew angle, which is measured in degrees counterclockwise from the x-axis.

### `center` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The center point of the skew operation.

### `matrix` [out]

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-matrix-3x2-f)***

When this method returns, contains the rotation transformation. You must allocate storage for this parameter.
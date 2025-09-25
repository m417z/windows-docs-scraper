# IdentityMatrix function

## Description

Creates an identity matrix.

## Return value

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)**

An identity matrix.

## Remarks

The identity matrix is the 3x2 matrix with ones on the main diagonal and zeros elsewhere. When an identity transform is applied to an object, it does not change the position, shape, or size of the object. It is similar to the way that multiplying a number by 1 does not change the number. Any transform other than the identity transform will modify the position, shape, and/or size of objects.

Calling this function is the same as calling [D2D1::Matrix3x2F::Identity()](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-matrix3x2f-identity).

## See also

[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)
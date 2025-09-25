# Matrix3x2F::Matrix3x2F(FLOAT,FLOAT,FLOAT,FLOAT,FLOAT,FLOAT)

## Description

Instantiates a new instance of the [Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f) class that contains the specified values.

## Parameters

### `m11`

Type: **FLOAT**

The value in the first row and first column of the matrix.

### `m12`

Type: **FLOAT**

The value in the first row and second column of the matrix.

### `m21`

Type: **FLOAT**

The value in the second row and first column of the matrix.

### `m22`

Type: **FLOAT**

The value in the second row and second column of the matrix.

### `m31`

Type: **FLOAT**

The value in the third row and first column of the matrix.

### `m32`

Type: **FLOAT**

The value in the third row and second column of the matrix.

## Remarks

This method enables you to explicitly set the values of matrix members. When using this method, ensure that each member represents an appropriate value for your transformation matrix. For example, to create the identity matrix, you must set *_11* and *_22* to 1, and the rest to 0. To create a translation matrix, you must set *_11* and *_22* to 1, *_12* and *_21* to 0, *_31* to the x displacement, and *_32* to the y displacement.

For convenience and accuracy, we recommended that whenever possible you use other helper functions, such as [Identity](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-matrix3x2f-identity) and [Translation](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-matrix3x2f-translation(d2d1_size_f)), instead of this one.

## See also

[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)
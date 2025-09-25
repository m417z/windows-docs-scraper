# XPS_MATRIX structure

## Description

Describes the left two columns of a 3-by-3 matrix.

## Members

### `m11`

The value in the left column of the first row of the matrix.

### `m12`

The value in the center column of the first row of the matrix.

### `m21`

The value in the left column of the second row of the matrix.

### `m22`

The value in the center column of the second row of the matrix.

### `m31`

The value in the left column of the third row of the matrix. This value is also the x-offset.

### `m32`

The value in the center column of the third row of the matrix. This value is also the y-offset.

## Remarks

The values in the third column of the matrix are assumed to be 0, 0, 1.

The following table shows the entire matrix.

|  |  |  |
| --- | --- | --- |
| m11 | m12 | 0 |
| m21 | m22 | 0 |
| m31 | m32 | 1 |

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)
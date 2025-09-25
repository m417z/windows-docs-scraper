# XMFLOAT4X4::operator-function-call(size_t,size_t)

## Description

Returns a `reference` to a matrix element of an instance `XMFLOAT4X4` as specified by row and column
arguments.

**Note** This operator is only available under C++.

## Parameters

### `Row`

Row containing the matrix element of interest. Row specification is 0 based.

### `Column`

Column containing the matrix element of interest. Column specification is 0 based.

## Return value

A `reference` to the matrix element specified by the operator's **Row** and **Column** arguments.

## Remarks

As a `reference` to the matrix element is returned, this operator can be used to update the value of an element
of an instance of `XMFLOAT4X4`.

The following example:

|  |
| --- |
| ```      XMFLOAT4X4 mat;      float& a= mat(2,3);      a=42.0; ``` |

will set the value of the *mat.m[2,3]* (or equivalently mat._34) to 42.0.

## See also

**Reference**

[XMFLOAT4X4](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x4)

[XMFLOAT4X4 Operators](https://learn.microsoft.com/windows/win32/dxmath/ovw-xmfloat4x4-operators)
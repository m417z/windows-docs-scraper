# XMFLOAT3X3::operator-function-call(size_t,size_t)

## Description

Returns a `reference` to a matrix element of an instance `XMFLOAT3X3` as
specified by row and column arguments.

This operator returns a `reference` to a matrix element of an instance [XMFLOAT3X3](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x3)  as specified by row and column arguments.

**Note** This operator is only available under C++.

## Parameters

### `Row`

Row containing the matrix element of interest. Row specification is 0 based.

### `Column`

Column containing the matrix element of interest. Column specification is 0 based.

## Return value

A `reference` to the matrix element specified by the operator's
**Row** and **Column** arguments.

## Remarks

As a `reference` to the matrix element is returned, this operator can be used
to update the value of an element of an instance of `XMFLOAT3X3`.

The following example:

|  |
| --- |
| ```      XMFLOAT3X3 mat;      float& a= mat(1,2);      a=42.0; ``` |

will set the value of the *mat.m[1,2]* (or equivalently mat._23) to 42.0.

## See also

**Reference**

[XMFLOAT3X3](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x3)

[XMFLOAT3X3 Operators](https://learn.microsoft.com/windows/win32/dxmath/ovw-xmfloat3x3-operators)
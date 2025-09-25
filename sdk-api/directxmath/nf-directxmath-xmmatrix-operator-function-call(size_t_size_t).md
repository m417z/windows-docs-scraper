# XMMATRIX::operator-function-call(size_t,size_t)

## Description

Returns a `reference` to a matrix element of an instance `XMMATRIX` as specified by row and column
arguments.

This operator returns a `reference` to a matrix element of an instance [XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) as
specified by row and column arguments.

**Note** This operator is only available when developing with C++.

## Parameters

### `Row`

Row containing the matrix element of interest. Row specification is 0 based.

### `Column`

Column containing the matrix element of interest. Column specification is 0 based.

## Return value

A `reference` to the matrix element specified by the operator's **Row** and **Column** arguments.

## Remarks

This operator is only available when building with ``_XM_NO_INTRINSICS_``.

As a `reference` to the matrix element is returned, this operator can be used to update the value of an element
of an instance of `XMMATRIX`.

The following example:

|  |
| --- |
| ```      XMMATRIX mat;      float& a= mat(1,2);      a=42.0; ``` |

will set the value of the *mat.m[1][2]* to 42.0.

## See also

**Reference**

[XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix)

[XMMATRIX Operators](https://learn.microsoft.com/windows/win32/dxmath/ovw-xmmatrix-operators)
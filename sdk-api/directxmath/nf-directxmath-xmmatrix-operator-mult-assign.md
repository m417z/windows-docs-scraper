# XMMATRIX::operator-mult-assign

## Description

Performs a matrix multiplication of the current instance of `XMMATRIX` by another instance of `XMMATRIX` and returns a reference to the current instance, which has been updated.

This operator performs a matrix multiplication of the current instance of [XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) by another instance of `XMMATRIX` and returns a reference to the current instance, which has been updated.

**Note** This operator is only available when developing with C++.

## Parameters

### `M` [ref]

Instance of `XMMATRIX` to be multiplied against the current instance of `XMMATRIX`.

## Return value

Reference to the current instance of `XMMATRIX`, which has been updated by this operator.

## Remarks

The current `XMMATRIX` is the left hand side of the matrix multiplication. That is the matrix operation *mat1 = mat1 * M*  can be implemented as:

|  |
| --- |
| ```       XMMATRIX mat1;       XMMATRIX M       mat1 *= M ``` |

And is equivalent to using operator* and
assigning the result to the call's first argument.

|  |
| --- |
| ```       const XMMATRIX& M;       XMMATRIX& mat1;       mat1 = XMMatrixMultiply(mat1, M); ``` |

## See also

**Reference**

[XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix)

[XMMATRIX Operators](https://learn.microsoft.com/windows/win32/dxmath/ovw-xmmatrix-operators)
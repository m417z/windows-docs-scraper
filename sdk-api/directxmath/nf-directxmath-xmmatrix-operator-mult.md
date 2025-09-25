# XMMATRIX::operator-mult

## Description

Performs a matrix multiplication of the current instance of `XMMATRIX` by another instance of `XMMATRIX`.

This operator performs a matrix multiplication of the current instance of [XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) by another instance of `XMMATRIX`.

**Note** This operator is only available when developing with C++.

## Parameters

### `M` [ref]

Instance of `XMMATRIX` to be multiplied against the current instance of `XMMATRIX`.

## Return value

An instance of `XMMATRIX` containing the result of the matrix multiplication.

## Remarks

The current `XMMATRIX` is the left hand side of the matrix multiplication. That is the matrix operation *mat2 = mat1 * M*  can be implemented as:

|  |
| --- |
| ```       XMMATRIX mat1;       XMMATRIX mat2;       XMMATRIX M       mat2 = mat1 * M ``` |

|  |
| --- |
| ```       const XMMATRIX& M;       XMMATRIX& mat1;       XMMATRIX& mat2;       mat2 = XMMatrixMultiply(mat1, M); ``` |

## See also

**Reference**

[XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix)

[XMMATRIX Operators](https://learn.microsoft.com/windows/win32/dxmath/ovw-xmmatrix-operators)
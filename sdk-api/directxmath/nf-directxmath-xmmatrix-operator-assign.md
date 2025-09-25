# XMMATRIX::operator-assign

## Description

Assigns the matrix data of one instance of `XMMATRIX` to the current instance of
`XMMATRIX` and returns a `reference` to the current instance.

This operator assigns the matrix data of one instance of [XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) to the current instance of `XMMATRIX` and returns a `reference` to the current
instance.

**Note** This operator is only available when developing with C++.

## Parameters

### `M` [ref]

Instance of `XMMATRIX` whose data
is used to update the current instance.

## Return value

A `reference` to the current instance of `XMMATRIX`, which has been updated by this operator.

## Remarks

The following pseudocode demonstrates the operation of this operator:

|  |
| --- |
| ```    XMMATRIX mat1;    XMMATRIX M;    // mat1=mat1*M    for (int i=0;i<4;i++){        for (int j=0;j<4;j++){            mat1.m[i][j]=M.m[i][j];        }    } ``` |

## See also

**Reference**

[XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix)

[XMMATRIX Operators](https://learn.microsoft.com/windows/win32/dxmath/ovw-xmmatrix-operators)
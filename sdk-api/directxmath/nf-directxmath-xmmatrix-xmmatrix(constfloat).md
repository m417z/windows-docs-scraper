# XMMATRIX::XMMATRIX(const float)

## Description

Initializes a new instance of the [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix) structure from a sixteen element `float` array.

Initializes a new instance of the **XMMATRIX** structure from a sixteen element `float` array.

**Note** This constructor is only available when developing with C++.

## Parameters

### `pArray`

Address of a 16 element float array, specifying the value of each member of a new instance of **XMMATRIX**.

## Remarks

The matrix elements are stored in *pArray* in *row-major* order.

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMMATRIX mat;
mat._11=pArray[0];
mat._12=pArray[1];
mat._13=pArray[2];
mat._14=pArray[3];
mat._21=pArray[4];
mat._22=pArray[5];
mat._23=pArray[6];
mat._24=pArray[7];
mat._31=pArray[8];
mat._32=pArray[9];
mat._33=pArray[10];
mat._34=pArray[11];
mat._41=pArray[12];
mat._42=pArray[13];
mat._43=pArray[14];
mat._44=pArray[15];
```

## See also

[XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix)

[XMMATRIX Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmmatrix-ctor)
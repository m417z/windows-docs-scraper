# XMFLOAT4X3::XMFLOAT4X3(const float)

## Description

Initializes a new instance of the `XMFLOAT4X3` structure from a twelve element
`float` array.

Initializes a new instance of the [XMFLOAT4X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x3) structure from a
twelve element `float` array.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Address of a 12 element `float` array, specifying the value of each member
of a new instance of [XMFLOAT4X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x3).

## Remarks

The matrix elements are stored in **pArray** in *row-major* order.

The following two pseudocode examples demonstrate the operation of this constructor:

```

   XMFLOAT4X3 mat;
   mat._11 = pArray[0];
   mat._12 = pArray[1];
   mat._13 = pArray[2];
   mat._21 = pArray[3];
   mat._22 = pArray[4];
   mat._23 = pArray[5];
   mat._31 = pArray[6];
   mat._32 = pArray[7];
   mat._33 = pArray[8];
   mat._41 = pArray[9];
   mat._42 = pArray[10];
   mat._43 = pArray[11];

```

Or

```

   XMFLOAT4X3 mat;
   mat.m[0,0] = pArray[0];
   mat.m[0,1] = pArray[1];
   mat.m[0,2] = pArray[2];
   mat.m[1,0] = pArray[3];
   mat.m[1,1] = pArray[4];
   mat.m[1,2] = pArray[5];
   mat.m[2,0] = pArray[6];
   mat.m[2,1] = pArray[7];
   mat.m[2,2] = pArray[8];
   mat.m[3,0] = pArray[9];
   mat.m[3,1] = pArray[10];
   mat.m[3,2] = pArray[11];

```

## See also

**Reference**

[XMFLOAT4X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x3)

[XMFLOAT4X3 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat4x3-ctor)
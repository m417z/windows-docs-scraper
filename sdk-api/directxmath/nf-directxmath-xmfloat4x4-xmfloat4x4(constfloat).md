# XMFLOAT4X4::XMFLOAT4X4(const float)

## Description

Initializes a new instance of the `XMFLOAT4X4` structure from a sixteen element
`float` array.

Initializes a new instance of the [XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4) structure from a
sixteen element `float` array.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Address of a 16 element `float` array, specifying the value of each member
of a new instance of [XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4).

## Remarks

The matrix elements are stored in **pArray** in *row-major* order.

The following two pseudocode examples demonstrate the operation of this constructor:

```

   XMFLOAT4X4 mat;
   mat._11 = pArray[0];
   mat._12 = pArray[1];
   mat._13 = pArray[2];
   mat._14 = pArray[3];
   mat._21 = pArray[4];
   mat._22 = pArray[5];
   mat._23 = pArray[6];
   mat._24 = pArray[7];
   mat._31 = pArray[8];
   mat._32 = pArray[9];
   mat._33 = pArray[10];
   mat._34 = pArray[11];
   mat._41 = pArray[12];
   mat._42 = pArray[13];
   mat._43 = pArray[14];
   mat._44 = pArray[16];

```

Or

```

    XMFLOAT4X4 mat;
   mat.m[0,0] = pArray[0];
   mat.m[0,1] = pArray[1];
   mat.m[0,2] = pArray[2];
   mat.m[0,3] = pArray[3];
   mat.m[1,0] = pArray[4];
   mat.m[1,1] = pArray[5];
   mat.m[1,2] = pArray[6];
   mat.m[1,3] = pArray[7];
   mat.m[2,0] = pArray[8];
   mat.m[2,1] = pArray[9];
   mat.m[2,2] = pArray[10];
   mat.m[2,3] = pArray[11];
   mat.m[3,0] = pArray[12];
   mat.m[3,1] = pArray[13];
   mat.m[3,2] = pArray[14];
   mat.m[3,3] = pArray[16];

```

## See also

**Reference**

[XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4)

[XMFLOAT4X4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat4x4-ctor)
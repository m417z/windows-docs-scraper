# XMFLOAT4X4::XMFLOAT4X4(float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float)

## Description

Initializes a new instance of the `XMFLOAT4X4` structure from sixteen scalar
`float` values.

Initializes a new instance of the [XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4) structure from sixteen
scalar `float` values.

**Note** This constructor is only available under C++.

## Parameters

### `m00`

Value used to initialize the **_11** member (equivalently the **m[0,0]** member) of the `XMFLOAT4X4` structure.

### `m01`

Value used to initialize the **_12** member (equivalently the
**m[0,1]**) of the `XMFLOAT4X4` structure.

### `m02`

Value used to initialize the **_13** member (equivalently the
**m[0,2]**) of the `XMFLOAT4X4` structure.

### `m03`

Value used to initialize the **_14** member (equivalently the
**m[0,3]**) of the `XMFLOAT4X4` structure.

### `m10`

Value used to initialize the **_21** member (equivalently the
**m[1,0]**) of the `XMFLOAT4X4` structure.

### `m11`

Value used to initialize the **_22** member (equivalently the
**m[1,1]**) of the `XMFLOAT4X4` structure.

### `m12`

Value used to initialize the **_23** member (equivalently the
**m[1,2]**) of the `XMFLOAT4X4` structure.

### `m13`

Value used to initialize the **_24** member (equivalently the
**m[1,3]**) of the `XMFLOAT4X4` structure.

### `m20`

Value used to initialize the **_31** member (equivalently the
**m[2,0]**) of the `XMFLOAT4X4` structure.

### `m21`

Value used to initialize the **_32** member (equivalently the
**m[2,1]**) of the `XMFLOAT4X4` structure.

### `m22`

Value used to initialize the **_33** member (equivalently the
**m[2,2]**) of the `XMFLOAT4X4` structure.

### `m23`

Value used to initialize the **_34** member (equivalently the
**m[2,3]**) of the `XMFLOAT4X4` structure.

### `m30`

Value used to initialize the **_41** member (equivalently the
**m[3,0]**) of the `XMFLOAT4X4` structure.

### `m31`

Value used to initialize the **_42** member (equivalently the
**m[3,1]**) of the `XMFLOAT4X4` structure.

### `m32`

Value used to initialize the **_43** member (equivalently the
**m[3,2]**) of the `XMFLOAT4X4` structure.

### `m33`

Value used to initialize the **_34** member (equivalently the
**m[3,3]**) of the `XMFLOAT4X4` structure.

## Remarks

The following two pseudocode examples demonstrate the operation of this constructor:

```

   XMFLOAT4X4 mat;
   mat._11 = m00;
   mat._12 = m01;
   mat._13 = m02;
   mat._14 = m03;
   mat._21 = m10;
   mat._22 = m11;
   mat._23 = m12;
   mat._24 = m13;
   mat._31 = m20;
   mat._32 = m21;
   mat._33 = m22;
   mat._34 = m23;
   mat._41 = m30;
   mat._42 = m31;
   mat._43 = m32;
   mat._44 = m33;

```

Or

```

   XMFLOAT4X4 mat;
   mat.m[0,0] = m00;
   mat.m[0,1] = m01;
   mat.m[0,2] = m02;
   mat.m[0,3] = m03;
   mat.m[1,0] = m10;
   mat.m[1,1] = m11;
   mat.m[1,2] = m12;
   mat.m[1,3] = m13;
   mat.m[2,0] = m20;
   mat.m[2,1] = m21;
   mat.m[2,2] = m22;
   mat.m[2,3] = m23;
   mat.m[3,0] = m30;
   mat.m[3,1] = m31;
   mat.m[3,2] = m32;
   mat.m[3,3] = m33;

```

## See also

**Reference**

[XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4)

[XMFLOAT4X4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmfloat4x4-ctor)
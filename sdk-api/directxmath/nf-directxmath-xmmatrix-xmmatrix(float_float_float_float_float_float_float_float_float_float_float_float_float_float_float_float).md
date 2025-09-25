# XMMATRIX::XMMATRIX(float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float)

## Description

Initializes a new instance of the `XMMATRIX` structure from sixteen scalar
`float` values.

Initializes a new instance of the [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix) structure from sixteen
scalar `float` values.

**Note** This constructor is only available when developing with C++.

## Parameters

### `m00`

Value used to initialize the **_11** member of the `XMMATRIX` structure.

### `m01`

Value used to initialize the **_12** member of the `XMMATRIX` structure.

### `m02`

Value used to initialize the **_13** member of the `XMMATRIX` structure.

### `m03`

Value used to initialize the **_14** member of the `XMMATRIX` structure.

### `m10`

Value used to initialize the **_21** member of the `XMMATRIX` structure.

### `m11`

Value used to initialize the **_22** member of the `XMMATRIX` structure.

### `m12`

Value used to initialize the **_23** member of the `XMMATRIX` structure.

### `m13`

Value used to initialize the **_24** member of the `XMMATRIX` structure.

### `m20`

Value used to initialize the **_31** member of the `XMMATRIX` structure.

### `m21`

Value used to initialize the **_32** member of the `XMMATRIX` structure.

### `m22`

Value used to initialize the **_33** member of the `XMMATRIX` structure.

### `m23`

Value used to initialize the **_34** member of the `XMMATRIX` structure.

### `m30`

Value used to initialize the **_41** member of the `XMMATRIX` structure.

### `m31`

Value used to initialize the **_42** member of the `XMMATRIX` structure.

### `m32`

Value used to initialize the **_43** member of the `XMMATRIX` structure.

### `m33`

Value used to initialize the **_44** member of the `XMMATRIX` structure.

## Remarks

The following pseudocode example demonstrates the operation of this constructor:

```

   XMMATRIX mat;
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

## See also

**Reference**

[XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix)

[XMMATRIX Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmmatrix-ctor)
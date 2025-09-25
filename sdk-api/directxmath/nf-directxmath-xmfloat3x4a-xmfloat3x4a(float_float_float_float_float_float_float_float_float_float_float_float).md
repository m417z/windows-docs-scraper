## Description

Constructs an **XMFLOAT3X4A** from 12 scalar float values.

## Parameters

### `m00`

Value used to initialize the *_11* member (equivalently, the *m\[0,0\]* member) of the new matrix.

### `m01`

Value used to initialize the *_12* member (equivalently, the *m\[0,1\]* member) of the new matrix.

### `m02`

Value used to initialize the *_13* member (equivalently, the *m\[0,2\]* member) of the new matrix.

### `m03`

Value used to initialize the *_14* member (equivalently, the *m\[0,3\]* member) of the new matrix.

### `m10`

Value used to initialize the *_21* member (equivalently, the *m\[1,0\]* member) of the new matrix.

### `m11`

Value used to initialize the *_22* member (equivalently, the *m\[1,1\]* member) of the new matrix.

### `m12`

Value used to initialize the *_23* member (equivalently, the *m\[1,2\]* member) of the new matrix.

### `m13`

Value used to initialize the *_24* member (equivalently, the *m\[1,3\]* member) of the new matrix.

### `m20`

Value used to initialize the *_31* member (equivalently, the *m\[2,0\]* member) of the new matrix.

### `m21`

Value used to initialize the *_32* member (equivalently, the *m\[2,1\]* member) of the new matrix.

### `m22`

Value used to initialize the *_33* member (equivalently, the *m\[2,2\]* member) of the new matrix.

### `m23`

Value used to initialize the *_34* member (equivalently, the *m\[2,3\]* member) of the new matrix.

## Remarks

These two pseudocode examples illustrate how this constructor operates.

```cpp
DirectX::XMFLOAT3X4A mat;
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
```

```
DirectX::XMFLOAT3X4A mat;
mat.m[0, 0] = m00;
mat.m[0, 1] = m01;
mat.m[0, 2] = m02;
mat.m[0, 3] = m03;
mat.m[1, 0] = m10;
mat.m[1, 1] = m11;
mat.m[1, 2] = m12;
mat.m[1, 3] = m13;
mat.m[2, 0] = m20;
mat.m[2, 1] = m21;
mat.m[2, 2] = m22;
mat.m[2, 3] = m23;
```

## See also

[XMFLOAT3X4A structure](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4a)
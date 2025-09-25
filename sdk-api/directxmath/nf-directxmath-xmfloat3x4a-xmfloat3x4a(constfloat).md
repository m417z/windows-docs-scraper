## Description

Constructs an **XMFLOAT3X4A** from a 12-element array of float values.

## Parameters

### `pArray`

Type: **const float \***

A pointer to a 12-element array of float values. The array specifies the value of each member of the new matrix.

## Remarks

The matrix elements in *pArray* should be in row-major order. These two pseudocode examples illustrate how this constructor operates.

```cpp
DirectX::XMFLOAT3X4A mat;
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
```

```
DirectX::XMFLOAT3X4A mat;
mat.m[0, 0] = pArray[0];
mat.m[0, 1] = pArray[1];
mat.m[0, 2] = pArray[2];
mat.m[0, 3] = pArray[3];
mat.m[1, 0] = pArray[4];
mat.m[1, 1] = pArray[5];
mat.m[1, 2] = pArray[6];
mat.m[1, 3] = pArray[7];
mat.m[2, 0] = pArray[8];
mat.m[2, 1] = pArray[9];
mat.m[2, 2] = pArray[10];
mat.m[2, 3] = pArray[11];
```

## See also

[XMFLOAT3X4A structure](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4a)
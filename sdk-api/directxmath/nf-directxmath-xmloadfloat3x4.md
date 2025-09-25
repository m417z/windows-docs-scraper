## Description

Loads an [**XMFLOAT3X4**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4) into an [**XMMATRIX**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix).

## Parameters

### `pSource`

Type: **const [XMFLOAT3X4](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4) \***

Pointer to the constant [**XMFLOAT3X4**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4) structure to load. This argument must point to cached memory.

## Return value

Type: **[XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix)**

An [**XMMATRIX**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) loaded with the data from the *pSource* argument.

This function performs a partial load of the returned **XMMATRIX**. For more info, see [Getting started (DirectXMath)](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-getting-started).

## Remarks

[**XMFLOAT3X4**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4) is a row-major form of the matrix. **XMLoadFloat3x4** could be used to read column-major data, but that would then need to be transposed with [XMMatrixTranspose](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmmatrixtranspose) before use in other [**XMMATRIX**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) functions.

## See also

[DirectXMath Library vector load functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
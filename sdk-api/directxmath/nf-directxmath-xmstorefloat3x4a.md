## Description

Stores an [**XMMATRIX**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) in an [**XMFLOAT3X4A**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4a).

## Parameters

### `pDestination` [out]

Type: **XMFLOAT3X4A \***

Pointer to the [**XMFLOAT3X4A**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4a) structure in which to store the data.

### `M` [in]

Type: **[XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix)**

Matrix containing the data to store.

## Remarks

[**XMFLOAT3X4A**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4a) is a row-major form of the matrix.

To write out column-major data requires that the [**XMMATRIX**](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) be transposed via [XMMatrixTranspose](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmmatrixtranspose) before calling the store function.

## See also

[DirectXMath Library vector store functions](https://learn.microsoft.com/windows/win32/dxmath/ovw-xnamath-reference-functions-storage)
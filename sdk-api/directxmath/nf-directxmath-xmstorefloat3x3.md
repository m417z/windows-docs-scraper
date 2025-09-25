# XMStoreFloat3x3 function

## Description

Stores an [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix) in an [XMFLOAT3X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3x3).

## Parameters

### `pDestination` [out]

Address at which to store the data.

### `M` [in]

Matrix containing the data to store.

## Return value

None.

## Remarks

[XMFLOAT3X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3x3) is a row-major matrix form. To write out column-major data requires the XMMATRIX be
transposed via [XMMatrixTranpose](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmmatrixtranspose) before calling the store function.

This function takes a matrix and writes the components out to nine single-precision floating-point values at the given
address. The most significant component of the first row vector is written to the first four bytes of the address,
followed by the second most significant component of the first row, followed by the third most significant component
of the first row. The most significant three components of the second row are then written out in a like manner to
memory beginning at byte 12, followed by the third row to memory beginning at byte 24.

The following pseudocode demonstrates the operation of the function.

```
pDestination->_11 = M[0].x; // 4 bytes to address (uint8_t*)pDestination
pDestination->_12 = M[0].y; // 4 bytes to address (uint8_t*)pDestination + 4
pDestination->_13 = M[0].z; // 4 bytes to address (uint8_t*)pDestination + 8

pDestination->_21 = M[1].x; // 4 bytes to address (uint8_t*)pDestination + 12
pDestination->_22 = M[1].y; // 4 bytes to address (uint8_t*)pDestination + 16
pDestination->_23 = M[1].z; // 4 bytes to address (uint8_t*)pDestination + 20

pDestination->_31 = M[2].x; // 4 bytes to address (uint8_t*)pDestination + 24
pDestination->_32 = M[2].y; // 4 bytes to address (uint8_t*)pDestination + 28
pDestination->_33 = M[2].z; // 4 bytes to address (uint8_t*)pDestination + 32
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
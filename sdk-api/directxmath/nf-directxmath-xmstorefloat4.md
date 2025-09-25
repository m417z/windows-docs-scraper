# XMStoreFloat4 function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4).

## Parameters

### `pDestination` [out]

Address at which to store the data.

### `V` [in]

Vector containing the data to store.

## Return value

None.

## Remarks

This function takes a vector and writes the components out to four single-precision floating-point values at the given address. The most significant component is written to the first four bytes of the address, the next most significant component is written to the next four bytes, and so on.

The following pseudocode demonstrates the operation of the function.

```
pDestination->x = V.x; // 4 bytes to address pDestination
pDestination->y = V.y; // 4 bytes to address (uint8_t*)pDestination + 4
pDestination->z = V.z; // 4 bytes to address (uint8_t*)pDestination + 8
pDestination->w = V.w; // 4 bytes to address (uint8_t*)pDestination + 12
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
# XMStoreShort2 function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort2).

## Parameters

### `pDestination` [out]

Address at which to store the data.

### `V` [in]

Vector containing the data to store.

## Return value

None.

## Remarks

This function takes a vector, clamps it to the range -32767.0f to 32767.0f, converts the two most significant components into a signed, normalized integer format, and writes the results out to two short integer values at the given address. The most significant component is written to the first two bytes of the address and the next most significant component is written to the next two bytes of the address.

The following pseudocode demonstrates the operation of the function.

```
static const XMVECTOR  Min = {-32767.0f, -32767.0f, -32767.0f, -32767.0f};
static const XMVECTOR  Max = {32767.0f, 32767.0f, 32767.0f, 32767.0f};
XMVECTOR               N;
N = XMVectorClamp(V, Min, Max);
N = XMVectorRound(N);

pDestination->x = (int16_t)N.x; // 2 bytes to address pDestination
pDestination->y = (int16_t)N.y; // 2 bytes to address (uint8_t*)pDestination + 2
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
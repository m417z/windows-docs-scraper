# XMStoreUByte2 function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMUBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte2).

## Parameters

### `pDestination` [out]

Address at which to store the data.

### `V` [in]

Vector containing the data to store.

## Return value

None.

## Remarks

The following pseudocode demonstrates the operation of the function.

```

XMVECTOR N;	
static const XMVECTOR  Max = {255.0f, 255.0f, 255.0f, 255.0f};

assert(pDestination);

N = XMVectorClamp(V, XMVectorZero(), Max);
N = XMVectorRound(N);

pDestination->x = (uint8_t)N.v[0];
pDestination->y = (uint8_t)N.v[1];

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
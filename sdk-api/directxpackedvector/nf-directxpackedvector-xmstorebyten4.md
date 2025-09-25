# XMStoreByteN4 function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten4).

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
static const XMVECTOR  Scale = {127.0f, 127.0f, 127.0f, 127.0f};

N = XMVectorMultiply(V, Scale);
N = XMVectorRound(N);

pDestination->x = (int8_t)N.v[0];
pDestination->y = (int8_t)N.v[1];
pDestination->z = (int8_t)N.v[2];
pDestination->w = (int8_t)N.v[3];
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
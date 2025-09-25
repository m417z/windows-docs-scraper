# XMStoreUDecN4 function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMUDECN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmudecn4).

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
static const XMVECTOR  Scale = {1023.0f, 1023.0f, 1023.0f, 3.0f};

assert(pDestination);

N = XMVectorClamp(V, XMVectorZero(), g_XMOne);
N = XMVectorMultiply(N, Scale);

pDestination->v = ((uint32_t)N.v[3] << 30) |
                  (((uint32_t)N.v[2] & 0x3FF) << 20) |
                  (((uint32_t)N.v[1] & 0x3FF) << 10) |
                  (((uint32_t)N.v[0] & 0x3FF));
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
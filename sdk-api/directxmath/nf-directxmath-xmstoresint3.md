# XMStoreSInt3 function

## Description

Stores signed integer data from an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an **XMINT3** structure.

## Parameters

### `pDestination` [out]

Address of an [XMINT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmint3) structure in which to store the data.

### `V`

Vector containing the data to store.

## Return value

None.

## Remarks

For 16-byte aligned memory, it may be faster to use [XMStoreInt3A](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmstoreint3a) with a casting operator.

The following pseudocode shows the operation of this function.

```

XMVECTOR N;	

assert(pDestination);

N = XMVectorClamp(V, MinInt, MaxInt );
N = XMVectorRound(N);

pDestination->x = (int32_t)N.v[0];
pDestination->y = (int32_t)N.v[1];
pDestination->z = (int32_t)N.v[2];

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
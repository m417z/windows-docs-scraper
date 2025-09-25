# XMStoreInt2 function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in a 2-element **uint32_t** array.

## Parameters

### `pDestination` [out]

Address at which to store the data. This pointer must be 4-byte aligned.

### `V` [in]

Vector containing the data to store.

## Return value

None.

## Remarks

The following pseudocode shows you the operation of the function.

```
uint32_t* pElement = (uint32_t*)pDestination;

assert(pDestination);
assert(((uint32_t_PTR)pDestination & 3) == 0);

pElement[0] = V.u[0];
pElement[1] = V.u[1];
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)

[XMINT2](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmint2)

[XMStoreSInt2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmstoresint2)

[XMStoreUInt2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmstoreuint2)

[XMUINT2](https://learn.microsoft.com/windows/desktop/direct3dhlsl/xmuint2)
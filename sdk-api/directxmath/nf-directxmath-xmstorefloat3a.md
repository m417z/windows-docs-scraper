# XMStoreFloat3A function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMFLOAT3A](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3a).

## Parameters

### `pDestination` [out]

Address at which to store the data. This address must be 16-byte aligned.

### `V` [in]

Vector containing the data to store.

## Return value

None.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
return (XMFLOAT3A*)XMStoreVector3A(pDestination, V);
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
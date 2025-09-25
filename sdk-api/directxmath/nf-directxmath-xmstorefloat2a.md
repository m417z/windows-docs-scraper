# XMStoreFloat2A function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMFLOAT2A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419469(v=vs.85)).

## Parameters

### `pDestination` [out]

Address at which to store the data. The given address must be aligned on a 16-byte boundary.

### `V` [in]

Vector containing the data to store.

## Return value

None.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
return (XMFLOAT2A*)XMStoreVector2A(pDestination, V);
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)
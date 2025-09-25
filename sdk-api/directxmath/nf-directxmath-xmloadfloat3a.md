# XMLoadFloat3A function

## Description

Loads an [XMFLOAT3A](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3a) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMFLOAT3A](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3a) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The **x**, **y**, and **z** members of the [XMFLOAT3A](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3a) are loaded
into the corresponding members of the returned [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type). The **w** member of the
**XMVECTOR** is initialized to 0.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
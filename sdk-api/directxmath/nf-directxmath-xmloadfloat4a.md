# XMLoadFloat4A function

## Description

Loads an [XMFLOAT4A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419609(v=vs.85)) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMFLOAT4A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419609(v=vs.85)) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The members of the [XMFLOAT4A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419609(v=vs.85)) are loaded into the corresponding members of the returned
[XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
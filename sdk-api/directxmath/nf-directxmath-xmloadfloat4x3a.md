# XMLoadFloat4x3A function

## Description

Loads an [XMFLOAT4X3A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419612(v=vs.85)) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMFLOAT4X3A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419612(v=vs.85)) structure to load.

## Return value

Returns an [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix) loaded with the data from the *pSource* parameter.

This function performs a partial load of the returned [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix). See [Getting Started](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-getting-started) for more information.

## Remarks

[XMFLOAT4X3A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419612(v=vs.85)) is a row-major form of the matrix. This function cannot be used to read column-major data since it assumes the last column is 0 0 0 1.

The members of the [XMFLOAT4X4A](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x4a) structure (**_11**, **_12**,
**_13**, and so on) are loaded into the corresponding members of the
[XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix). The remaining members of the returned
**XMMATRIX** are 0.0f, except for **_44**, which is 1.0f.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
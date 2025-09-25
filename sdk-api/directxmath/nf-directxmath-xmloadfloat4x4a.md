# XMLoadFloat4x4A function

## Description

Loads an [XMFLOAT4X4A](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x4a) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMFLOAT4X4A](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x4a) structure to load.

## Return value

Returns an [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix) loaded with the data from the *pSource* parameter.

## Remarks

[XMFLOAT4X4A](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x4a) is a row-major form of the matrix. This function could be used to read column-major data,
but would then need to be transposed with [XMMatrixTranpose](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmmatrixtranspose) before use in other XMMATRIX functions.

The members of the [XMFLOAT4X4A](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x4a) structure (**_11**, **_12**,
**_13**, and so on) are loaded into the corresponding members of the
[XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
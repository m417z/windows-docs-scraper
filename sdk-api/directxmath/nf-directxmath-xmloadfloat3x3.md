# XMLoadFloat3x3 function

## Description

Loads an [XMFLOAT3X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3x3) into an [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix).

## Parameters

### `pSource` [in]

Address of the [XMFLOAT3X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3x3) structure to load. This parameter must point to cached
memory.

## Return value

Returns an [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix) loaded with the data from the *pSource* parameter.

This function performs a partial load of the returned [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix). See [Getting Started](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-getting-started) for more information.

## Remarks

[XMFLOAT3X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3x3) is a row-major form of the matrix. This function could be used to read column-major data,
but would then need to be transposed with [XMMatrixTranpose](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmmatrixtranspose) before use in other XMMATRIX functions.

The members of the [XMFLOAT3X3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3x3) structures (**_11**, **_12**,
**_13**, and so on) are loaded into the corresponding members of the
[XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix). The remaining members of the returned
**XMMATRIX** are 0.0f, except for **_44**, which is 1.0f.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
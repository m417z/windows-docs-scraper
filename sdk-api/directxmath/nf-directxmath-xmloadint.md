# XMLoadInt function

## Description

Loads a scalar value into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the scalar data to load.

## Return value

Returns an `XMVECTORI` whose **x** member is loaded with the data from
the *pSource* parameter. The other components of the returned vector will be initialized to 0.

## Remarks

To convert the loaded [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) into float values, use [XMConvertVectorUIntToFloat](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectoruinttofloat) or [XMConvertVectorIntToFloat](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectorinttofloat).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
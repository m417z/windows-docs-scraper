# XMLoadHalf2 function

## Description

Loads an [XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The **x** and **y** members of the [XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2) are converted to
single-precision format and loaded into the corresponding members of the [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type). The
**z** and **w** members of the returned **XMVECTOR** will be initialized to 0.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
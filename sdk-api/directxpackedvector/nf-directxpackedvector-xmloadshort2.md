# XMLoadShort2 function

## Description

Loads an [XMSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort2) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort2) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) structure loaded with the data from the *pSource* parameter.

## Remarks

The **x** and **y** members of the [XMSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort2) are converted to
single-precision format, and loaded into the corresponding members of the [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type). The
**z** and **w** members of the returned **XMVECTOR** will be initialized to 0. The
following pseudocode shows you the operation of this function:

```
XMVECTOR Result;

Result.x = (float)pSource->x;
Result.y = (float)pSource->y;
vectorOut.z = 0;
vectorOut.w = 0;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
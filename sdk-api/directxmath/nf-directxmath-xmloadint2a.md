# XMLoadInt2A function

## Description

Loads 16-byte aligned data into the **x** and **y** components of an
[XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `PSource` [in]

Address of the 16-byte aligned data to load.

## Return value

Returns an `XMVECTORI` loaded with the data from the *pSource* parameter.

## Remarks

The z and w components of the returned [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) will be initialized to 0.

To convert the loaded [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) into float values, use [XMConvertVectorUIntToFloat](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectoruinttofloat) or [XMConvertVectorIntToFloat](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectorinttofloat).

The following pseudocode shows you the operation of the function.

```
XMVECTOR vectorOut;

uint32_t* pElement = (uint32_t*)pSource;

assert(((uint32_t_PTR)pSource & 0xF) == 0);

V.u[0] = pElement[0];
V.u[1] = pElement[1];
V.u[2] = 0;
V.u[3] = 0;

	
return vectorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)
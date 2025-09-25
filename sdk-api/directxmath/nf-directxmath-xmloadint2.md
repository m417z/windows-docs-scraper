# XMLoadInt2 function

## Description

Loads data into the x and y components of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the data to load.

## Return value

Returns an `XMVECTORI` loaded with the data from the *pSource* parameter.

## Remarks

The z and w components of the returned [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) will be initialized to 0.

For 16-byte aligned memory, it may be faster to use [XMLoadInt2A](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloadint2a) with a casting operator.

To convert the loaded [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) into float values, use [XMConvertVectorUIntToFloat](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectoruinttofloat) or [XMConvertVectorIntToFloat](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectorinttofloat).

The following pseudocode shows you the operation of the function.

```
XMVECTOR vectorOut;

uint32_t* pElement = (uint32_t*)pSource;

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

[XMINT2](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmint2)

[XMLoadSInt2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloadsint2)

[XMLoadUInt2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloaduint2)

[XMUINT2](https://learn.microsoft.com/windows/desktop/direct3dhlsl/xmuint2)
# XMConvertVectorUIntToFloat function

## Description

Converts an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) with **uint32_t** components to an
**XMVECTOR** with **float** components and applies a uniform bias.

## Parameters

### `VUInt` [in]

Vector with **uint32_t** components that is to be converted.

### `DivExponent` [in]

Each component of *VUInt* will be converted to a **float** and then divided by two raised to the
*DivExponent* power. This parameter must be a number (an immediate value) and not a variable.

## Return value

Returns the converted vector, where each component has been divided by two raised to the *DivExponent* power.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Conversion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-conversion)

[XMConvertVectorFloatToUInt](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectorfloattouint)

[XMConvertVectorIntToFloat](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectorinttofloat)
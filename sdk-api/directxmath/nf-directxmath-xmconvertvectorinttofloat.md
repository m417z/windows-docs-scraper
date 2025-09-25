# XMConvertVectorIntToFloat function

## Description

Converts an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) with **int32_t** components to an
**XMVECTOR** with **float** components and applies a uniform bias.

## Parameters

### `VInt` [in]

Vector with **int32_t** components that is to be converted.

### `DivExponent` [in]

Each component of *VInt* will be converted to a **float** and then divided by two raised to the
*DivExponent* power. This parameter must be a number (an immediate value) and not a variable.

## Return value

Returns the converted vector, where each component has been divided by two raised to the *DivExponent* power.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Conversion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-conversion)

[XMConvertVectorFloatToInt](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectorfloattoint)

[XMConvertVectorUIntToFloat](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmconvertvectoruinttofloat)
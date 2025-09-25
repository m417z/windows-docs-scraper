# XMVectorExp function

## Description

Computes two raised to the power for each component.

**Note** This function is a compatibility alias for [XMVectorExp2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp2) for existing Windows 8 code. This function is deprecated for Windows 8.1. Don't use it and instead use **XMVectorExp2** or [XMVectorExpE](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexpe).

## Parameters

### `V` [in]

Vector used for the exponents of base two.

## Return value

Returns a vector whose components are two raised to the power of the corresponding component of *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)
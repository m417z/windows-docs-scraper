# XMVectorLog function

## Description

Computes the base two logarithm of each component of a vector.

**Note** This function is a compatibility alias for [XMVectorLog2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog2) for existing Windows 8 code. This function is deprecated for Windows 8.1. Don't use it and instead use **XMVectorLog2** or [XMVectorLogE](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorloge).

## Parameters

### `V` [in]

Vector for which to compute the base two logarithm.

## Return value

Returns a vector whose components are base two logarithm of the corresponding components of *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)
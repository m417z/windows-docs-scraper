# XMVectorASin function

## Description

Computes the arcsine of each component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `V` [in]

Vector for which to compute the arcsine. Each component should be between -1.0f and 1.0f.

## Return value

Returns a vector whose components are the arcsine of the corresponding components of *V*.

## Remarks

This function uses a 7-degree minimax approximation.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorASinEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorasinest)

[XMVectorSin](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsin)
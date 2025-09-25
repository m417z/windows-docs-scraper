# XMVectorASinEst function

## Description

Estimates the arcsine of each component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `V` [in]

Vector for which to compute the arcsine. Each component should be between -1.0f and 1.0f.

## Return value

Returns a vector whose components are estimates of the arcsine of the corresponding components of *V*.

## Remarks

`Est` functions offer increased performance at the expense of reduced accuracy.
`Est` functions are appropriate for non-critical calculations where accuracy can be sacrificed for speed.
The exact amount of lost accuracy and speed increase are platform dependent.

This function uses a 3-term minimax approximation.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorASin](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorasin)

[XMVectorSin](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsin)
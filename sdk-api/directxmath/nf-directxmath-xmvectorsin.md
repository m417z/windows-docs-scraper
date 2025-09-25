# XMVectorSin function

## Description

Computes the sine of each component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `V` [in]

Vector for which to compute the sine.

## Return value

Returns a vector. Each component is the sine of the corresponding component of *V*.

## Remarks

This function uses a 11-degree minimax approximation.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorASin](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorasin)

[XMVectorASinEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorasinest)

[XMVectorSinEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsinest)
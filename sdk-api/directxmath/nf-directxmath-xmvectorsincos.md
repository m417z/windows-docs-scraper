# XMVectorSinCos function

## Description

Computes the sine and cosine of each component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSin` [out]

Address of a vector, each of whose components is the sine of the corresponding component of *V*.

### `pCos` [out]

Address of a vector, each of whose components is the cosine of the corresponding component of *V*.

### `V` [in]

Vector for which to compute the sine and cosine.

## Return value

None.

## Remarks

This function uses an 11-degree minimax approximation for sine, 10-degree for cosine.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorSinCosEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsincosest)
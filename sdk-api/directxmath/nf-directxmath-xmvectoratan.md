# XMVectorATan function

## Description

Computes the arctangent of each component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `V` [in]

Vector for which to compute the arctangent.

## Return value

Returns a vector whose components are the arctangent of the corresponding components of *V*.

## Remarks

This function uses a 17-degree minimax approximation.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorATan2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectoratan2)

[XMVectorATan2Est](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectoratan2est)

[XMVectorATanEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectoratanest)

[XMVectorTan](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectortan)
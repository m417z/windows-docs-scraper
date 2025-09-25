# XMVector2LengthEst function

## Description

Estimates the length of a 2D vector.

## Parameters

### `V` [in]

2D vector.

## Return value

Returns a vector, each of whose components are estimates of the length of *V*.

## Remarks

`Est` functions offer increased performance at the expense of reduced accuracy.
`Est` functions are appropriate for non-critical calculations where accuracy can be sacrificed for speed.
The exact amount of lost accuracy and speed increase are platform dependent.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-geometric)

[XMVector2Length](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2length)

[XMVector2LengthSq](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2lengthsq)
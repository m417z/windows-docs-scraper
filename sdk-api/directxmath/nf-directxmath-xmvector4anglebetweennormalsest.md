# XMVector4AngleBetweenNormalsEst function

## Description

Estimates the radian angle between two normalized 4D vectors.

## Parameters

### `N1` [in]

Normalized 4D vector.

### `N2` [in]

Normalized 4D vector.

## Return value

Returns a vector. The estimate of the radian angle (between *N1* and *N2*) is replicated to each of the components.

## Remarks

`Est` functions offer increased performance at the expense of reduced accuracy.
`Est` functions are appropriate for non-critical calculations where accuracy can be sacrificed for speed.
The exact amount of lost accuracy and speed increase are platform dependent.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-geometric)

[XMVector4AngleBetweenNormals](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4anglebetweennormals)
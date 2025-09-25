# XMVector3NormalizeEst function

## Description

Estimates the normalized version of a 3D vector.

## Parameters

### `V` [in]

3D vector.

## Return value

Returns an estimate of the normalized version of *V*.

## Remarks

For a vector with 0 length or infinite length, this function returns a vector of QNaN.

`Est` functions offer increased performance at the expense of reduced accuracy.
`Est` functions are appropriate for non-critical calculations where accuracy can be sacrificed for speed.
The exact amount of lost accuracy and speed increase are platform dependent.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-geometric)

[XMVector3Normalize](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector3normalize)
# XMQuaternionNormalizeEst function

## Description

Estimates the normalized version of a quaternion.

## Parameters

### `Q` [in]

A quaternion for which to estimate the normalized version.

## Return value

An [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) union that is the estimate of the normalized version of a quaternion.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

This function internally calls the [XMVector4NormalizeEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4normalizeest) function.

`Est` functions offer increased performance at the expense of reduced accuracy.
`Est` functions are appropriate for non-critical calculations where accuracy can be sacrificed for speed.
The exact amount of lost accuracy and speed increase are platform dependent.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)

[XMQuaternionNormalize](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionnormalize)
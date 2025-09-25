# XMPlaneNormalizeEst function

## Description

Estimates the coefficients of a plane so that coefficients of x, y, and z form a unit normal vector.

## Parameters

### `P` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

## Return value

Returns an estimation of the normalized plane as a 4D vector whose components are the plane coefficients (A, B, C, D)
for the plane equation `Ax+By+Cz+D=0`.

## Remarks

`Est` functions offer increased performance at the expense of reduced accuracy.
`Est` functions are appropriate for non-critical calculations where accuracy can be sacrificed for speed.
The exact amount of lost accuracy and speed increase are platform dependent.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)

[XMPlaneNormalize](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmplanenormalize)
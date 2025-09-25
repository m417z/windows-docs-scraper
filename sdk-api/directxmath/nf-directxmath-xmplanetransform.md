# XMPlaneTransform function

## Description

Transforms a plane by a given matrix.

## Parameters

### `P` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

### `M` [in]

Transformation matrix.

## Return value

Returns the transformed plane as a 4D vector whose components are the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)

[XMPlaneTransformStream](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmplanetransformstream)
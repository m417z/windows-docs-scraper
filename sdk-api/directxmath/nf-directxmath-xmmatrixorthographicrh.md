# XMMatrixOrthographicRH function

## Description

Builds an orthogonal projection matrix for a right-handed coordinate system.

## Parameters

### `ViewWidth` [in]

Width of the frustum at the near clipping plane.

### `ViewHeight` [in]

Height of the frustum at the near clipping plane.

### `NearZ` [in]

Distance to the near clipping plane.

### `FarZ` [in]

Distance to the far clipping plane.

## Return value

Returns the orthogonal projection matrix.

## Remarks

For typical usage, *NearZ* is less than *FarZ*. However, if you flip these values so *FarZ* is less than *NearZ*, the result is an inverted z buffer (also known as a "reverse z buffer") which can provide increased floating-point precision.

*NearZ* and *FarZ* cannot be the same value and must be greater than 0.

All the parameters of
**XMMatrixOrthographicRH** are distances
in camera space.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)

[XMMatrixOrthographicLH](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmmatrixorthographiclh)
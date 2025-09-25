# XMMatrixPerspectiveFovRH function

## Description

Builds a right-handed perspective projection matrix based on a field of view.

## Parameters

### `FovAngleY` [in]

Top-down field-of-view angle in radians.

### `AspectRatio` [in]

Aspect ratio of view-space X:Y.

### `NearZ` [in]

Distance to the near clipping plane. Must be greater than zero.

### `FarZ` [in]

Distance to the far clipping plane. Must be greater than zero.

## Return value

Returns the perspective projection matrix.

## Remarks

For typical usage, *NearZ* is less than *FarZ*. However, if you flip these values so *FarZ* is less than *NearZ*, the result is an inverted z buffer (also known as a "reverse z buffer") which can provide increased floating-point precision.

*NearZ* and *FarZ* cannot be the same value and must be greater than 0.

The default *AspectRatio* axis is horizontal, but recalculating *FovAngleY* with *AspectRatio* controls the view scale direction: 2.0 * atan(tan(FovAngleY * 0.5) / AspectRatio).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)

[XMMatrixPerspectiveFovLH](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmmatrixperspectivefovlh)
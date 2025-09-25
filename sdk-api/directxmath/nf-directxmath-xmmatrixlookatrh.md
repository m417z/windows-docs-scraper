# XMMatrixLookAtRH function

## Description

Builds a view matrix for a right-handed coordinate system using a camera position, an up direction, and a focal point.

## Parameters

### `EyePosition` [in]

Position of the camera.

### `FocusPosition` [in]

Position of the focal point.

### `UpDirection` [in]

Up direction of the camera, typically < 0.0f, 1.0f, 0.0f >.

## Return value

Returns a view matrix that transforms a point from world space into view space.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)

[XMMatrixLookAtLH](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmmatrixlookatlh)
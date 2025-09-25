# XMMatrixAffineTransformation function

## Description

Builds an affine transformation matrix.

## Parameters

### `Scaling` [in]

Vector of scaling factors for each dimension.

### `RotationOrigin` [in]

Point identifying the center of rotation.

### `RotationQuaternion` [in]

Rotation factors.

### `Translation` [in]

Translation offsets.

## Return value

Returns the affine transformation matrix, built from the scaling, rotation, and translation information.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)
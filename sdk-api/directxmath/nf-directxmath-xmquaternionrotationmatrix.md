# XMQuaternionRotationMatrix function

## Description

Computes a rotation quaternion from a rotation matrix.

## Parameters

### `M` [in]

Rotation matrix.

## Return value

Returns the rotation quaternion.

## Remarks

This function only uses the upper 3x3 portion of the [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix). Note if the input matrix contains scales, shears, or
other non-rotation transformations in the upper 3x3 matrix, then the output of this function is ill-defined.

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)
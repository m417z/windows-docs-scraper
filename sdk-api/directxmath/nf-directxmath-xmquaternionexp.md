# XMQuaternionExp function

## Description

Computes the exponential of a given pure quaternion.

## Parameters

### `Q` [in]

Pure quaternion for which to compute the exponential. The w-component of the input quaternion is ignored in the
calculation.

## Return value

Returns the exponential of *Q*.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)
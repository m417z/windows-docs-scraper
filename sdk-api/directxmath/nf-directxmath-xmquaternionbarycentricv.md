# XMQuaternionBaryCentricV function

## Description

Returns a point in barycentric coordinates, using the specified quaternions.

## Parameters

### `Q0` [in]

First quaternion in the triangle.

### `Q1` [in]

Second quaternion in the triangle.

### `Q2` [in]

Third quaternion in the triangle.

### `F` [in]

Weighting factor. All components of this vector must be the same.

### `G` [in]

Weighting factor. All components of this vector must be the same.

## Return value

Returns a quaternion in barycentric coordinates.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

This function is identical to [XMQuaternionBaryCentric](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionbarycentric) except
that *F* and *G* are supplied using a 4D vector instead of a **float** value.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)

[XMQuaternionBaryCentric](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionbarycentric)
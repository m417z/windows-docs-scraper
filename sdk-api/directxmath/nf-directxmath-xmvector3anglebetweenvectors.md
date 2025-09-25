# XMVector3AngleBetweenVectors function

## Description

Computes the radian angle between two 3D vectors.

## Parameters

### `V1` [in]

3D vector.

### `V2` [in]

3D vector.

## Return value

Returns a vector. The radian angle between *V1* and *V2* is replicated to each of the components.

## Remarks

If V1 and V2 are normalized 3D vectors, it is faster to use [XMVector3AngleBetweenNormals](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector3anglebetweennormals).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-geometric)
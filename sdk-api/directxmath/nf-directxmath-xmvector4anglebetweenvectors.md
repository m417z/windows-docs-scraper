# XMVector4AngleBetweenVectors function

## Description

Compute the radian angle between two 4D vectors.

## Parameters

### `V1` [in]

4D vector.

### `V2` [in]

4D vector.

## Return value

Returns a vector. The radian angle between *V1* and *V2* is replicated to each of the components.

## Remarks

If V1 and V2 are normalized 4D vectors, it is faster to use [XMVector4AngleBetweenNormals](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4anglebetweennormals).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-geometric)
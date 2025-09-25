# XMVector2AngleBetweenVectors function

## Description

Computes the radian angle between two 2D vectors.

## Parameters

### `V1` [in]

2D vector.

### `V2` [in]

2D vector.

## Return value

Returns a vector. The radian angle between *V1* and *V2* is replicated to each of the components.

## Remarks

If V1 and V2 are normalized 2D vectors, it is faster to use [XMVector2AngleBetweenNormals](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2anglebetweennormals).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-geometric)

[XMVector2AngleBetweenNormals](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2anglebetweennormals)
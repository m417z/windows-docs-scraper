# XMVectorBaryCentricV function

## Description

Returns a point in Barycentric coordinates, using the specified position vectors.

## Parameters

### `Position0` [in]

First position.

### `Position1` [in]

Second position.

### `Position2` [in]

Third position.

### `F` [in]

Weighting factors for the corresponding components of the position.

### `G` [in]

Weighting factors for the corresponding components of the position.

## Return value

Returns the Barycentric coordinates.

## Remarks

This function is identical to [XMVectorBaryCentric](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmvectorbarycentric) except that independent weighting factors may supplied in *F* and *G*. As an example, you might want to calculate two sets of 2D Barycentric coordinates, using the x and y-components of the position vectors for one set of 2D positions and the z and w-components of the position vectors for the other set of 2D positions. The x and y-components of *F* and *G* would determine the weighting factors for the first set of Barycentric coordinates. Similarly, the z and w-components of *F* and *G* would determine the weighting factors for the second set of Barycentric coordinates.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorBaryCentric](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmvectorbarycentric)
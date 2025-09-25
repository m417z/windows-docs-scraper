# XMVectorCatmullRomV function

## Description

Performs a Catmull-Rom interpolation, using the specified position vectors.

## Parameters

### `Position0` [in]

First position.

### `Position1` [in]

Second position.

### `Position2` [in]

Third position.

### `Position3` [in]

Fourth position.

### `T` [in]

Interpolating control factor for the corresponding components of the position.

## Return value

Returns the results of the Catmull-Rom interpolation.

## Remarks

This function is identical to [XMVectorCatmullRom](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorcatmullrom) except that independent weighting factors may supplied in *T*. As an example, you might want to calculate two sets of Catmull-Rom interpolation, using the x and y-components of the position vectors for one set of 2D positions and the z and w-components of the position vectors for the other set of 2D positions. The x and y-components of *T* would determine the interpolation factors for the first Catmull-Rom interpolation. Similarly, the z and w-components of *T* would determine the interpolation factors for the second Catmull-Rom interpolation.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorCatmullRom](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorcatmullrom)
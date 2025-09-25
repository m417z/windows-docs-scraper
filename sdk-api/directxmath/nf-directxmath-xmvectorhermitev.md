# XMVectorHermiteV function

## Description

Performs a Hermite spline interpolation, using the specified vectors.

## Parameters

### `Position0` [in]

First position to interpolate from.

### `Tangent0` [in]

Tangent vector for the first position.

### `Position1` [in]

Second position to interpolate from.

### `Tangent1` [in]

Tangent vector for the second position.

### `T` [in]

Interpolating control factor with each component corresponding to a term of the Hermite equation.

## Return value

Returns a vector containing the interpolation.

## Remarks

This function is identical to [XMVectorHermite](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorhermite) except that independent weighting factors may be supplied in *T*. As an example, you might want to calculate two sets of Hermite spline interpolation, using the x and y-components of the position vectors for one set of 2D positions and the z and w-components of the position vectors for the other set of 2D positions. The x and y-components of *T* would determine the interpolation factors for the first Hermite spline interpolation. Similarly, the z and w-components of *T* would determine the interpolation factors for the second Hermite spline interpolation.

The following pseudocode demonstrates the operation of the function:

``` syntax

Result[i] = (2*(T.x)^3 - 3*(T.x)^2 + 1) * Position0.[i]
                  + ((T.y)^3 - 2*(T.y)^2 + (T.y)) * Tangent0.[i]
                  + (-2*(T.z)^3 + 3*(T.z)^2) * Position1.[i]
                  + ((T.w)^3 - *(T.w)^2) * Tangent1.[i]

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorHermite](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorhermite)
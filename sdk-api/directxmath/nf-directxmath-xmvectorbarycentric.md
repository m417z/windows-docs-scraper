# XMVectorBaryCentric function

## Description

Returns a point in Barycentric coordinates, using the specified position vectors.

## Parameters

### `Position0` [in]

First position.

### `Position1` [in]

Second position.

### `Position2` [in]

Third position.

### `f` [in]

Weighting factor. See the remarks.

### `g` [in]

Weighting factor. See the remarks.

## Return value

Returns the Barycentric coordinates.

## Remarks

This function provides a way to understand points in and around a triangle, independent of where the triangle is located. This function returns the resulting point by using the following equation: *Position0*> + *f*>(*Position1*-*Position0*>) + *g*>(*Position2*-*Position0*>).

Any point in the plane *Position0*>*Position1*>*Position2*> can be represented by the Barycentric coordinate (*f*>,*g*>), where *f*> controls how much *Position1*> gets weighted into the result, and *g*> controls how much *Position2*> gets weighted into the result. Lastly, 1-*f*>-*g*> controls how much *Position0*> gets weighted into the result.

Note the following relations.

* If (*f*>=0 && *g*>=0 && 1-*f*-*g*>=0), the point is inside the triangle *Position0*>*Position1*>*Position2*>.
* If (*f*==0 && *g*>=0 && 1-*f*-*g*>=0), the point is on the line *Position0*>*Position2*>.
* If (*f*>=0 && *g*==0 && 1-*f*-g>=0), the point is on the line *Position0*>*Position1*>.
* If (*f*>=0 && *g*>=0 && 1-*f*-*g*==0), the point is on the line *Position1*>*Position2*>.

Barycentric coordinates are a form of general coordinates. In this context, using Barycentric coordinates represents a change in coordinate systems. What holds true for Cartesian coordinates holds true for Barycentric coordinates.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorBaryCentricV](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorbarycentricv)
## Description

The **SetWorldTransform** function sets a two-dimensional linear transformation between world space and page space for the specified device context. This transformation can be used to scale, rotate, shear, or translate graphics output.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpxf` [in]

A pointer to an [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure that contains the transformation data.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Below is the transformation matrix (note that the digits in the element notation are 1-based column number followed by 1-based row number, rather than the reverse).

``` syntax
| eM11 eM21 eDx |
| eM12 eM22 eDy |
| 0    0    1   |

```

So for any coordinates (x, y) in world space, the transformed coordinates in page space (x', y') can be determined in the way shown below.

``` syntax
| x' |   | eM11 eM21 eDx |   | x |
| y' | = | eM12 eM22 eDy | . | y |
| 1  |   | 0    0    1   |   | 1 |

x' = x * eM11 + y * eM21 + eDx
y' = x * eM12 + y * eM22 + eDy

```

This function uses logical units.

The world transformation is usually used to scale or rotate logical images in a device-independent way.

The default world transformation is the identity matrix with zero offset.

The **SetWorldTransform** function will fail unless the graphics mode for the given device context has been set to GM_ADVANCED by previously calling the [SetGraphicsMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode) function. Likewise, it will not be possible to reset the graphics mode for the device context to the default GM_COMPATIBLE mode, unless the world transformation has first been reset to the default identity transformation by calling **SetWorldTransform** or [ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform).

#### Examples

For an example, see [Using Coordinate Spaces and Transformations](https://learn.microsoft.com/windows/desktop/gdi/using-coordinate-spaces-and-transformations).

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getworldtransform)

[ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform)

[SetGraphicsMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode)

[SetMapMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmapmode)

[SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex)

[SetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportorgex)

[SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex)

[SetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindoworgex)

[XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform)
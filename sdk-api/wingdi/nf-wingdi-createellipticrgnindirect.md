# CreateEllipticRgnIndirect function

## Description

The **CreateEllipticRgnIndirect** function creates an elliptical region.

## Parameters

### `lprect` [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the coordinates of the upper-left and lower-right corners of the bounding rectangle of the ellipse in logical units.

## Return value

If the function succeeds, the return value is the handle to the region.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the **HRGN** object, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

A bounding rectangle defines the size, shape, and orientation of the region: The long sides of the rectangle define the length of the ellipse's major axis; the short sides define the length of the ellipse's minor axis; and the center of the rectangle defines the intersection of the major and minor axes.

## See also

[CreateEllipticRegn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createellipticrgn)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)
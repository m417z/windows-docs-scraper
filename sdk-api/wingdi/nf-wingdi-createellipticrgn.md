# CreateEllipticRgn function

## Description

The **CreateEllipticRgn** function creates an elliptical region.

## Parameters

### `x1` [in]

Specifies the x-coordinate in logical units, of the upper-left corner of the bounding rectangle of the ellipse.

### `y1` [in]

Specifies the y-coordinate in logical units, of the upper-left corner of the bounding rectangle of the ellipse.

### `x2` [in]

Specifies the x-coordinate in logical units, of the lower-right corner of the bounding rectangle of the ellipse.

### `y2` [in]

Specifies the y-coordinate in logical units, of the lower-right corner of the bounding rectangle of the ellipse.

## Return value

If the function succeeds, the return value is the handle to the region.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the HRGN object, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

A bounding rectangle defines the size, shape, and orientation of the region: The long sides of the rectangle define the length of the ellipse's major axis; the short sides define the length of the ellipse's minor axis; and the center of the rectangle defines the intersection of the major and minor axes.

## See also

[CreateEllipticRegnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createellipticrgnindirect)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)
# SetBrushOrgEx function

## Description

The **SetBrushOrgEx** function sets the brush origin that GDI assigns to the next brush an application selects into the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate, in device units, of the new brush origin. If this value is greater than the brush width, its value is reduced using the modulus operator (*nXOrg* **mod** brush width).

### `y` [in]

The y-coordinate, in device units, of the new brush origin. If this value is greater than the brush height, its value is reduced using the modulus operator (*nYOrg* **mod** brush height).

### `lppt` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the previous brush origin.

This parameter can be **NULL** if the previous brush origin is not required.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

A brush is a bitmap that the system uses to paint the interiors of filled shapes.

The brush origin is a pair of coordinates specifying the location of one pixel in the bitmap. The default brush origin coordinates are (0,0). For horizontal coordinates, the value 0 corresponds to the leftmost column of pixels; the width corresponds to the rightmost column. For vertical coordinates, the value 0 corresponds to the uppermost row of pixels; the height corresponds to the lowermost row.

The system automatically tracks the origin of all window-managed device contexts and adjusts their brushes as necessary to maintain an alignment of patterns on the surface. The brush origin that is set with this call is relative to the upper-left corner of the client area.

An application should call **SetBrushOrgEx** after setting the bitmap stretching mode to HALFTONE by using [SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode). This must be done to avoid brush misalignment.

The system automatically tracks the origin of all window-managed device contexts and adjusts their brushes as necessary to maintain an alignment of patterns on the surface.

## See also

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[GetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbrushorgex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)

[UnrealizeObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-unrealizeobject)
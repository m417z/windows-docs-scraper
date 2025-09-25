# GetBrushOrgEx function

## Description

The **GetBrushOrgEx** function retrieves the current brush origin for the specified device context. This function replaces the **GetBrushOrg** function.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lppt` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the brush origin, in device coordinates.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

A brush is a bitmap that the system uses to paint the interiors of filled shapes.

The brush origin is a set of coordinates with values between 0 and 7, specifying the location of one pixel in the bitmap. The default brush origin coordinates are (0,0). For horizontal coordinates, the value 0 corresponds to the leftmost column of pixels; the value 7 corresponds to the rightmost column. For vertical coordinates, the value 0 corresponds to the uppermost row of pixels; the value 7 corresponds to the lowermost row. When the system positions the brush at the start of any painting operation, it maps the origin of the brush to the location in the window's client area specified by the brush origin. For example, if the origin is set to (2,3), the system maps the origin of the brush (0,0) to the location (2,3) on the window's client area.

If an application uses a brush to fill the backgrounds of both a parent and a child window with matching colors, it may be necessary to set the brush origin after painting the parent window but before painting the child window.

The system automatically tracks the origin of all window-managed device contexts and adjusts their brushes as necessary to maintain an alignment of patterns on the surface.

## See also

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex)

[UnrealizeObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-unrealizeobject)
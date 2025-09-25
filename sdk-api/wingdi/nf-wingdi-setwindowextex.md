# SetWindowExtEx function

## Description

The **SetWindowExtEx** function sets the horizontal and vertical extents of the window for a device context by using the specified values.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The window's horizontal extent in logical units.

### `y` [in]

The window's vertical extent in logical units.

### `lpsz` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the previous window extents, in logical units. If *lpSize* is **NULL**, this parameter is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The *window* refers to the logical coordinate system of the page space. The *extent* is the maximum value of an axis. This function sets the maximum values for the horizontal and vertical axes of the window (in logical coordinates). When mapping between page space and device space, [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex) and **SetWindowExtEx** determine the scaling factor between the window and the viewport. For more information, see [Transformation of Coordinate Spaces](https://learn.microsoft.com/windows/desktop/gdi/transformation-of-coordinate-spaces).

When the following mapping modes are set, calls to the **SetWindowExtEx** and [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex) functions are ignored:

* MM_HIENGLISH
* MM_HIMETRIC
* MM_LOENGLISH
* MM_LOMETRIC
* MM_TEXT
* MM_TWIPS

When MM_ISOTROPIC mode is set, an application must call the **SetWindowExtEx** function before calling [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex). Note that for the MM_ISOTROPIC mode, certain portions of a nonsquare screen may not be available for display because the logical units on both axes represent equal physical distances.

#### Examples

For an example, see [Invalidating the Client Area](https://learn.microsoft.com/windows/desktop/gdi/invalidating-the-client-area).

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwindowextex)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)

[SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex)
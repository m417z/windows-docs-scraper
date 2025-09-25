# UnrealizeObject function

## Description

The **UnrealizeObject** function resets the origin of a brush or resets a logical palette. If the *hgdiobj* parameter is a handle to a brush, **UnrealizeObject** directs the system to reset the origin of the brush the next time it is selected. If the *hgdiobj* parameter is a handle to a logical palette, **UnrealizeObject** directs the system to realize the palette as though it had not previously been realized. The next time the application calls the [RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette) function for the specified palette, the system completely remaps the logical palette to the system palette.

## Parameters

### `hgdiobj` [in]

A handle to the logical palette to be reset.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **UnrealizeObject** function should not be used with stock objects. For example, the default palette, obtained by calling [GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject) (DEFAULT_PALETTE), is a stock object.

A palette identified by *hgdiobj* can be the currently selected palette of a device context.

If *hgdiobj* is a brush, **UnrealizeObject** does nothing, and the function returns **TRUE**. Use [SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex) to set the origin of a brush.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject)

[RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette)

[SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex)
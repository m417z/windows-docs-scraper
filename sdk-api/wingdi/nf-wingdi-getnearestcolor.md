# GetNearestColor function

## Description

The **GetNearestColor** function retrieves a color value identifying a color from the system palette that will be displayed when the specified color value is used.

## Parameters

### `hdc` [in]

A handle to the device context.

### `color` [in]

A color value that identifies a requested color. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

If the function succeeds, the return value identifies a color from the system palette that corresponds to the given color value.

If the function fails, the return value is CLR_INVALID.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetNearestPaletteIndex](https://learn.microsoft.com/previous-versions/dd144903(v=vs.85))

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)
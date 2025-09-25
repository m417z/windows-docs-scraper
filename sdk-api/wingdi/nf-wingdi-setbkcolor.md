# SetBkColor function

## Description

The **SetBkColor** function sets the current background color to the specified color value, or to the nearest physical color if the device cannot represent the specified color value.

## Parameters

### `hdc` [in]

A handle to the device context.

### `color` [in]

The new background color. To make a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

If the function succeeds, the return value specifies the previous background color as a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value.

If the function fails, the return value is CLR_INVALID.

## Remarks

This function fills the gaps between styled lines drawn using a pen created by the [CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen) function; it does not fill the gaps between styled lines drawn using a pen created by the [ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen) function. The **SetBkColor** function also sets the background colors for [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) and [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta).

If the background mode is OPAQUE, the background color is used to fill gaps between styled lines, gaps between hatched lines in brushes, and character cells. The background color is also used when converting bitmaps from color to monochrome and vice versa.

#### Examples

For an example, see "Example of Owner-Drawn Menu Items" in [Using Menus](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[GetBKColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbkcolor)

[GetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbkmode)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[SetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkmode)
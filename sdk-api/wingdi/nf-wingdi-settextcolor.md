# SetTextColor function

## Description

The **SetTextColor** function sets the text color for the specified device context to the specified color.

## Parameters

### `hdc` [in]

A handle to the device context.

### `color` [in]

The color of the text.

## Return value

If the function succeeds, the return value is a color reference for the previous text color as a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value.

If the function fails, the return value is CLR_INVALID.

## Remarks

The text color is used to draw the face of each character written by the [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) and [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) functions. The text color is also used in converting bitmaps from color to monochrome and vice versa.

#### Examples

For an example, see "Setting Fonts for Menu-Item Text Strings" in [Using Menus](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

[BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcolor)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor)

[StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)
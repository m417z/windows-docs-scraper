# GetTextColor function

## Description

The **GetTextColor** function retrieves the current text color for the specified device context.

## Parameters

### `hdc` [in]

Handle to the device context.

## Return value

If the function succeeds, the return value is the current text color as a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value.

If the function fails, the return value is CLR_INVALID. No extended error information is available.

## Remarks

The text color defines the foreground color of characters drawn by using the [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) or [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[SetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcolor)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)
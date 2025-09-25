# SetTextJustification function

## Description

The **SetTextJustification** function specifies the amount of space the system should add to the break characters in a string of text. The space is added when an application calls the [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) or [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) functions.

## Parameters

### `hdc` [in]

A handle to the device context.

### `extra` [in]

The total extra space, in logical units, to be added to the line of text. If the current mapping mode is not MM_TEXT, the value identified by the *nBreakExtra* parameter is transformed and rounded to the nearest pixel.

### `count` [in]

The number of break characters in the line.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The break character is usually the space character (ASCII 32), but it may be defined by a font as some other character. The [GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics) function can be used to retrieve a font's break character.

The [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) function distributes the specified extra space evenly among the break characters in the line.

The [GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a) function is always used with the **SetTextJustification** function. Sometimes the **GetTextExtentPoint32** function takes justification into account when computing the width of a specified line before justification, and sometimes it does not. For more details on this, see **GetTextExtentPoint32**. This width must be known before an appropriate *nBreakExtra* value can be computed.

**SetTextJustification** can be used to justify a line that contains multiple strings in different fonts. In this case, each string must be justified separately.

Because rounding errors can occur during justification, the system keeps a running error term that defines the current error value. When justifying a line that contains multiple runs, [GetTextExtentPoint](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointa) automatically uses this error term when it computes the extent of the next run, allowing [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) to blend the error into the new run. After each line has been justified, this error term must be cleared to prevent it from being incorporated into the next line. The term can be cleared by calling **SetTextJustification** with *nBreakExtra* set to zero.

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)
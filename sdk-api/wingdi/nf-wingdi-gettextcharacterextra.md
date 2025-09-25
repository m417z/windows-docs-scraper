# GetTextCharacterExtra function

## Description

The **GetTextCharacterExtra** function retrieves the current intercharacter spacing for the specified device context.

## Parameters

### `hdc` [in]

Handle to the device context.

## Return value

If the function succeeds, the return value is the current intercharacter spacing, in logical coordinates.

If the function fails, the return value is 0x8000000.

## Remarks

The intercharacter spacing defines the extra space, in logical units along the base line, that the [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) or [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) functions add to each character as a line is written. The spacing is used to expand lines of text.

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[SetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcharacterextra)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)
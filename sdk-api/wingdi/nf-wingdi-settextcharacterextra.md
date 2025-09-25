# SetTextCharacterExtra function

## Description

The **SetTextCharacterExtra** function sets the intercharacter spacing. Intercharacter spacing is added to each character, including break characters, when the system writes a line of text.

## Parameters

### `hdc` [in]

A handle to the device context.

### `extra` [in]

The amount of extra space, in logical units, to be added to each character. If the current mapping mode is not MM_TEXT, the *nCharExtra* parameter is transformed and rounded to the nearest pixel.

## Return value

If the function succeeds, the return value is the previous intercharacter spacing.

If the function fails, the return value is 0x80000000.

## Remarks

This function is supported mainly for compatibility with existing applications. New applications should generally avoid calling this function, because it is incompatible with complex scripts (scripts that require text shaping; Arabic script is an example of this).

The recommended approach is that instead of calling this function and then [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta), applications should call [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) and use its *lpDx* parameter to supply widths.

## See also

[DrawText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcharacterextra)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)
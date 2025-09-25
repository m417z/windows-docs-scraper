# GetTextExtentPoint32W function

## Description

The **GetTextExtentPoint32** function computes the width and height of the specified string of text.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpString` [in]

A pointer to a buffer that specifies the text string. The string does not need to be null-terminated, because the *c* parameter specifies the length of the string.

### `c` [in]

The [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) pointed to by *lpString*.

### `psizl` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the dimensions of the string, in logical units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **GetTextExtentPoint32** function uses the currently selected font to compute the dimensions of the string. The width and height, in logical units, are computed without considering any clipping.

Because some devices kern characters, the sum of the extents of the characters in a string may not be equal to the extent of the string.

The calculated string width takes into account the intercharacter spacing set by the [SetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcharacterextra) function and the justification set by [SetTextJustification](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextjustification). This is true for both displaying on a screen and for printing. However, if *lpDx* is set in [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta), **GetTextExtentPoint32** does not take into account either intercharacter spacing or justification. In addition, for EMF, the print result always takes both intercharacter spacing and justification into account.

When dealing with text displayed on a screen, the calculated string width takes into account the intercharacter spacing set by the [SetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcharacterextra) function and the justification set by [SetTextJustification](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextjustification). However, if *lpDx* is set in [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta), **GetTextExtentPoint32** does not take into account either intercharacter spacing or justification. However, when printing with EMF:

* The print result ignores intercharacter spacing, although **GetTextExtentPoint32** takes it into account.
* The print result takes justification into account, although **GetTextExtentPoint32** ignores it.

When this function returns the text extent, it assumes that the text is horizontal, that is, that the escapement is always 0. This is true for both the horizontal and vertical measurements of the text. Even if you use a font that specifies a nonzero escapement, this function doesn't use the angle while it computes the text extent. The app must convert it explicitly. However, when the graphics mode is set to [GM_ADVANCED](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode) and the character orientation is 90 degrees from the print orientation, the values that this function return do not follow this rule. When the character orientation and the print orientation match for a given string, this function returns the dimensions of the string in the [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure as { cx : 116, cy : 18 }. When the character orientation and the print orientation are 90 degrees apart for the same string, this function returns the dimensions of the string in the **SIZE** structure as { cx : 18, cy : 116 }.

**GetTextExtentPoint32** doesn't consider "\n" (new line) or "\r\n" (carriage return and new line) characters when it computes the height of a text string.

#### Examples

For an example, see [Drawing Text from Different Fonts on the Same Line](https://learn.microsoft.com/windows/desktop/gdi/drawing-text-from-different-fonts-on-the-same-line).

> [!NOTE]
> The wingdi.h header defines GetTextExtentPoint32 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)

[SetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcharacterextra)

[SetTextJustification](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextjustification)
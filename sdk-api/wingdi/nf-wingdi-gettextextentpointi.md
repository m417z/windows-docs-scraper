# GetTextExtentPointI function

## Description

The **GetTextExtentPointI** function computes the width and height of the specified array of glyph indices.

## Parameters

### `hdc` [in]

Handle to the device context.

### `pgiIn` [in]

Pointer to array of glyph indices.

### `cgi` [in]

Specifies the number of glyph indices.

### `psize` [out]

Pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the dimensions of the string, in logical units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **GetTextExtentPointI** function uses the currently selected font to compute the dimensions of the array of glyph indices. The width and height, in logical units, are computed without considering any clipping.

When this function returns the text extent, it assumes that the text is horizontal, that is, that the escapement is always 0. This is true for both the horizontal and vertical measurements of the text. Even if you use a font that specifies a nonzero escapement, this function doesn't use the angle while it computes the text extent. The app must convert it explicitly. However, when the graphics mode is set to [GM_ADVANCED](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode) and the character orientation is 90 degrees from the print orientation, the values that this function return do not follow this rule. When the character orientation and the print orientation match for a given string, this function returns the dimensions of the string in the [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure as { cx : 116, cy : 18 }. When the character orientation and the print orientation are 90 degrees apart for the same string, this function returns the dimensions of the string in the **SIZE** structure as { cx : 18, cy : 116 }.

Because some devices kern characters, the sum of the extents of the individual glyph indices may not be equal to the extent of the entire array of glyph indices.

The calculated string width takes into account the intercharacter spacing set by the [SetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcharacterextra) function.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointa)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)

[SetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcharacterextra)
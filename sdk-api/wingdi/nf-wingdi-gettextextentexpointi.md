# GetTextExtentExPointI function

## Description

The **GetTextExtentExPointI** function retrieves the number of characters in a specified string that will fit within a specified space and fills an array with the text extent for each of those characters. (A text extent is the distance between the beginning of the space and a character that will fit in the space.) This information is useful for word-wrapping calculations.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpwszString` [in]

A pointer to an array of glyph indices for which extents are to be retrieved.

### `cwchString` [in]

The number of glyphs in the array pointed to by the *pgiIn* parameter.

### `nMaxExtent` [in]

The maximum allowable width, in logical units, of the formatted string.

### `lpnFit` [out]

A pointer to an integer that receives a count of the maximum number of characters that will fit in the space specified by the *nMaxExtent* parameter. When the *lpnFit* parameter is **NULL**, the *nMaxExtent* parameter is ignored.

### `lpnDx` [out]

A pointer to an array of integers that receives partial glyph extents. Each element in the array gives the distance, in logical units, between the beginning of the glyph indices array and one of the glyphs that fits in the space specified by the *nMaxExtent* parameter. Although this array should have at least as many elements as glyph indices specified by the *cgi* parameter, the function fills the array with extents only for as many glyph indices as are specified by the *lpnFit* parameter. If *lpnFit* is **NULL**, the function does not compute partial string widths.

### `lpSize` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the dimensions of the glyph indices array, in logical units. This value cannot be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If both the *lpnFit* and *alpDx* parameters are **NULL**, calling the **GetTextExtentExPointI** function is equivalent to calling the [GetTextExtentPointI](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointi) function.

When this function returns the text extent, it assumes that the text is horizontal, that is, that the escapement is always 0. This is true for both the horizontal and vertical measurements of the text. Even if you use a font that specifies a nonzero escapement, this function doesn't use the angle while it computes the text extent. The app must convert it explicitly. However, when the graphics mode is set to [GM_ADVANCED](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode) and the character orientation is 90 degrees from the print orientation, the values that this function return do not follow this rule. When the character orientation and the print orientation match for a given string, this function returns the dimensions of the string in the [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure as { cx : 116, cy : 18 }. When the character orientation and the print orientation are 90 degrees apart for the same string, this function returns the dimensions of the string in the **SIZE** structure as { cx : 18, cy : 116 }.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointa)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)
# GetTextExtentExPointA function

## Description

The **GetTextExtentExPoint** function retrieves the number of characters in a specified string that will fit within a specified space and fills an array with the text extent for each of those characters. (A text extent is the distance between the beginning of the space and a character that will fit in the space.) This information is useful for word-wrapping calculations.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpszString` [in]

A pointer to the null-terminated string for which extents are to be retrieved.

### `cchString` [in]

The number of characters in the string pointed to by the *lpszStr* parameter. For an ANSI call it specifies the string length in bytes and for a Unicode it specifies the string length in WORDs. Note that for the ANSI function, characters in SBCS code pages take one byte each, while most characters in DBCS code pages take two bytes; for the Unicode function, most currently defined Unicode characters (those in the Basic Multilingual Plane (BMP)) are one WORD while Unicode surrogates are two WORDs.

### `nMaxExtent` [in]

The maximum allowable width, in logical units, of the formatted string.

### `lpnFit` [out]

A pointer to an integer that receives a count of the maximum number of characters that will fit in the space specified by the *nMaxExtent* parameter. When the *lpnFit* parameter is **NULL**, the *nMaxExtent* parameter is ignored.

### `lpnDx` [out]

A pointer to an array of integers that receives partial string extents. Each element in the array gives the distance, in logical units, between the beginning of the string and one of the characters that fits in the space specified by the *nMaxExtent* parameter. This array must have at least as many elements as characters specified by the *cchString* parameter because the entire array is used internally. The function fills the array with valid extents for as many characters as are specified by the *lpnFit* parameter. Any values in the rest of the array should be ignored. If *alpDx* is **NULL**, the function does not compute partial string widths.

For complex scripts, where a sequence of characters may be represented by any number of glyphs, the values in the *alpDx* array up to the number specified by the *lpnFit* parameter match one-to-one with code points. Again, you should ignore the rest of the values in the *alpDx* array.

### `lpSize` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the dimensions of the string, in logical units. This parameter cannot be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If both the *lpnFit* and *alpDx* parameters are **NULL**, calling the **GetTextExtentExPoint** function is equivalent to calling the [GetTextExtentPoint](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointa) function.

For the ANSI version of **GetTextExtentExPoint**, the *lpDx* array has the same number of INT values as there are bytes in *lpString*. The INT values that correspond to the two bytes of a DBCS character are each the extent of the entire composite character.

Note, the *alpDx* values for **GetTextExtentExPoint** are not the same as the *lpDx* values for [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta). To use the *alpDx* values in *lpDx*, you must first process them.

When this function returns the text extent, it assumes that the text is horizontal, that is, that the escapement is always 0. This is true for both the horizontal and vertical measurements of the text. Even if you use a font that specifies a nonzero escapement, this function doesn't use the angle while it computes the text extent. The app must convert it explicitly. However, when the graphics mode is set to [GM_ADVANCED](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode) and the character orientation is 90 degrees from the print orientation, the values that this function return do not follow this rule. When the character orientation and the print orientation match for a given string, this function returns the dimensions of the string in the [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure as { cx : 116, cy : 18 }. When the character orientation and the print orientation are 90 degrees apart for the same string, this function returns the dimensions of the string in the **SIZE** structure as { cx : 18, cy : 116 }.

This function returns the extent of each successive character in a string. When these are rounded to logical units, you get different results than what is returned from the [GetCharWidth](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidtha), which returns the width of each individual character rounded to logical units.

> [!NOTE]
> The wingdi.h header defines GetTextExtentExPoint as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpointa)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)
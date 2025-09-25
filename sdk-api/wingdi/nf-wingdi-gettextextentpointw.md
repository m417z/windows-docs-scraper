# GetTextExtentPointW function

## Description

The **GetTextExtentPoint** function computes the width and height of the specified string of text.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should call the [GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a) function, which provides more accurate results.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpString` [in]

A pointer to the string that specifies the text. The string does not need to be zero-terminated, since *cbString* specifies the length of the string.

### `c` [in]

The [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) pointed to by *lpString*.

### `lpsz` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the dimensions of the string, in logical units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **GetTextExtentPoint** function uses the currently selected font to compute the dimensions of the string. The width and height, in logical units, are computed without considering any clipping. Also, this function assumes that the text is horizontal, that is, that the escapement is always 0. This is true for both the horizontal and vertical measurements of the text. Even if using a font specifying a nonzero escapement, this function will not use the angle while computing the text extent. The application must convert it explicitly.

Because some devices kern characters, the sum of the extents of the characters in a string may not be equal to the extent of the string.

The calculated string width takes into account the intercharacter spacing set by the [SetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcharacterextra) function.

> [!NOTE]
> The wingdi.h header defines GetTextExtentPoint as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)

[SetTextCharacterExtra](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcharacterextra)
# GetGlyphIndicesW function

## Description

The **GetGlyphIndices** function translates a string into an array of glyph indices. The function can be used to determine whether a glyph exists in a font.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpstr` [in]

A pointer to the string to be converted.

### `c` [in]

The length of both the [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) pointed to by *lpstr* and the size (in WORDs) of the buffer pointed to by *pgi*.

### `pgi` [out]

This buffer must be of dimension c. On successful return, contains an array of glyph indices corresponding to the characters in the string.

### `fl` [in]

Specifies how glyphs should be handled if they are not supported. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **GGI_MARK_NONEXISTING_GLYPHS** | Marks unsupported glyphs with the hexadecimal value 0xffff. |

## Return value

If the function succeeds, it returns the number of bytes (for the ANSI function) or WORDs (for the Unicode function) converted.

If the function fails, the return value is GDI_ERROR.

## Remarks

This function attempts to identify a single-glyph representation for each character in the string pointed to by *lpstr*. While this is useful for certain low-level purposes (such as manipulating font files), higher-level applications that wish to map a string to glyphs will typically wish to use the [Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe) functions.

> [!NOTE]
> The wingdi.h header defines GetGlyphIndices as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetFontUnicodeRanges](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontunicoderanges)
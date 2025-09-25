# GetFontUnicodeRanges function

## Description

The **GetFontUnicodeRanges** function returns information about which Unicode characters are supported by a font. The information is returned as a [GLYPHSET](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphset) structure.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpgs` [out]

A pointer to a [GLYPHSET](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphset) structure that receives the glyph set information. If this parameter is **NULL**, the function returns the size of the **GLYPHSET** structure required to store the information.

## Return value

If the function succeeds, it returns number of bytes written to the GLYPHSET structure or, if the *lpgs* parameter is **NULL**, it returns the size of the GLYPHSET structure required to store the information.

If the function fails, it returns zero. No extended error information is available.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GLYPHSET](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphset)
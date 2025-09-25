# GetFontLanguageInfo function

## Description

The **GetFontLanguageInfo** function returns information about the currently selected font for the specified display context. Applications typically use this information and the [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) function to prepare a character string for display.

## Parameters

### `hdc` [in]

Handle to a display device context.

## Return value

The return value identifies characteristics of the currently selected font. The function returns 0 if the font is "normalized" and can be treated as a simple Latin font; it returns GCP_ERROR if an error occurs. Otherwise, the function returns a combination of the following values.

| Value | Meaning |
| --- | --- |
| GCP_DBCS | The character set is DBCS. |
| GCP_DIACRITIC | The font/language contains diacritic glyphs. |
| FLI_GLYPHS | The font contains extra glyphs not normally accessible using the code page. Use [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) to access the glyphs. This value is for information only and is not intended to be passed to **GetCharacterPlacement**. |
| GCP_GLYPHSHAPE | The font/language contains multiple glyphs per code point or per code point combination (supports shaping and/or ligation), and the font contains advanced glyph tables to provide extra glyphs for the extra shapes. If this value is specified, the **lpGlyphs** array must be used with the [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) function and the ETO_GLYPHINDEX value must be passed to the [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function when the string is drawn. |
| GCP_KASHIDA | The font/ language permits Kashidas. |
| GCP_LIGATE | The font/language contains ligation glyphs which can be substituted for specific character combinations. |
| GCP_USEKERNING | The font contains a kerning table which can be used to provide better spacing between the characters and glyphs. |
| GCP_REORDER | The language requires reordering for display for example, Hebrew or Arabic. |

The return value, when masked with FLI_MASK, can be passed directly to the [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) function.

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa)
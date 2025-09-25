# CreateFontIndirectExW function

## Description

The **CreateFontIndirectEx** function specifies a logical font that has the characteristics in the specified structure. The font can subsequently be selected as the current font for any device context.

## Parameters

### `unnamedParam1` [in]

Pointer to an [ENUMLOGFONTEXDV](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumlogfontexdva) structure that defines the characteristics of a multiple master font.

Note, this function ignores the **elfDesignVector** member in [ENUMLOGFONTEXDV](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumlogfontexdva).

## Return value

If the function succeeds, the return value is the handle to the new [ENUMLOGFONTEXDV](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumlogfontexdva) structure.

If the function fails, the return value is zero. No extended error information is available.

## Remarks

The **CreateFontIndirectEx** function creates a logical font with the characteristics specified in the [ENUMLOGFONTEXDV](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumlogfontexdva) structure. When this font is selected by using the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function, GDI's font mapper attempts to match the logical font with an existing physical font. If it fails to find an exact match, it provides an alternative whose characteristics match as many of the requested characteristics as possible.

When you no longer need the font, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

The font mapper for [CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta), [CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta), and **CreateFontIndirectEx** recognizes both the English and the localized typeface name, regardless of locale.

> [!NOTE]
> The wingdi.h header defines CreateFontIndirectEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta)

[CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta)

[ENUMLOGFONTEXDV](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumlogfontexdva)

[EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa)

[EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa)

[EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)
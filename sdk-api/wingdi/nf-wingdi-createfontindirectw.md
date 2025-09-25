# CreateFontIndirectW function

## Description

The **CreateFontIndirect** function creates a logical font that has the specified characteristics. The font can subsequently be selected as the current font for any device context.

## Parameters

### `lplf` [in]

A pointer to a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that defines the characteristics of the logical font.

## Return value

If the function succeeds, the return value is a handle to a logical font.

If the function fails, the return value is **NULL**.

## Remarks

The **CreateFontIndirect** function creates a logical font with the characteristics specified in the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure. When this font is selected by using the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function, GDI's font mapper attempts to match the logical font with an existing physical font. If it fails to find an exact match, it provides an alternative whose characteristics match as many of the requested characteristics as possible.

To get the appropriate font on different language versions of the OS, call [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) with the desired font characteristics in the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure, retrieve the appropriate typeface name, and create the font using [CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta) or **CreateFontIndirect**.

When you no longer need the font, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

The fonts for many East Asian languages have two typeface names: an English name and a localized name. [CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta) and **CreateFontIndirect** take the localized typeface name only on a system locale that matches the language, while they take the English typeface name on all other system locales. The best method is to try one name and, on failure, try the other. Note that [EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa), [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa), and [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) return the English typeface name if the system locale does not match the language of the font.

The font mapper for [CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta), **CreateFontIndirect**, and [CreateFontIndirectEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirectexa) recognizes both the English and the localized typeface name, regardless of locale.

#### Examples

For an example, see [Creating a Logical Font](https://learn.microsoft.com/windows/desktop/gdi/creating-a-logical-font).

> [!NOTE]
> The wingdi.h header defines CreateFontIndirect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta)

[CreateFontIndirectEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirectexa)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa)

[EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa)

[EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)
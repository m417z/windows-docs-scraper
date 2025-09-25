# ENUMLOGFONTEXDVW structure

## Description

The **ENUMLOGFONTEXDV** structure contains the information used to create a font.

## Members

### `elfEnumLogfontEx`

An [ENUMLOGFONTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumlogfontexa) structure that contains information about the logical attributes of the font.

### `elfDesignVector`

A [DESIGNVECTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-designvector) structure. This is zero-filled unless the font described is a multiple master OpenType font.

## Remarks

The actual size of **ENUMLOGFONTEXDV** depends on that of [DESIGNVECTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-designvector), which, in turn depends on its **dvNumAxes** member.

The [EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa), [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa), and [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) functions have been modified to return pointers to [ENUMTEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumtextmetrica) and **ENUMLOGFONTEXDV** to the callback function.

> [!NOTE]
> The wingdi.h header defines ENUMLOGFONTEXDV as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFontIndirectEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirectexa)

[DESIGNVECTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-designvector)

[ENUMTEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumtextmetrica)

[EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa)

[EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa)

[EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)
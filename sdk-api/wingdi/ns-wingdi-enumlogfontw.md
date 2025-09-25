# ENUMLOGFONTW structure

## Description

The **ENUMLOGFONT** structure defines the attributes of a font, the complete name of a font, and the style of a font.

## Members

### `elfLogFont`

A [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that defines the attributes of a font.

### `elfFullName`

A unique name for the font. For example, ABCD Font Company TrueType Bold Italic Sans Serif.

### `elfStyle`

The style of the font. For example, Bold Italic.

## See also

[EnumFontFamProc](https://learn.microsoft.com/previous-versions/dd162621(v=vs.85))

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

## Remarks

> [!NOTE]
> The wingdi.h header defines ENUMLOGFONT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
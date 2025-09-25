# ENUMLOGFONTEXW structure

## Description

The **ENUMLOGFONTEX** structure contains information about an enumerated font.

## Members

### `elfLogFont`

A [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that contains values defining the font attributes.

### `elfFullName`

The unique name of the font. For example, ABC Font Company TrueType Bold Italic Sans Serif.

### `elfStyle`

The style of the font. For example, Bold Italic.

### `elfScript`

The script, that is, the character set, of the font. For example, Cyrillic.

## See also

[EnumFontFamExProc](https://learn.microsoft.com/previous-versions/dd162618(v=vs.85))

[EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

## Remarks

> [!NOTE]
> The wingdi.h header defines ENUMLOGFONTEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
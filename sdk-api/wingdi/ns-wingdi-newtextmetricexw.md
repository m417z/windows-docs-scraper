# NEWTEXTMETRICEXW structure

## Description

The **NEWTEXTMETRICEX** structure contains information about a physical font.

## Members

### `ntmTm`

A [NEWTEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-newtextmetrica) structure.

### `ntmFontSig`

A [FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature) structure indicating the coverage of the font.

## See also

[FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[NEWTEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-newtextmetrica)

## Remarks

> [!NOTE]
> The wingdi.h header defines NEWTEXTMETRICEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
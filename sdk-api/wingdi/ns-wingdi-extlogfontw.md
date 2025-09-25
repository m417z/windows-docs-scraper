# EXTLOGFONTW structure

## Description

The **EXTLOGFONT** structure defines the attributes of a font.

## Members

### `elfLogFont`

Specifies some of the attributes of the specified font. This member is a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure.

### `elfFullName`

A unique name for the font (for example, ABCD Font Company TrueType Bold Italic Sans Serif).

### `elfStyle`

The style of the font (for example, Bold Italic).

### `elfVersion`

Reserved. Must be zero.

### `elfStyleSize`

This member only has meaning for hinted fonts. It specifies the point size at which the font is hinted. If set to zero, which is its default value, the font is hinted at the point size corresponding to the **lfHeight** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure specified by **elfLogFont**.

### `elfMatch`

A unique identifier for an enumerated font. This will be filled in by the graphics device interface (GDI) upon font enumeration.

### `elfReserved`

Reserved; must be zero.

### `elfVendorId`

A 4-byte identifier of the font vendor.

### `elfCulture`

Reserved; must be zero.

### `elfPanose`

A [PANOSE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-panose) structure that specifies the shape of the font. If all members of this structure are set to zero, the **elfPanose** member is ignored by the font mapper.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

[PANOSE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-panose)

## Remarks

> [!NOTE]
> The wingdi.h header defines EXTLOGFONT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
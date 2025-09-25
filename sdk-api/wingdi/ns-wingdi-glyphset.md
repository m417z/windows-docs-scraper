# GLYPHSET structure

## Description

The **GLYPHSET** structure contains information about a range of Unicode code points.

## Members

### `cbThis`

The size, in bytes, of this structure.

### `flAccel`

Flags describing the maximum size of the glyph indices. This member can be the following value.

| Value | Meaning |
| --- | --- |
| GS_8BIT_INDICES | Treat glyph indices as 8-bit wide values. Otherwise, they are 16-bit wide values. |

### `cGlyphsSupported`

The total number of Unicode code points supported in the font.

### `cRanges`

The total number of Unicode ranges in **ranges**.

### `ranges`

Array of Unicode ranges that are supported in the font.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetFontUnicodeRanges](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontunicoderanges)

[WCRANGE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-wcrange)
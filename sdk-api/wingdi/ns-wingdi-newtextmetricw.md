# NEWTEXTMETRICW structure

## Description

The **NEWTEXTMETRIC** structure contains data that describes a physical font.

## Members

### `tmHeight`

The height (ascent + descent) of characters.

### `tmAscent`

The ascent (units above the base line) of characters.

### `tmDescent`

The descent (units below the base line) of characters.

### `tmInternalLeading`

The amount of leading (space) inside the bounds set by the **tmHeight** member. Accent marks and other diacritical characters may occur in this area. The designer may set this member to zero.

### `tmExternalLeading`

The amount of extra leading (space) that the application adds between rows. Since this area is outside the font, it contains no marks and is not altered by text output calls in either OPAQUE or TRANSPARENT mode. The designer may set this member to zero.

### `tmAveCharWidth`

The average width of characters in the font (generally defined as the width of the letter x). This value does not include overhang required for bold or italic characters.

### `tmMaxCharWidth`

The width of the widest character in the font.

### `tmWeight`

The weight of the font.

### `tmOverhang`

The extra width per string that may be added to some synthesized fonts. When synthesizing some attributes, such as bold or italic, graphics device interface (GDI) or a device may have to add width to a string on both a per-character and per-string basis. For example, GDI makes a string bold by expanding the spacing of each character and overstriking by an offset value; it italicizes a font by shearing the string. In either case, there is an overhang past the basic string. For bold strings, the overhang is the distance by which the overstrike is offset. For italic strings, the overhang is the amount the top of the font is sheared past the bottom of the font.

The **tmOverhang** member enables the application to determine how much of the character width returned by a [GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a) function call on a single character is the actual character width and how much is the per-string extra width. The actual width is the extent minus the overhang.

### `tmDigitizedAspectX`

The horizontal aspect of the device for which the font was designed.

### `tmDigitizedAspectY`

The vertical aspect of the device for which the font was designed. The ratio of the **tmDigitizedAspectX** and **tmDigitizedAspectY** members is the aspect ratio of the device for which the font was designed.

### `tmFirstChar`

The value of the first character defined in the font.

### `tmLastChar`

The value of the last character defined in the font.

### `tmDefaultChar`

The value of the character to be substituted for characters that are not in the font.

### `tmBreakChar`

The value of the character to be used to define word breaks for text justification.

### `tmItalic`

An italic font if it is nonzero.

### `tmUnderlined`

An underlined font if it is nonzero.

### `tmStruckOut`

A strikeout font if it is nonzero.

### `tmPitchAndFamily`

The pitch and family of the selected font. The low-order bit (bit 0) specifies the pitch of the font. If it is 1, the font is variable pitch (or proportional). If it is 0, the font is fixed pitch (or monospace). Bits 1 and 2 specify the font type. If both bits are 0, the font is a raster font; if bit 1 is 1 and bit 2 is 0, the font is a vector font; if bit 1 is 0 and bit 2 is set, or if both bits are 1, the font is some other type. Bit 3 is 1 if the font is a device font; otherwise, it is 0.

The four high-order bits designate the font family. The **tmPitchAndFamily** member can be combined with the hexadecimal value 0xF0 by using the bitwise AND operator and can then be compared with the font family names for an identical match. For more information about the font families, see [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta).

### `tmCharSet`

The character set of the font.

### `ntmFlags`

Specifies whether the font is italic, underscored, outlined, bold, and so forth. May be any reasonable combination of the following values.

| Bit | Name | Meaning |
| --- | --- | --- |
| 0 | NTM_ITALIC | italic |
| 5 | NTM_BOLD | bold |
| 8 | NTM_REGULAR | regular |
| 16 | NTM_NONNEGATIVE_AC | no glyph in a font at any size has a negative A or C space. |
| 17 | NTM_PS_OPENTYPE | PostScript OpenType font |
| 18 | NTM_TT_OPENTYPE | TrueType OpenType font |
| 19 | NTM_MULTIPLEMASTER | multiple master font |
| 20 | NTM_TYPE1 | Type 1 font |
| 21 | NTM_DSIG | font with a digital signature. This allows traceability and ensures that the font has been tested and is not corrupted |

### `ntmSizeEM`

The size of the em square for the font. This value is in notional units (that is, the units for which the font was designed).

### `ntmCellHeight`

The height, in notional units, of the font. This value should be compared with the value of the **ntmSizeEM** member.

### `ntmAvgWidth`

The average width of characters in the font, in notional units. This value should be compared with the value of the **ntmSizeEM** member.

## Remarks

The last four members of the **NEWTEXTMETRIC** structure are not included in the [TEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica) structure; in all other respects, the structures are identical.

The sizes in the **NEWTEXTMETRIC** structure are typically specified in logical units; that is, they depend on the current mapping mode of the display context.

> [!NOTE]
> The wingdi.h header defines NEWTEXTMETRIC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)
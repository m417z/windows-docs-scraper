# TEXTMETRICW structure

## Description

The **TEXTMETRIC** structure contains basic information about a physical font. All sizes are specified in logical units; that is, they depend on the current mapping mode of the display context.

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

The average width of characters in the font (generally defined as the width of the letter *x* ). This value does not include the overhang required for bold or italic characters.

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

The value of the character to be substituted for characters not in the font.

### `tmBreakChar`

The value of the character that will be used to define word breaks for text justification.

### `tmItalic`

Specifies an italic font if it is nonzero.

### `tmUnderlined`

Specifies an underlined font if it is nonzero.

### `tmStruckOut`

A strikeout font if it is nonzero.

### `tmPitchAndFamily`

Specifies information about the pitch, the technology, and the family of a physical font.

The four low-order bits of this member specify information about the pitch and the technology of the font. A constant is defined for each of the four bits.

| Constant | Meaning |
| --- | --- |
| TMPF_FIXED_PITCH | If this bit is set the font is a variable pitch font. If this bit is clear the font is a fixed pitch font. Note very carefully that those meanings are the opposite of what the constant name implies. |
| TMPF_VECTOR | If this bit is set the font is a vector font. |
| TMPF_TRUETYPE | If this bit is set the font is a TrueType font. |
| TMPF_DEVICE | If this bit is set the font is a device font. |

An application should carefully test for qualities encoded in these low-order bits, making no arbitrary assumptions. For example, besides having their own bits set, TrueType and PostScript fonts set the TMPF_VECTOR bit. A monospace bitmap font has all of these low-order bits clear; a proportional bitmap font sets the TMPF_FIXED_PITCH bit. A Postscript printer device font sets the TMPF_DEVICE, TMPF_VECTOR, and TMPF_FIXED_PITCH bits.

The four high-order bits of **tmPitchAndFamily** designate the font's font family. An application can use the value 0xF0 and the bitwise AND operator to mask out the four low-order bits of **tmPitchAndFamily**, thus obtaining a value that can be directly compared with font family names to find an identical match. For information about font families, see the description of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure.

### `tmCharSet`

The character set of the font. For a list of possible values, see *lfCharSet* field of the [LOGFONT structure](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfontw).

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

## Remarks

> [!NOTE]
> The wingdi.h header defines TEXTMETRIC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
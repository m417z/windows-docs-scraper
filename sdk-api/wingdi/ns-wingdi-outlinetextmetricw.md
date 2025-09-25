# OUTLINETEXTMETRICW structure

## Description

The **OUTLINETEXTMETRIC** structure contains metrics describing a TrueType font.

## Members

### `otmSize`

The size, in bytes, of the **OUTLINETEXTMETRIC** structure.

### `otmTextMetrics`

A [TEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica) structure containing further information about the font.

### `otmFiller`

A value that causes the structure to be byte-aligned.

### `otmPanoseNumber`

The PANOSE number for this font.

### `otmfsSelection`

The nature of the font pattern. This member can be a combination of the following bits.

| Bit | Meaning |
| --- | --- |
| 0 | Italic |
| 1 | Underscore |
| 2 | Negative |
| 3 | Outline |
| 4 | Strikeout |
| 5 | Bold |

### `otmfsType`

Indicates whether the font is licensed. Licensed fonts must not be modified or exchanged. If bit 1 is set, the font may not be embedded in a document. If bit 1 is clear, the font can be embedded. If bit 2 is set, the embedding is read-only.

### `otmsCharSlopeRise`

The slope of the cursor. This value is 1 if the slope is vertical. Applications can use this value and the value of the **otmsCharSlopeRun** member to create an italic cursor that has the same slope as the main italic angle (specified by the **otmItalicAngle** member).

### `otmsCharSlopeRun`

The slope of the cursor. This value is zero if the slope is vertical. Applications can use this value and the value of the **otmsCharSlopeRise** member to create an italic cursor that has the same slope as the main italic angle (specified by the **otmItalicAngle** member).

### `otmItalicAngle`

The main italic angle of the font, in tenths of a degree counterclockwise from vertical. Regular (roman) fonts have a value of zero. Italic fonts typically have a negative italic angle (that is, they lean to the right).

### `otmEMSquare`

The number of logical units defining the x- or y-dimension of the em square for this font. (The number of units in the x- and y-directions are always the same for an em square.)

### `otmAscent`

The maximum distance characters in this font extend above the base line. This is the typographic ascent for the font.

### `otmDescent`

The maximum distance characters in this font extend below the base line. This is the typographic descent for the font.

### `otmLineGap`

The typographic line spacing.

### `otmsCapEmHeight`

Not supported.

### `otmsXHeight`

Not supported.

### `otmrcFontBox`

The bounding box for the font.

### `otmMacAscent`

The maximum distance characters in this font extend above the base line for the Macintosh computer.

### `otmMacDescent`

The maximum distance characters in this font extend below the base line for the Macintosh computer.

### `otmMacLineGap`

The line-spacing information for the Macintosh computer.

### `otmusMinimumPPEM`

The smallest recommended size for this font, in pixels per em-square.

### `otmptSubscriptSize`

The recommended horizontal and vertical size for subscripts in this font.

### `otmptSubscriptOffset`

The recommended horizontal and vertical offset for subscripts in this font. The subscript offset is measured from the character origin to the origin of the subscript character.

### `otmptSuperscriptSize`

The recommended horizontal and vertical size for superscripts in this font.

### `otmptSuperscriptOffset`

The recommended horizontal and vertical offset for superscripts in this font. The superscript offset is measured from the character base line to the base line of the superscript character.

### `otmsStrikeoutSize`

The width of the strikeout stroke for this font. Typically, this is the width of the em dash for the font.

### `otmsStrikeoutPosition`

The position of the strikeout stroke relative to the base line for this font. Positive values are above the base line and negative values are below.

### `otmsUnderscoreSize`

The thickness of the underscore character for this font.

### `otmsUnderscorePosition`

The position of the underscore character for this font.

### `otmpFamilyName`

The offset from the beginning of the structure to a string specifying the family name for the font.

### `otmpFaceName`

The offset from the beginning of the structure to a string specifying the typeface name for the font. (This typeface name corresponds to the name specified in the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure.)

### `otmpStyleName`

The offset from the beginning of the structure to a string specifying the style name for the font.

### `otmpFullName`

The offset from the beginning of the structure to a string specifying the full name for the font. This name is unique for the font and often contains a version number or other identifying information.

## Remarks

The sizes returned in **OUTLINETEXTMETRIC** are specified in logical units; that is, they depend on the current mapping mode of the specified display context.

Note, **OUTLINETEXTMETRIC** is defined using the current pack setting. To avoid problems, make sure that the application is built using the platform default packing. For example, 32-bit Windows uses a default of 8-byte packing. For more information, see [C-Compiler Packing Issues](https://learn.microsoft.com/windows/win32/midl/c-compiler-packing-issues).

> [!NOTE]
> The wingdi.h header defines OUTLINETEXTMETRIC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetOutlineTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getoutlinetextmetricsa)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

[TEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica)
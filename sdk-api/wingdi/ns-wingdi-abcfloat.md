# ABCFLOAT structure

## Description

The **ABCFLOAT** structure contains the A, B, and C widths of a font character.

## Members

### `abcfA`

The A spacing of the character. The A spacing is the distance to add to the current position before drawing the character glyph.

### `abcfB`

The B spacing of the character. The B spacing is the width of the drawn portion of the character glyph.

### `abcfC`

The C spacing of the character. The C spacing is the distance to add to the current position to provide white space to the right of the character glyph.

## Remarks

The A, B, and C widths are measured along the base line of the font.

The character increment (total width) of a character is the sum of the A, B, and C spaces. Either the A or the C space can be negative to indicate underhangs or overhangs.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharABCWidthsFloat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsfloata)
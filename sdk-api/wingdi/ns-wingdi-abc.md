# ABC structure

## Description

The **ABC** structure contains the width of a character in a TrueType font.

## Members

### `abcA`

The A spacing of the character. The A spacing is the distance to add to the current position before drawing the character glyph.

### `abcB`

The B spacing of the character. The B spacing is the width of the drawn portion of the character glyph.

### `abcC`

The C spacing of the character. The C spacing is the distance to add to the current position to provide white space to the right of the character glyph.

## Remarks

The total width of a character is the summation of the A, B, and C spaces. Either the A or the C space can be negative to indicate underhangs or overhangs.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa)
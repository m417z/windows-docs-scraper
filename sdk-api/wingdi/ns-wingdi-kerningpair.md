# KERNINGPAIR structure

## Description

The **KERNINGPAIR** structure defines a kerning pair.

## Members

### `wFirst`

The character code for the first character in the kerning pair.

### `wSecond`

The character code for the second character in the kerning pair.

### `iKernAmount`

The amount this pair will be kerned if they appear side by side in the same font and size. This value is typically negative, because pair kerning usually results in two characters being set more tightly than normal. The value is specified in logical units; that is, it depends on the current mapping mode.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetKerningPairs](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getkerningpairsa)
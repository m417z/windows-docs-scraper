# _WIDTHRUN structure

## Description

The WIDTHRUN structure is used to define the contents of [Unidrv font metrics files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.ufm files).

## Members

### `wStartGlyph`

Is an index value indicating the first glyph of the width run.

### `wGlyphCount`

Specifies the number of glyphs represented by the width run.

### `loCharWidthOffset`

Specifies the offset from the beginning of a [WIDTHTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_widthtable) structure to the location containing the width of the set of glyphs contained in the width run.

## Remarks

A width run describes the widths of a set of adjacent glyphs. Sets of width runs are described by an array of WIDTHRUN elements. The array is contained in a [WIDTHTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_widthtable) structure.

Index values contained in **dwStartGlyph** are integers, starting with 1, with each glyph in the font having an index. That is, the first glyph in the font is assigned an index value of 1, the next glyph's index is 2, and so on.

For example, suppose the first three elements of a WIDTHRUN array contain the following values:

**wStartGlyph**
**wGlyphCount**
**IoCharWidthOffset**=*xxx*

**wStartGlyph**
**wGlyphCount**
**IoCharWidthOffset**=*yyy*

**wStartGlyph**
**wGlyphCount**
**IoCharWidthOffset**
*zzz*
At offset *xxx*: 56, 50, 60 (WORD-sized)

At offset *yyy*: 54, 60

At offset *zzz*: 54, 60, 43, 40

In this example, widths for the first three glyphs of the font are contained in an array at location WIDTHTABLE+*xxx*, the widths for the next two glyphs are contained in an array at location WIDTHTABLE+*yyy*, and widths for the next four glyphs are contained in an array at location WIDTHTABLE+*zzz*.

If a device font is proportional and has variable pitch characters, the WIDTHTABLE structure's **WidthRun** array contains only one WIDTHRUN element, and WIDTHTABLE+**loCharWidthOffset** points to a character width array for all characters in the font.

For Western device fonts, the **fwdAveCharWidth** member of the [IFIMETRICS](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-ifimetrics) structure is used for determining single-byte character widths, if the character widths are not specified using a WIDTHTABLE structure.

For East Asian device fonts, the **fwdAveCharWidth** and **fwdMaxCharInc** members of the IFIMETRICS structure are used for determining single-byte and double-byte character widths. If the font is proportional, the font's .ufm file should contain a WIDTHTABLE structure for the proportional glyphs.

## See also

[IFIMETRICS](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-ifimetrics)

[WIDTHTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_widthtable)
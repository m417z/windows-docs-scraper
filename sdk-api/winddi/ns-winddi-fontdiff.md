# FONTDIFF structure

## Description

The FONTDIFF structure describes all of the characteristics that are different between a base font and one of its simulations.

## Members

### `jReserved1`

### `jReserved2`

### `jReserved3`

Are reserved for system use.

### `bWeight`

Specifies the Panose weight.

### `usWinWeight`

Specifies the weight of the font in the range 0 to 1000 (for example, 400 is normal and 700 is bold). This value is provided to the application in the **lfWeight** member of the Win32 LOGFONT structure.

### `fsSelection`

Specifies a combination of the following flags:

| Value | Meaning |
| --- | --- |
| FM_SEL_BOLD | Set if the characters of the font are bold. |
| FM_SEL_ITALIC | Set if the characters of the font are italic. |
| FM_SEL_NEGATIVE | Set if the characters of the font have the foreground and background reversed. |
| FM_SEL_OUTLINED | Set if the characters of the font are hollow. |
| FM_SEL_REGULAR | Set if the characters of the font are normal weight. |
| FM_SEL_STRIKEOUT | Set if the characters of the font are struck out by default; otherwise strikeouts must be simulated. |
| FM_SEL_UNDERSCORE | Set if all the characters of the font are underscored by default; otherwise underscoring must be simulated. |

### `fwdAveCharWidth`

Specifies the arithmetic average of the width of all of the 26 lower case letters 'a' through 'z' of the Latin alphabet and the space character. If any of the 26 lowercase letters are not present, then this member should be set equal to the weighted average of all glyphs in the font.

### `fwdMaxCharInc`

Specifies the maximum character increment of all glyphs in the font.

### `ptlCaret`

Specifies a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that indicates the direction of the ascender direction of the font. For example, the value for a nonitalicized Latin font is (0,1) while an italicized Latin font might specify a value of (2,5).

## Remarks

If a font has already been emboldened, the only possible remaining simulation is italicization, yielding a bold italic simulation. Similarly, an italicized font can only be emboldened, also yielding a bold italic simulation.

For descriptions of the FSHORT and FWORD data types, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## See also

[FONTSIM](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontsim)
# GLYPHDATA structure

## Description

The GLYPHDATA structure contains information about an individual glyph.

## Members

### `gdf`

Specifies a [GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef) union that contains a pointer to either a [GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits) structure or a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure, depending on whether, respectively, the glyph data is in the form of a bitmap or an outline.

### `hg`

Handle to the glyph.

### `fxD`

Specifies a FIX value containing the character increment amount, D = A + B + C. The character increment amount represents the sum of the prebearing, or left sidebearing amount (A), the width of the glyph (B), and the width of the right sidebearing amount (C). The two sidebearing amounts represent the (usually) empty space immediately to the left and right of the glyph. The value stored in **fxD** is the dot product of D and a unit vector along the baseline (in device coordinates), yielding the projection of D onto the baseline.

### `fxA`

Specifies a FIX value containing the prebearing, or left sidebearing amount, A. The value stored in **fxA** is the dot product of A and a unit vector along the baseline (in device coordinates), yielding the projection of A onto the baseline.

### `fxAB`

Specifies a FIX value containing the advancing edge of the character, A + B. The value stored in fxAB is the dot product of A + B and a unit vector along the baseline (in device coordinates), yielding the projection of A + B onto the baseline.

### `fxInkTop`

Specifies a FIX value containing the distance between the baseline and the ink box top along a unit vector in the ascent direction (in device coordinates).

### `fxInkBottom`

Specifies a FIX value containing the distance between the baseline and the ink box bottom along a unit vector in the ascent direction (in device coordinates).

### `rclInk`

Specifies a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that describes the ink box in which the glyph fits. The sides of the ink box are parallel to the x and y axes.

### `ptqD`

Specifies a POINTQF structure that contains the character increment vector, D = A + B + C. The high-order WORDs of **ptqD** are 28.4 device coordinates. The low-order WORDs of this member provide additional precision. For a description of the POINTQF structure, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## Remarks

The quantities A, B, and C mentioned in the descriptions of GLYPHDATA members are simple transforms of the notional space versions into 28.4 device coordinates. A is the left sidebearing amount, the width of the space to the left of the glyph, B is the width of the glyph, and C is the right sidebearing amount, the width of the space to the right of the glyph. For some glyphs, A and/or C can be negative, indicating that the glyph extends farther to the left and/or right than is usually the case.

For a description of the FIX data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## See also

[GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits)

[GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)
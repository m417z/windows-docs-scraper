# GLYPHDEF structure

## Description

The GLYPHDEF union identifies individual glyphs and provides either a pointer to a GLYPHBITS structure or a pointer to a PATHOBJ structure.

## Members

### `pgb`

If **pgb** is defined, this member is a pointer to a [GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits) structure. The driver can use the bitmap bits stored in this structure to form the associated glyph on its surface.

### `ppo`

If **ppo** is defined, this member is a pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure the driver can examine to extract the path describing the associated glyph.

## See also

[GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)
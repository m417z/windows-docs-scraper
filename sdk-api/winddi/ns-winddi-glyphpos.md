# GLYPHPOS structure

## Description

The GLYPHPOS structure is used by GDI to provide a graphics driver with a glyph's description and position.

## Members

### `hg`

Handle to the glyph.

### `pgdf`

Pointer to a [GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef) union.

### `ptl`

Specifies a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that contains the coordinates of the point in device space where the character origin of the glyph should be placed.

## Remarks

## See also

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)

[GLYPHDEF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphdef)

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[STROBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_benum)

[STROBJ_vEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_venumstart)
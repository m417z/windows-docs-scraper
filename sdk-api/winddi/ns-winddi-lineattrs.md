# LINEATTRS structure

## Description

The LINEATTRS structure is used by a driver's line-drawing functions to determine line attributes.

## Members

### `fl`

Option flags. This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| LA_ALTERNATE | A special cosmetic line style; every other pixel is on. |
| LA_GEOMETRIC | A geometric wide line. |
| LA_STARTGAP | The first entry in the style array specifies the length of the first gap. |
| LA_STYLED | The line is a styled line. |

### `iJoin`

Specifies join styles for geometric wide lines. This member can be one of the following values:

| Join Style | Meaning |
| --- | --- |
| JOIN_BEVEL | The joining edges of wide lines are beveled. |
| JOIN_MITER | The joining edges of wide lines are mitered. |
| JOIN_ROUND | The joining edges of wide lines are rounded. |

### `iEndCap`

Specifies the end cap style for a geometric wide line. This member can be one of the following values:

| End Cap Style | Meaning |
| --- | --- |
| ENDCAP_BUTT | The end cap is |
| ENDCAP_ROUND | The end cap is rounded. |
| ENDCAP_SQUARE | The end cap is square. |

### `elWidth`

Specifies a FLOAT_LONG that indicates the width of the line. This width is measured in FLOAT world coordinates for a geometric wide line, but in LONG device coordinates for a cosmetic wide line. For a description of the FLOAT_LONG data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

### `eMiterLimit`

Specifies a FLOATL that sets the limit as a multiple of the line width that a miter join is allowed to extend from its inside corner to its outer vertex. This prevents very long spikes from occurring when lines of a path meet at very small angles. If the miter limit is exceeded, a bevel join should be used instead. For a description of the FLOATL data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

This member is used only by geometric wide lines.

### `cstyle`

Specifies the number of entries in the style array pointed to by the **pstyle** member.

### `pstyle`

Pointer to an array of FLOAT_LONG elements: the style array. If this member is **NULL**, the line style is solid. For a description of the FLOAT_LONG data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

### `elStyleState`

Specifies a FLOAT_LONG that contains a pair of 16-bit values supplied by GDI whenever the driver calls [PATHOBJ_bEnumClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benumcliplines). These two values, packed into a FLOAT_LONG, specify where in the styling array (at which pixel) to start the first subpath. This value must be updated as part of the output routine if the line is not solid. This member applies to cosmetic lines only

. See also [Styled Cosmetic Lines](https://learn.microsoft.com/windows-hardware/drivers/display/styled-cosmetic-lines) for additional information.

## See also

[DrvStrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokeandfillpath)

[DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath)

[PATHOBJ_vEnumStartClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstartcliplines)
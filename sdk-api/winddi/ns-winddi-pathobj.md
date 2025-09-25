# PATHOBJ structure

## Description

The PATHOBJ structure is used to describe a set of lines and Bezier curves that are to be stroked or filled.

## Members

### `fl`

A set of hint flags that describe the path. This member is a bitwise OR (with certain restrictions) of the following values:

| Flag | Description |
| --- | --- |
| PO_ALL_INTEGERS | The vertices of the path have integer coordinates with no fractional parts. This flag is intended primarily as an accelerator so that drivers can use a simpler all-integer fast-path.<br><br>In addition, when GDI sets this flag, the driver is permitted to deviate slightly from the standard NT-based operating system GDI Grid Intersection Quantization (GIQ) convention that dictates the rasterization rules for lines. Specifically, when PO_ALL_INTEGERS is set the driver can choose its own rules for which pixel should be lit in the tie-breaker case where a line logically falls exactly between two pixels. Typically, this flag allows drivers to use hardware point-to-point line drawing capabilities even when the hardware has a different tie-breaker rule from that of GIQ.<br><br>GDI sets this flag only for solid lines that are one pixel wide. Also, GDI sets this flag only if the graphics mode of the device context is set to GM_COMPATIBLE. For more information about setting the graphics mode, see **SetGraphicsMode** in the Microsoft Window SDK documentation. |
| PO_BEZIERS | The path contains Bezier curves. GDI sets only one of PO_BEZIERS or PO_ELLIPSE in the **fl** member. |
| PO_ELLIPSE | The path consists of a single ellipse inscribed in the path's bounding rectangle. GDI sets only one of PO_BEZIERS or PO_ELLIPSE in the **fl** member. |
| PO_ENUM_AS_INTEGERS | The driver can request that the vertices returned from [PATHOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benum) be expressed in a 32-bit integer format rather than the standard 28.4 format. The driver makes this request by ORing PO_ENUM_AS_INTEGERS into the **fl** member of the given PATHOBJ before calling **PATHOBJ_bEnum**.<br><br>The driver can set PO_ENUM_AS_INTEGERS only when GDI has set the PO_ALL_INTEGERS flag. That is, the path must be known to contain only integer coordinates. Note that PO_ENUM_AS_INTEGERS is the only flag that the driver is permitted to modify.<br><br>When this flag is set, the driver is permitted to deviate slightly from the standard GIQ convention that dictates the rasterization rules for lines. Specifically, when PO_ENUM_ALL_INTEGERS is set the driver can choose its own rules for which pixel should be lit in the tie-breaker case where a line logically falls exactly between two pixels. Typically, this flag allows drivers to use hardware point-to-point line drawing capabilities even when the hardware has a different tie-breaker rule from that of GIQ. |

### `cCurves`

The number of lines and Bezier curves that make up the path.

## Remarks

Functions associated with this structure allow the lines and curves to be enumerated for the driver.

The following GDI service routines are provided for PATHOBJ objects:

[PATHOBJ_bCloseFigure](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_bclosefigure)

[PATHOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benum)

[PATHOBJ_bEnumClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_benumcliplines)

[PATHOBJ_bMoveTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_bmoveto)

[PATHOBJ_bPolyBezierTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_bpolybezierto)

[PATHOBJ_bPolyLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_bpolylineto)

[PATHOBJ_vEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstart)

[PATHOBJ_vEnumStartClipLines](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_venumstartcliplines)

[PATHOBJ_vGetBounds](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-pathobj_vgetbounds)

## See also

[DrvFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfillpath)

[DrvStrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokeandfillpath)

[DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath)

[EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath)

[EngDeletePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletepath)
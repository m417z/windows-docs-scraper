# EngStrokeAndFillPath function

## Description

The **EngStrokeAndFillPath** function causes GDI to fill a path and stroke it at the same time.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that defines the drawing surface.

### `ppo`

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure that defines the path to be filled. The **PATHOBJ_***Xxx* service routines are provided to enumerate the lines, Bezier curves, and other data that make up the path.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The **CLIPOBJ_***Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

### `pxo`

Pointer to a [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure that is only needed when a geometric wide line is to be drawn and specifies the transform that converts world coordinates to device coordinates. The path is provided in device coordinates but a geometric wide line is actually widened in world coordinates.

The driver can use the **XFORMOBJ_***Xxx* service routines to determine the transform.

### `pboStroke`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that describes the brush to use when stroking the path.

### `plineattrs`

Pointer to a [LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs) structure.

### `pboFill`

Pointer to a BRUSHOBJ structure that describes the brush to use when filling the path.

### `pptlBrushOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the brush origin for both brushes.

### `mixFill` [in]

Defines the foreground and background raster operations to use for the fill brush.

### `flOptions` [in]

Specifies which fill mode to use. This parameter can be FP_WINDINGMODE or FP_ALTERNATEMODE; all other bits should be ignored. For more information about these modes, see [Path Fill Modes](https://learn.microsoft.com/windows-hardware/drivers/display/path-fill-modes).

## Return value

The return value is **TRUE** if GDI fills the path. If the driver should fill the path, the return value is **FALSE**, and an error code is not logged. If GDI encounters an unexpected error, such as not being able to realize the brush, the return value is DDI_ERROR, and an error code is logged.

## Remarks

The mix mode defines how the incoming pattern should be mixed with the data already on the device surface. The MIX data type consists of two ROP2 values packed into a single ULONG. The low-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvStrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokeandfillpath)

[LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))
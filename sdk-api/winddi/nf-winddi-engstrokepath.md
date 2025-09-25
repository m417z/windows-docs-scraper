# EngStrokePath function

## Description

The **EngStrokePath** function requests that GDI stroke a specified path.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `ppo`

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure. The **PATHOBJ_***Xxx* service routines are provided to enumerate the lines, Bezier curves, and other data that make up the path. This indicates what is to be drawn.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The **CLIPOBJ_***Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles. Optionally, all the lines in the path can be enumerated preclipped by this CLIPOBJ. This means that drivers can have all their line clipping calculations done for them.

### `pxo`

Pointer to a [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure. This is needed only when a geometric wide line is to be drawn. It specifies the transform that converts world coordinates to device coordinates. This is needed because the path is provided in device coordinates but a geometric wide line is actually widened in world coordinates.

The driver can use the **XFORMOBJ_***Xxx* service routines to determine the transform.

### `pbo`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that specifies the brush to be used when drawing the path.

### `pptlBrushOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that contains the brush origin used to align the brush pattern on the device.

### `plineattrs` [in]

Pointer to a [LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs) structure. Note that the **elStyleState** member of this structure must be updated as part of this function if the line is styled. Also note the **ptlLastPel** member of the same structure must be updated if a single-pixel-width cosmetic line is being drawn.

### `mix` [in]

Specifies how to combine the brush with the destination.

## Return value

The return value is **TRUE** if GDI strokes the path. If the driver should stroke the path, the return value is **FALSE**, and no error is logged. If GDI encounters an error, the return value is DDI_ERROR, and an error code is logged.

## Remarks

The mix mode defines how the incoming pattern should be mixed with the data already on the device surface. The MIX data type consists of two ROP2 values packed into a single ULONG. The low-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath)

[LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))
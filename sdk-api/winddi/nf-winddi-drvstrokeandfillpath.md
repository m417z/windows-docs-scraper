# DrvStrokeAndFillPath function

## Description

The **DrvStrokeAndFillPath** function strokes (outlines) and fills a path concurrently.

## Parameters

### `pso` [in, out]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `ppo` [in, out]

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure that describes the path to be filled. The PATHOBJ_*Xxx* service routines are provided to enumerate the lines, Bezier curves, and other data that make up the path.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The CLIPOBJ_*Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

### `pxo` [in, optional]

Pointer to a [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure that is required when a geometric wide line is drawn. It specifies the transform that takes world coordinates to device coordinates. This is needed because the path is provided in device coordinates but a geometric wide line is actually widened in world coordinates. The XFORMOBJ can be queried to find out what the transform is.

### `pboStroke` [in]

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that specifies the brush to use when stroking the path.

### `plineattrs` [in]

Pointer to the [LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs) structure that describes the attributes of the line to be drawn.

### `pboFill` [in]

Pointer to a BRUSHOBJ structure that specifies the brush to use when filling the path.

### `pptlBrushOrg` [in]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that specifies the brush origin for both brushes.

### `mixFill` [in]

The mix mode that defines the foreground and background raster operations to use for the brush. For more information about mix mode, see Remarks.

### `flOptions` [in]

Specifies either FP_WINDINGMODE, meaning that a winding mode fill should be performed, or FP_ALTERNATEMODE, meaning that an alternating mode fill should be performed. All other flags should be ignored. For more information about these modes, see [Path Fill Modes](https://learn.microsoft.com/windows-hardware/drivers/display/path-fill-modes).

## Return value

The return value is **TRUE** if the driver is able to fill the path. Otherwise, if GDI should instead fill the path, the return value is **FALSE**. If an error occurs, the return value is DDI_ERROR, and an error code is logged.

## Remarks

If a wide line is used for stroking, the filled area must be reduced to compensate.

The driver can return **FALSE** if the path or the clipping is too complex for the device to handle; in that case, GDI converts to a simpler call. For example, if the device driver has set the GCAPS_BEZIERS flag in the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure and then receives a path with Bezier curves, it can return **FALSE**; GDI will then convert the Bezier curves to lines and call **DrvStrokeAndFillPath** again. If the device driver returns **FALSE** again, GDI will further simplify the call, making calls to [DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath) and [DrvFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfillpath), or to [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt), depending on the mix and width of the lines making up the path.

The mix mode defines how the incoming pattern should be mixed with the data that is already on the device surface. The MIX data type consists of two binary raster operation (ROP2) values packed into a single ULONG. The lowest-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfillpath)

[DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath)

[LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))
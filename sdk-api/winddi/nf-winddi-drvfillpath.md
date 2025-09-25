# DrvFillPath function

## Description

The **DrvFillPath** function is an optional entry point to handle the filling of closed paths.

## Parameters

### `pso` [in, out]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that defines the surface on which to draw.

### `ppo` [in]

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure that defines the path to be filled. The PATHOBJ_*Xxx* service routines are provided to enumerate the lines, Bezier curves, and other data that make up the path.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The CLIPOBJ_*Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

### `pbo` [in]

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that defines the pattern and colors used to fill the closed path. This parameter should be dereferenced only if the fill operation specified in *mix* requires the use of a brush. For example, if *mix* is set to BLACKNESS, *pbo* is not defined and should not be dereferenced.

### `pptlBrushOrg` [in]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the brush origin, which is used to align the brush pattern on the device.

### `mix` [in]

The mix mode that defines the foreground and background raster operations to use for the brush. For more information about mix mode, see Remarks.

### `flOptions` [in]

Specifies either FP_WINDINGMODE, indicating that a winding mode fill should be performed, or FP_ALTERNATEMODE, indicating that an alternating mode fill should be performed. All other flags should be ignored. For more information about these modes, see [Path Fill Modes](https://learn.microsoft.com/windows-hardware/drivers/display/path-fill-modes).

## Return value

The return value is **TRUE** if the driver is able to fill the path. If the path or clipping is too complex to be handled by the driver and should be handled by GDI, the return value is **FALSE**, and an error code is not logged. If the driver encounters an unexpected error, such as not being able to realize the brush, the return value is DDI_ERROR, and an error code is logged.

## Remarks

GDI can call **DrvFillPath** to fill a path on a [device-managed surface](https://learn.microsoft.com/windows-hardware/drivers/). When deciding whether to call this function, GDI compares the fill requirements with the following flags in the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure: GCAPS_BEZIERS, GCAPS_ALTERNATEFILL, and GCAPS_WINDINGFILL.

The mix mode defines how the incoming pattern should be mixed with the data that is already on the device surface. The MIX data type consists of two binary raster operation (ROP2) values packed into a single ULONG. The lowest-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvStrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokeandfillpath)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)
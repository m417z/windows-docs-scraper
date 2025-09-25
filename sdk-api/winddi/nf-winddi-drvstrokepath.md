# DrvStrokePath function

## Description

The **DrvStrokePath** function strokes (outlines) a path.

## Parameters

### `pso` [in, out]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the surface on which to draw.

### `ppo` [in]

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure. GDI PATHOBJ_*Xxx* service routines are provided to enumerate the lines, Bezier curves, and other data that make up the path. This indicates what is to be drawn.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. GDI CLIPOBJ_*Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles. Optionally, all the lines in the path may be enumerated preclipped in a CLIPOBJ structure. This means that drivers can have GDI perform all line clipping calculations.

### `pxo` [in, optional]

Pointer to a [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure. This is needed only when a geometric wide line is to be drawn. It specifies the transform that maps world coordinates to device coordinates. This is needed because the path is provided in device coordinates but a geometric wide line is actually widened in world coordinates.

The XFORMOBJ structure can be queried to find the transform.

### `pbo` [in]

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that specifies the brush to be used when drawing the path.

### `pptlBrushOrg` [in]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that specifies the brush origin used to align the brush pattern on the device.

### `plineattrs` [in]

Pointer to a [LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs) structure. Note that the **elStyleState** member of this structure must be updated as part of this function if the line is styled. Also note that the **ptlLastPel** member must be updated if a single pixel width cosmetic line is being drawn.

### `mix` [in]

The mix mode that defines the foreground and background raster operations to use for the brush. For more information about mix mode, see Remarks.

## Return value

The return value is **TRUE** if the driver is able to stroke the path. If GDI should instead stroke the path, the return value is **FALSE**, but no error code is logged. If the driver encounters an error, the return value is DDI_ERROR, and an error code is reported.

## Remarks

If the driver has hooked the function, and if the appropriate GCAPS are set, GDI calls **DrvStrokePath** when GDI draws a line or curve with any set of attributes.

If a driver supports this entry point, it should also support the drawing of cosmetic wide lines with arbitrary clipping. Using the provided GDI functions, the call can be broken down into a set of single-pixel-width lines with precomputed clipping.

This function is required if any drawing is to be done on a [device-managed surface](https://learn.microsoft.com/windows-hardware/drivers/).

Drivers for advanced devices can optionally receive this call to draw paths containing Bezier curves and geometric wide lines. GDI will test the GCAPS_BEZIERS and GCAPS_GEOMETRICWIDE flags of the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure to decide whether it should call this function. (The four combinations of the bits determine the four levels of functionality for this call.) If the driver gets an advanced call containing Bezier curves or geometric wide lines, it can decide not to handle the call, returning **FALSE**. This might happen if the path or clipping is too complex for the device to process. If the call does return **FALSE**, GDI breaks the call down into simpler calls that can be handled more easily.

For device-managed surfaces, the function must minimally support single-pixel-wide solid and styled cosmetic lines using a solid-colored brush.

The mix mode defines how the incoming pattern should be mixed with the data that is already on the device surface. The MIX data type consists of two binary raster operation (ROP2) values packed into a single ULONG. The lowest-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfillpath)

[LINEATTRS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-lineattrs)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))
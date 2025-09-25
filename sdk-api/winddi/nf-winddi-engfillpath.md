# EngFillPath function

## Description

The **EngFillPath** function fills a path.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `ppo`

Pointer to a [PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj) structure that defines the path to be filled. Use the **PATHOBJ_***Xxx* service routines to enumerate the lines, Bezier curves, and other data that make up the path.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. Use the **CLIPOBJ_***Xxx* service routines to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

### `pbo`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that defines the pattern and colors with which to fill.

### `pptlBrushOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure defining the brush origin to use to align the brush pattern on the device.

### `mix` [in]

Defines the foreground and background raster operations to use for the brush.

### `flOptions` [in]

Specifies the mode to use when filling the path. This value should be FP_WINDINGMODE or FP_ALTERNATEMODE. All other flags should be ignored. For more information about these modes, see [Path Fill Modes](https://learn.microsoft.com/windows-hardware/drivers/display/path-fill-modes).

## Return value

The return value is **TRUE** if GDI is able to fill the path. Otherwise, it is **FALSE**, and an error code is not logged. If an error is encountered, the return value is **FALSE**, and an error code is logged.

## Remarks

Whenever GDI fills a path on a [device-managed surface](https://learn.microsoft.com/windows-hardware/drivers/), it can call this entry point depending on a comparison of the fill requirements and the following GCAPS bits: GCAPS_BEZIERS, GCAPS_ALTERNATEFILL, and GCAPS_WINDINGFILL.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)
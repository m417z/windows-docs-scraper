# EngPaint function

## Description

The **EngPaint** function causes GDI to paint a specified region.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that defines the area to be painted. The **CLIPOBJ_***Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

### `pbo`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that defines the pattern and colors with which to fill.

### `pptlBrushOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the brush origin used to align the brush pattern on the device.

### `mix` [in]

Defines the foreground and background raster operations to use for the brush.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

Vector device drivers can implement this function with the help of [EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath) and **PATHOBJ_***Xxx* service routines.

The mix mode defines how the incoming pattern should be mixed with the data already on the device surface. The MIX data type consists of two ROP2 values packed into a single ULONG. The low-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[EngCreatePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepath)

[PATHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-pathobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)
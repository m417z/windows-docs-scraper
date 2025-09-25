# DrvLineTo function

## Description

The **DrvLineTo** function draws a single, solid, integer-only cosmetic line.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that defines the clip region in which the rendering must be done. No pixels can be affected outside this clip region.

### `pbo`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that specifies the brush to use when drawing the line.

### `x1`

Specify the integer x-coordinates of the line's beginning point.

### `y1`

Specify the integer y-coordinates of the line's beginning point.

### `x2`

Specify the integer x-coordinates of the line's end point.

### `y2`

Specify the integer y-coordinates of the line's end point.

### `prclBounds`

Pointer to the [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the integer rectangle that bounds the unclipped line. Drivers that support hardware line drawing can use this rectangle to quickly determine whether the line fits in a coordinate space small enough to be rendered by the hardware.

### `mix`

The mix mode that defines the foreground and background raster operations to use for the brush. In the call to **DrvLineTo**, the foreground and background raster-operation values are the same. For more information about mix mode, see Remarks.

## Return value

**DrvLineTo** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

**DrvLineTo** is an optional entry point that a driver can supply as an optimization for application calls to the Win32 **LineTo** function. If the driver doesn't hook **DrvLineTo**, or if the driver returns **FALSE** from a call to this function, GDI will automatically call [DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath) instead. A driver that has hooked **DrvLineTo** can call [EngLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englineto) when the rendering surface is a [DIB](https://learn.microsoft.com/windows-hardware/drivers/).

This function is simpler than [DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath) because it supports only integer end-points and solid cosmetic lines. GDI has less overhead when calling **DrvLineTo** instead of **DrvStrokePath**; consequently, **DrvLineTo** is intended to be used as a simple optimization by drivers that can accelerate nominal width lines in hardware.

The mix mode defines how the incoming pattern should be mixed with the data that is already on the device surface. The MIX data type consists of two binary raster operation (ROP2) values packed into a single ULONG. The lowest-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath)

[EngLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englineto)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)
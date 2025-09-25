# EngLineTo function

## Description

The **EngLineTo** function draws a single, solid, integer-only cosmetic line.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that defines the clip region in which the rendering must be done. No pixels can be affected outside this clip region.

### `pbo`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that specifies the brush to use when drawing the line.

### `x1`

Specify the integer x-coordinate of the line's beginning point.

### `y1`

Specify the integer y-coordinate of the line's beginning point.

### `x2`

Specify the integer x-coordinate of the line's end point.

### `y2`

Specify the integer x- and y-coordinate of the line's end point.

### `prclBounds`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that describes the rectangle that bounds the unclipped line. Drivers that support hardware line drawing can use this rectangle to quickly determine whether the line fits in a coordinate space small enough to be rendered by the hardware.

### `mix`

Defines how the incoming pattern should be mixed with the data already on the device surface. The low-order byte defines the raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## Return value

**EngLineTo** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

The driver that has hooked [DrvLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvlineto) can call **EngLineTo** when the rendering surface is a device-independent bitmap (DIB).

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvlineto)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)
# DrvTextOut function

## Description

The **DrvTextOut** function is the entry point from GDI that calls for the driver to render a set of glyphs at specified positions.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to write.

### `pstro`

Pointer to a [STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj) structure that defines the glyphs to be rendered and the positions in which to place them.

### `pfo`

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure from which to retrieve information about the font and its glyphs.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that defines the clip region through which all rendering must be done. The driver cannot affect any pixels outside the clip region.

### `prclExtra`

Pointer to a RECTL structure. GDI always sets this parameter to **NULL** in calls to this function. It should be ignored by the driver.

### `prclOpaque`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that represents a single opaque rectangle. This rectangle is lower-right exclusive. Pixels within this rectangle (those that are not foreground and not clipped) are to be rendered with the opaque brush. This rectangle always bounds the text to be drawn. If this parameter is **NULL**, no opaque pixels are to be rendered.

### `pboFore`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that represents the brush object to be used for the foreground pixels. This brush will always be a solid color brush.

### `pboOpaque`

Pointer to a BRUSHOBJ structure that represents the opaque pixels. Both the foreground and background mix modes for this brush are assumed to be R2_COPYPEN. Unless the driver sets the GCAPS_ARBRUSHOPAQUE capabilities bit in the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure, it will always be called with a solid color brush.

### `pptlOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the brush origin for both brushes.

### `mix`

The mix mode that defines the foreground and background raster operations to use for the brush that *pboFore* points to. For more information about mix mode, see Remarks.

## Return value

The return value is **TRUE** if the function is successful; otherwise, it is **FALSE**.

## Remarks

The input parameters to **DrvTextOut** define two sets of pixels: foreground and opaque. The driver must render the surface so that the result is identical to a process where the opaque pixels are rendered first with the opaque brush, and then the foreground pixels are rendered with the foreground brush. Each of these operations is limited by clipping.

The foreground and opaque pixels are regarded as a screen through which color is brushed onto the surface. The glyphs of the font do not have color in themselves.

The input parameters to **DrvTextOut** define the set of glyph pixels, the set of extra rectangles, the opaque rectangle, and the clip region. It is the driver's responsibility to calculate and then render the set of foreground and opaque pixels.

GDI guarantees that **DrvTextOut** and [DrvDestroyFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdestroyfont) never overlap; consequently, the driver can rely on cached information while processing a **DrvTextOut** call.

The mix mode defines how the incoming pattern should be mixed with the data that is already on the device surface. The MIX data type consists of two binary raster operation (ROP2) values packed into a single ULONG. The lowest-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

This is a conditionally required function.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvDestroyFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdestroyfont)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)
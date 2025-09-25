# EngTextOut function

## Description

The **EngTextOut** function causes GDI to render a set of glyphs at specified positions.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to write.

### `pstro`

Pointer to a [STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj) structure that defines the glyphs to be rendered and the positions where they are to be placed.

### `pfo`

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure that is used to retrieve information about the font and its glyphs.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that defines the clip region through which rendering must be done. No pixels can be affected outside this clip region.

### `prclExtra`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure. This parameter should always be **NULL**.

### `prclOpaque`

Pointer to a RECTL structure that identifies a single opaque rectangle that is lower-right exclusive. Pixels within this rectangle (those that are not foreground and not clipped) are to be rendered with the opaque brush. This rectangle always bounds the text to be drawn. If this parameter is **NULL**, no opaque pixels are to be rendered.

### `pboFore`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that represents the brush object to be used for the foreground pixels. This brush will always be a solid color brush.

### `pboOpaque`

Pointer to a BRUSHOBJ structure that represents the brush object for the opaque pixels. Both the foreground and background mix modes for this brush are assumed to be R2_COPYPEN. Unless the driver sets the GCAPS_ARBRUSHOPAQUE capabilities bit in the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure, it will always be called with a solid color brush.

### `pptlOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the brush origin for both brushes. If this parameter is set to 0 when **EngTextOut** is called, some printer drivers may print color images incorrectly. For more information, see **Remarks**.

### `mix` [in]

Specifies foreground and background raster operations (mix modes) for *pboFore*.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

The driver should call **EngTextOut** when it has hooked [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) and cannot render the glyphs.

**Note** The driver cannot punt to **EngTextOut** if it has hooked *DrvTextOut* for a device managed surface.

The input parameters to **EngTextOut** define two sets of pixels: foreground and opaque. The driver must render the surface so the result is identical to a process where the opaque pixels are rendered first with the opaque brush, and then the foreground pixels are rendered with the foreground brush. Each of these operations is limited by clipping.

When the *pptlOrg* parameter of this function is set to 0, some printer drivers print color images incorrectly in Microsoft Windows Server 2003 (Japanese version). Setting *pptlOrg* to 0, a **NULL** pointer value, is interpreted to mean that no brush origin is defined. To prevent this problem, initialize *pptlOrg* with the address of a POINTL structure whose members are set to (0,0), prior to the call to **EngTextOut**.

The foreground and opaque pixels are regarded as a screen through which color is brushed onto the surface. The glyphs of the font do not have color in themselves.

The input parameters to **EngTextOut** define the set of glyph pixels, the set of extra rectangles, the opaque rectangle, and the clip region. The driver must calculate and then render the set of foreground and opaque pixels.

The mix mode defines how the incoming pattern should be mixed with the data already on the device surface. The MIX data type consists of two ROP2 values packed into a single ULONG. The low-order byte defines the foreground raster operation; the next byte defines the background raster operation. For more information about raster operation codes, see the Microsoft Windows SDK documentation.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)
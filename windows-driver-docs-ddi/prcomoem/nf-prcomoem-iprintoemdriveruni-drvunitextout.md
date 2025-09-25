# IPrintOemDriverUni::DrvUniTextOut

## Description

The `IPrintOemDriverUni::DrvUniTextOut` method is provided by the Unidrv driver so that a rendering plug-in using a device-managed drawing surface can easily output text strings.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to write.

### `pstro`

Pointer to a [STROBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-strobj) structure that defines the glyphs to be rendered and the positions in which to place them.

### `pfo`

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-fontobj) structure from which to retrieve information about the font and its glyphs.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-clipobj) structure that defines the clip region through which all rendering must be done. The driver cannot affect any pixels outside the clip region.

### `prclExtra`

Pointer to a RECTL structure. GDI always sets this parameter to **NULL** in calls to this function. It should be ignored by the driver.

### `prclOpaque`

Pointer to a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that represents a single opaque rectangle. This rectangle is bottom-right exclusive. Pixels within this rectangle (those that are not foreground and not clipped) are to be rendered with the opaque brush. This rectangle always bounds the text to be drawn. If this parameter is **NULL**, no opaque pixels are to be rendered.

### `pboFore`

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-brushobj) structure that represents the brush object to be used for the foreground pixels. This brush will always be a solid color brush.

### `pboOpaque`

Pointer to a BRUSHOBJ structure that represents the opaque pixels. Both the foreground and background mix modes for this brush are assumed to be R2_COPYPEN. Unless the driver sets the GCAPS_ARBRUSHOPAQUE capabilities bit in the **flGraphicsCaps** member of the DEVINFO structure, it will always be called with a solid color brush.

### `pptlBrushOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure that defines the brush origin for both brushes.

### `mix`

The foreground and background raster operations (mix modes) for *pboFore*.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemDriverUni::DrvUniTextOut` method is provided by Unidrv for use by rendering plug-ins that support a device-managed drawing surface. Such rendering plug-ins must hook out Unidrv's [DrvTextOut](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvtextout) function, and the `IPrintOemDriverUni::DrvUniTextOut` method is meant to be called from that hooking function. The hooking function must perform text region clipping and text rotation operations. It can then call `IPrintOemDriverUni::DrvUniTextOut` to request Unidrv to create the text string using downloadable fonts (and to perform glyph-based clipping).

If `IPrintOemDriverUni::DrvUniTextOut` cannot create the text string, either because the font is not available or is rotated, it calls the rendering plug-in's [IPrintOemUni::TextOutAsBitmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-textoutasbitmap) method, which draws the text string as a bitmap.

For more information, see [Handling Device-Managed Surfaces](https://learn.microsoft.com/windows-hardware/drivers/print/handling-device-managed-surfaces).
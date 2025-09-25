# IPrintOemUni::TextOutAsBitmap

## Description

The `IPrintOemUni::TextOutAsBitmap` method allows a rendering plug-in to create a bitmap image of a text string, in case a downloadable font is not available.

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

Pointer to a BRUSHOBJ structure that represents the opaque pixels. Both the foreground and background mix modes for this brush are assumed to be R2_COPYPEN. Unless the driver sets the GCAPS_ARBRUSHOPAQUE capabilities bit in the *flGraphicsCaps* member of the DEVINFO structure, it will always be called with a solid color brush.

### `pptlOrg`

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

The `IPrintOemUni::TextOutAsBitmap` method is called from Unidrv's [IPrintOemDriverUni::DrvUniTextOut](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvunitextout) method, if that method cannot create the text string using downloadable fonts, either because the font is not available or is rotated. `IPrintOemUni::TextOutAsBitmap` should create a bitmap image of the text and send it to the print device.

The `IPrintOemUni::TextOutAsBitmap` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "TextOutAsBitmap" as input.

## See also

[IPrintOemDriverUni::DrvUniTextOut](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvunitextout)

[IPrintOemUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuni)

[IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod)
# IPrintOemUni::ImageProcessing

## Description

The `IPrintOemUni::ImageProcessing` method can be used with Unidrv-supported printers to modify image bitmap data, in order to perform color formatting or halftoning. The method can return the modified bitmap to Unidrv or send it directly to the print spooler.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pSrcBitmap`

Caller-supplied pointer to an input [DIB](https://learn.microsoft.com/windows-hardware/drivers/).

### `pBitmapInfoHeader`

Caller-supplied pointer to a BITMAPINFOHEADER structure that describes the bitmap pointed to by *pSrcBitmap*. The BITMAPINFOHEADER structure is described in the Microsoft Windows SDK documentation.

### `pColorTable`

Caller-supplied pointer to a color table. This parameter is used only if the output format is eight bits per pixel. For more information, see the following Remarks section.

When interpreting a bitmap, you must examine the color table. Unidrv can modify the colors in a bitmap, but it will also make corresponding adjustments in the color table, resulting in no net change. However, if you ignore color table changes, and examine only the bitmap, an image might not print properly. For an example, see the discussion of the *pPaletteEntry* parameter in [HT_Get8BPPMaskPalette](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-ht_get8bppmaskpalette).

### `dwCallbackID`

Caller-supplied value assigned to the ***IPCallbackID** attribute of the currently selected option for the ColorMode feature. For more information, see the following Remarks section.

### `pIPParams`

Caller-supplied pointer to an [IPPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-ipparams) structure.

### `ppbResult` [out]

Pointer to a memory location that contains the address of a buffer. The contents of the buffer depend on where the converted DIB should be sent.

If this method intends to send the converted DIB back to Unidrv and is successful in the conversion, it should set **ppbResult* to the address of the buffer containing the converted DIB, and should return S_OK. If the conversion fails, the method should set **ppbResult* to **NULL**, and should return E_FAIL.

If this method intends to send the converted DIB to the spooler and is successful in the conversion, the method should set **ppbResult* to **TRUE**, and should return S_OK. If the conversion fails, the method should set **ppbResult* to **FALSE** and should return E_FAIL. For more information, see the discussion of the ***DevBPP** and ***DevNumOfPlanes** attributes in the Remarks section.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

### Source Bitmap Characteristics

### Destination Bitmap Characteristics

## Remarks

The `IPrintOemUni::ImageProcessing` method is used to modify image bitmaps before they are sent to the print spooler. Its purpose is to provide customized support for color modes and halftoning methods not supported by Unidrv. A printer driver that sends a bitmap to the print spooler (as opposed to sending it back to Unidrv) must set the *DevBPP and *DevNumOfPlanes attributes to zero in the printer's [GPD](https://learn.microsoft.com/windows-hardware/drivers/) file.

If the method is implemented, and if the GPD file entry for the current color format contains an ***IPCallbackID** attribute, Unidrv calls the method each time a bitmap is available. The call is made after GDI renders the bitmap, which is then sent to the spooler. (For information about the ***IPCallbackID** attribute, see [Option Attributes for the ColorMode Feature](https://learn.microsoft.com/windows-hardware/drivers/print/option-attributes-for-the-colormode-feature).)

If the current color mode, as specified by *dwCallbackID*, is one that Unidrv supports, then the `IPrintOemUni::ImageProcessing` method should perform halftoning operations on the received bitmap and return it to Unidrv for spooling. If the current color mode is one that Unidrv does not support, the method must perform halftoning operations and then spool the bitmap.

If the method is performing only halftoning operations, it must do the following:

* Perform halftoning operations on the data, as indicated by the **pHalftoneOption** member of the [IPPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-ipparams) structure.
* Return the modified image data to Unidrv by placing it in a buffer and supplying the buffer's address as the method's return value. The returned buffer can be the one pointed to by *pSrcBitmap*, or it can be one that is locally allocated.

For more information about customizing halftoning operations in Unidrv, see [Customized Halftoning](https://learn.microsoft.com/windows-hardware/drivers/print/customized-halftoning).

To handle customized color formatting, the `IPrintOemUni::ImageProcessing` method must do the following:

* Convert DIB data, described by the *pSrcBitmap* and *pBitmapInfoHeader* parameter values, into the color format indicated by *dwCallbackID*.
* Perform halftoning operations on the data, as indicated by the **pHalftoneOption** member of the [IPPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-ipparams) structure.
* Send the data to the print spooler by calling the [IPrintOemDriverUni::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwritespoolbuf) method.
* Modify the printer's cursor position by making appropriate calls to the [IPrintOemDriverUni::DrvXMoveTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvxmoveto) and [IPrintOemDriverUni::DrvYMoveTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvymoveto) methods.

For more information about customizing color formatting operations in Unidrv, see [Customized Color Formats](https://learn.microsoft.com/windows-hardware/drivers/print/customized-color-formats).

The *dwCallbackID* parameter indicates the type of color formatting, if any, that should be performed. Within the printer's GPD file, each *Option entry for the ColorMode feature describes a color format. If the format requires processing by the `IPrintOemUni::ImageProcessing` method, its *Option entry must contain an ***IPCallbackID** attribute. When Unidrv calls the `IPrintOemUni::ImageProcessing` method, it supplies the attribute value associated with the currently selected option for the ColorMode feature. This value is the *dwCallbackID* parameter's value.

Whether the `IPrintOemUni::ImageProcessing` method is performing color formatting operations and spooling image data, or just performing halftoning operations and returning processed bitmaps to Unidrv, it should export an [IPrintOemUni::MemoryUsage](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-memoryusage) method if it allocates significant amounts of memory for destination bitmaps or other purposes. Otherwise, system performance might be degraded.

If the method is implemented, it is called for every raster region on the page. However, if a region is blank, the **bBlankBand** member of the [IPPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-ipparams) structure is set to **TRUE**, which indicates the block is blank and the data is invalid. Because a band can be broken up into alternating blocks of blank and nonblank regions to optimize performance, the block size does not always correspond to the band size.

The source bitmap described by *pSrcBitmap* and *pBitmapInfoHeader* has the following characteristics:

* DIB contents are top-down ordered and uncompressed.
* The data format is one that is listed in [Handling Color Formats](https://learn.microsoft.com/windows-hardware/drivers/print/handling-color-formats).
* If the format requires a color table, the table is pointed to by *pColorTable*.
* Color data is in PRIMARY_ORDER_CBA format, as explained in the description of the **ulPrimaryOrder** member of the [GDIINFO](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-gdiinfo) structure. In other words, if the color format is RGB or CMY, the least significant *n* bits must contain the blue or yellow value, the next *n* bits must contain the green or magenta value, and the next *n* bits must contain the red or cyan value. Unused bits are in the most significant position. If the format uses 4 bits per pixel, then *n* is 1. For 24 bits per pixel, *n* is 8, as shown in the following figure. For CMYK, the fourth group of *n* bits contains black.

\
![PRIMARY_ORDER_CBA Format](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/images/bitmap.png)
\
The preceding figure depicts color data in PRIMARY_ORDER_CBA format for two pixels, with 24 bits of color data per pixel. Moving from low memory addresses to high memory addresses, there are eight bits of blue data, then eight bits of green data, and then eight bits of red data, after which the pattern repeats. This is also known as BGR device output order.
\
For halftoning operations, in which a processed bitmap is returned to Unidrv, the returned bitmap must have the following characteristics:

* DIB contents must be top-down ordered and uncompressed.
* The data format must be one that is listed in [Handling Color Formats](https://learn.microsoft.com/windows-hardware/drivers/print/handling-color-formats), and it must be compatible with the ***DevBPP** and ***DevNumOfPlanes** attributes of the color format identified by *dwCallbackID*. (For information about these attributes, see [Option Attributes for the ColorMode Feature](https://learn.microsoft.com/windows-hardware/drivers/print/option-attributes-for-the-colormode-feature).)
* If the format requires a color table, the table must be created and its address must be returned in *pColorTable*.
* Color data must be returned in PRIMARY_ORDER_CBA format, as described for the source bitmap.
* The BITMAPINFOHEADER structure specified by *pBitmapInfoHeader* must describe both the input and output bitmaps. The `IPrintOemUni::ImageProcessing` method must not change the structure's contents.

The `IPrintOemUni::ImageProcessing` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "ImageProcessing" as input.

## See also

[HT_Get8BPPMaskPalette](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-ht_get8bppmaskpalette)

[IPrintOemUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuni)

[IPrintOemUni::FilterGraphics](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-filtergraphics)
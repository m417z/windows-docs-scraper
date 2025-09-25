# IPrintOemUni::TTDownloadMethod

## Description

The `IPrintOemUni::TTDownloadMethod` method enables a rendering plug-in to indicate the format that Unidrv should use for a specified TrueType soft font.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pUFObj`

Caller-supplied pointer to a [UNIFONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unifontobj) structure.

### `pdwResult` [out]

Receives one of the following method-supplied constant values:

| Value | Definition |
| --- | --- |
| TTDOWNLOAD_BITMAP | Unidrv should download the specified font as bitmaps. |
| TTDOWNLOAD_DONTCARE | Unidrv can select the font format. |
| TTDOWNLOAD_GRAPHICS | Unidrv should print TrueType fonts as graphics, instead of downloading the font. |
| TTDOWNLOAD_TTOUTLINE | Unidrv should download the specified font as outlines. For more information, see the following Remarks section. |

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemUni::TTDownloadMethod` method's purpose is to allow a rendering plug-in to specify a printer's preferred format for a specified TrueType soft font.

If a rendering plug-in implements the `IPrintOemUni::TTDownloadMethod` method, Unidrv calls the method each time it is ready to send a TrueType font to the print spooler. Unidrv specifies the font type and the `IPrintOemUni::TTDownloadMethod` method should specify the printer's preferred format in the location pointed to by *pdwResult*.

The method should not return TTDOWNLOAD_TTOUTLINE unless the printer can rasterize TrueType fonts. The rendering plug-in is responsible for reading and parsing TrueType font files. Pointers to TrueType font files can be obtained by calling [FONTOBJ_pvTrueTypeFontFile](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-fontobj_pvtruetypefontfile).

The `IPrintOemUni::TTDownloadMethod` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "TTDownLoadMethod" as input.

For additional information see [Customized Font Management](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management).

## See also

[DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj)

[FONTOBJ_pvTrueTypeFontFile](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-fontobj_pvtruetypefontfile)

[IPrintOemUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuni)

[IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod)

[UNIFONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unifontobj)
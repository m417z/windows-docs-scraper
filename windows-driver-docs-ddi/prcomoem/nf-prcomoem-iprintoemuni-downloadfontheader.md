# IPrintOemUni::DownloadFontHeader

## Description

The `IPrintOemUni::DownloadFontHeader` method allows a rendering plug-in for [Unidrv](https://learn.microsoft.com/windows-hardware/drivers/) to send a font's header information to a printer.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pUFObj`

Caller-supplied pointer to a [UNIFONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unifontobj) structure.

### `pdwResult` [out]

Receives a method-supplied value representing the amount of printer memory, in bytes, required to store the font header information. If the operation fails, the returned value should be zero.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemUni::DownloadFontHeader` method is used for supporting soft fonts on printers that do not accept [PCL](https://learn.microsoft.com/windows-hardware/drivers/) commands. Its purpose is to allow a rendering plug-in to obtain font header information from Unidrv and to send the information to the printer.

Information that might be required for constructing a non-[PCL](https://learn.microsoft.com/windows-hardware/drivers/) font header can be obtained by:

* Referencing the [UNIFONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unifontobj) structure that is received as an input argument.
* Calling the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function to get the font's [FONTOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-fontobj) structure.

The method should send the header information to the spooler by calling [IPrintOemDriverUni::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwritespoolbuf).

The `IPrintOemUni::DownloadFontHeader` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "DownloadFontHeader" as input.

If you implement the `IPrintOemUni::DownloadFontHeader` method, you must also implement the [IPrintOemUni::DownloadCharGlyph](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-downloadcharglyph) method.

For additional information see [Customized Font Management](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management).
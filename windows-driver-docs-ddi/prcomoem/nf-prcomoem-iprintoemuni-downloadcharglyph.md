# IPrintOemUni::DownloadCharGlyph

## Description

The `IPrintOemUni::DownloadCharGlyph` method enables a rendering plug-in for Unidrv to send a character glyph for a specified soft font to the printer.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pUFObj`

Caller-supplied pointer to a [UNIFONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unifontobj) structure.

### `hGlyph`

Caller-supplied glyph handle.

### `pdwWidth`

Caller-supplied pointer to receive the method-supplied width of the character.

### `pdwResult` [out]

Receives a method-supplied value representing the amount of printer memory, in bytes, required to store the character glyph. If the operation fails, the returned value should be zero.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemUni::DownloadCharGlyph` method is used for supporting soft fonts on printers that do not accept [PCL](https://learn.microsoft.com/windows-hardware/drivers/) commands. Its purpose is to enable a rendering plug-in to send a character glyph to the printer.

If a rendering plug-in implements the `IPrintOemUni::DownloadCharGlyph` method, Unidrv calls the method immediately after sending the command string specified by the CmdSetCharCode command entry, which is contained in the printer's [GPD](https://learn.microsoft.com/windows-hardware/drivers/) file. (GPD files are described in [Microsoft Universal Printer Driver](https://learn.microsoft.com/windows-hardware/drivers/print/microsoft-universal-printer-driver).) The method should do the following:

* Call the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) function to obtain the glyph image specified by *hGlyph*.
* Call [IPrintOemDriverUni::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwritespoolbuf) to send the glyph to the printer.
* Call the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) function again to obtain the glyph's width, then store the width in the address pointed to by *pdwWidth*.
* Return the amount of printer memory required to store the glyph by placing it in the location specified by *pdwResult*.

The `IPrintOemUni::DownloadCharGlyph` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "DownloadCharGlyph" as input.

If you implement the `IPrintOemUni::DownloadCharGlyph` method, you must also implement the [IPrintOemUni::DownloadFontHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-downloadfontheader) method.

For additional information see [Customized Font Management](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management).
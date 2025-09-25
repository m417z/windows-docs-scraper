# IPrintCorePS2::DrvWriteSpoolBuf

## Description

The `IPrintCorePS2::DrvWriteSpoolBuf` method is provided by the Pscript5 driver so that a [rendering plug-in](https://learn.microsoft.com/windows-hardware/drivers/print/rendering-plug-ins) can send printer data to the spooler.

## Parameters

### `pdevobj` [in]

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pBuffer` [in]

Caller-supplied pointer to a buffer containing data to be sent to the print spooler.

### `cbSize` [in]

Caller-supplied value representing the size, in bytes, of the buffer pointed to by *pBuffer*.

### `pdwResult` [out]

Receives a method-supplied value representing the number of bytes sent to the spooler.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

This method has the same behavior as [IPrintOemDriverPS::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverps-drvwritespoolbuf). This method is supported for any Pscript5 render plug-ins.

## See also

[IPrintCorePS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreps2)

[IPrintOemDriverPS::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverps-drvwritespoolbuf)
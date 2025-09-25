# IPrintOemDriverUni::DrvWriteSpoolBuf

## Description

The `IPrintOemDriverUni::DrvWriteSpoolBuf` method is provided by the Unidrv driver so that a [rendering plug-in](https://learn.microsoft.com/windows-hardware/drivers/print/rendering-plug-ins) can send printer data to the spooler.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pBuffer`

Caller-supplied pointer to a buffer containing data to be sent to the print spooler.

### `cbSize`

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

OEMs use the Unidrv helper function `IPrintOemDriverUni::DrvWriteSpoolBuf` to send output to the printer. If a print job is terminated by the user, `IPrintOemDriverUni::DrvWriteSpoolBuf` returns E_FAIL and can no longer be used to send any data to the printer. When this occurs, certain printers must have a clean-up code fragment sent to them, resetting their states before they can start new print jobs. For these printers, [IPrintOemDriverUni::DrvWriteAbortBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwriteabortbuf) can be used to send this code fragment to the printer.

Rendering plug-ins are described in [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).
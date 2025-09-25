# IPrintOemDriverUni::DrvWriteAbortBuf

## Description

The `IPrintOemDriverUni::DrvWriteAbortBuf` method is provided by the Unidrv driver to allow an OEM [rendering plug-in](https://learn.microsoft.com/windows-hardware/drivers/print/rendering-plug-ins) to send printer clean-up code after a user terminates a print job.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pBuffer`

Caller-supplied pointer to a buffer containing a code fragment to be sent to the printer.

### `cbSize`

Caller-supplied number of bytes in the buffer pointed to by *pBuffer*.

### `dwWait`

Caller-supplied length of time the printer must wait, in milliseconds, before it can start a new print job after the current job is aborted.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

OEMs use [IPrintOemDriverUni::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwritespoolbuf) to send output to the printer. If a print job is terminated by the user, `IPrintOemDriverUni::DrvWriteSpoolBuf` returns E_FAIL and can no longer be used to send any data to the printer. When this occurs, certain printers must have a clean-up code fragment sent to them, resetting their states before they can start new print jobs. For these printers, `IPrintOemDriverUni::DrvWritetAbortBuf` is used to send this code fragment to the printer.

`IPrintOemDriverUni::DrvWriteAbortBuf` can only be called after `IPrintOemDriverUni::DrvWriteSpoolBuf` has returned E_FAIL. `IPrintOemDriverUni::DrvWriteAbortBuf` should not be called more than once per job.

Rendering plug-ins are described in [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).
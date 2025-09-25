# IPrintOemDriverPS::DrvWriteSpoolBuf

## Description

The `IPrintOemDriverPS::DrvWriteSpoolBuf` method is provided by the Pscript5 driver so that [rendering plug-ins](https://learn.microsoft.com/windows-hardware/drivers/print/rendering-plug-ins) can send printer data to the spooler.

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
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

Rendering plug-ins are described in [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).
# PrintDocumentOnPrintProcessor function

## Description

A print processor's `PrintDocumentOnPrintProcessor` function converts a print job from a spooled format into raw data that can be sent to a print monitor.

## Parameters

### `hPrintProcessor` [in]

Caller-supplied print processor handle. This is the handle returned by a previous call to [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor).

### `pDocumentName` [in]

Caller-supplied pointer to the document name.

## Return value

If the operation succeeds, the function should return **TRUE**. If the operation fails, the function should call **SetLastError** to set an error code, and then return **FALSE**.

## Remarks

Print processors are required to export a `PrintDocumentOnPrintProcessor` function. The spooler calls the function after calling [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor). The function's purpose is to read the contents of the file named by *pDocumentName*, convert (if necessary) the file's data to a data stream that can be read by printer hardware, and to send the data stream back to the spooler. The spooler can then send the data stream to the appropriate [print monitor](https://learn.microsoft.com/windows-hardware/drivers/).

If the input format is NT-based operating system EMF, the `PrintDocumentOnPrintProcessor` function can call [GDI functions for print processors](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/). For more information, see [Processing a Print Job](https://learn.microsoft.com/windows-hardware/drivers/print/processing-a-print-job).

The converted data stream must be sent back to the spooler by calling **WritePrinter**, which is described in the Microsoft Windows SDK documentation. For more information, see [Processing a Print Job](https://learn.microsoft.com/windows-hardware/drivers/print/processing-a-print-job).

The `PrintDocumentOnPrintProcessor` function must be written to handle requests to pause, resume, or cancel the print job. For more information, see [ControlPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-controlprintprocessor).

## See also

[ControlPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-controlprintprocessor)

[OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor)
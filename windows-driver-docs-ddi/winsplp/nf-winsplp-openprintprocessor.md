# OpenPrintProcessor function

## Description

A print processor's `OpenPrintProcessor` function prepares the print processor for printing a job and returns a handle.

## Parameters

### `pPrinterName` [in]

Caller-supplied pointer to the name of the printer for which the print processor is being opened.

### `pPrintProcessorOpenData` [in]

Caller-supplied pointer to a [PRINTPROCESSOROPENDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_printprocessoropendata) structure.

## Return value

If the operation succeeds, the function should return a handle that can be used as an input argument for subsequent calls to [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor), [ControlPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-controlprintprocessor), and [ClosePrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-closeprintprocessor). If the operation fails, the function should call **SetLastError** to set an error code, and then return **NULL**.

## Remarks

Print processors are required to export an `OpenPrintProcessor` function. The spooler calls the function when a print job is available. The function should perform initialization operations that are required before a job can be processed, based on the job's data type.

The function must return a handle. Typically, the handle is a pointer to an internal structure. The structure must contain a pointer to the printer's name and a pointer to the printer's [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, both of which are received in the [PRINTPROCESSOROPENDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_printprocessoropendata) structure. These two pointers are required by the print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function, and this latter function receives the handle as input when the spooler calls it.

## See also

[ClosePrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-closeprintprocessor)

[ControlPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-controlprintprocessor)

[PRINTPROCESSOROPENDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_printprocessoropendata)

[PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor)
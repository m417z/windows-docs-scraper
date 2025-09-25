# ClosePrintProcessor function

## Description

A print processor's **ClosePrintProcessor** function completes the printing of a print job and makes the associated handle invalid.

## Parameters

### `hPrintProcessor` [in, out]

Caller-supplied print processor handle. This is the handle returned by a previous call to [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor).

## Return value

If the operation succeeds, the function should return **TRUE**. If the operation fails, the function should call SetLastError to set an error code, and then return **FALSE**.

## Remarks

Print processors are required to export a **ClosePrintProcessor** function. The spooler calls the function after the print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) returns. The function should free all resources that were allocated by the [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor) function.

## See also

[OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor)

[PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor)
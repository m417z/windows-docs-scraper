# GdiStartPageEMF function

## Description

The **GdiStartPageEMF** function performs initialization operations for a physical page of an EMF-formatted print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**, and an error code can be obtained by calling **GetLastError**.

## Remarks

The **GdiStartPageEMF** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

A print processor must call the **GdiStartPageEMF** function each time a new physical page is to be created. It can then call [GdiPlayPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiplaypageemf) for each document page that is to be placed on the physical page.

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).

## See also

[GdiEndPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiendpageemf)
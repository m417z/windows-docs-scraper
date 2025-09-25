# GdiDeleteSpoolFileHandle function

## Description

The **GdiDeleteSpoolFileHandle** function releases a spool file handle.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**.

## Remarks

The **GdiDeleteSpoolFileHandle** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

Print processors should call **GdiDeleteSpoolFileHandle** after calling [GdiEndDocEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdienddocemf), when processing a print job's EMF data stream has been completed. The function calls ClosePrinter (described in the Microsoft Window SDK documentation) to close the printer connection.

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).

## See also

[GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle)
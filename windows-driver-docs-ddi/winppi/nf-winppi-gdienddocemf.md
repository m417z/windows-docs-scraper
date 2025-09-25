# GdiEndDocEMF function

## Description

The **GdiEndDocEMF** function ends EMF playback operations for an EMF-formatted print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**, and an error code can be obtained by calling **GetLastError**.

## Remarks

The **GdiEndDocEMF** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

The function performs operations that must be performed after a print job's EMF records have been played. The function calls the spooler's **EndDoc** function (described in the Microsoft Window SDK documentation), which in turn calls the printer driver's [DrvEndDoc](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenddoc) function.

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).

## See also

[GdiStartDocEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdistartdocemf)
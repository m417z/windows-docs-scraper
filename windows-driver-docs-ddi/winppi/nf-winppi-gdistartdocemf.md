# GdiStartDocEMF function

## Description

The **GdiStartDocEMF** function performs initialization operations for an EMF-formatted print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

### `pDocInfo`

Caller-supplied pointer to a DOCINFOW structure (described in the Microsoft Window SDK documentation).

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**, and an error code can be obtained by calling **GetLastError**.

## Remarks

The **GdiStartDocEMF** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

The function performs initializations that must take place before a print job's EMF records can be played. The function calls the spooler's **StartDoc** function (described in the Window SDK documentation), which in turn calls the printer driver's [DrvStartDoc](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvstartdoc) function.

The print processor must set the **lpszOutput** member of the DOCINFOW structure to the output file name contained in the [PRINTPROCESSOROPENDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_printprocessoropendata) structure, previously received by the [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor) function.

The print processor must set the **lpszDocName** member of the DOCINFOW structure to the document name pointer, previously received by the [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).

## See also

[GdiEndDocEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdienddocemf)
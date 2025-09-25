## Description

The GdiGetPageCount function returns the number of pages in a print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

## Return value

If the operation succeeds, the function returns the number of pages in the current print job. Otherwise the function returns zero.

## Remarks

The GdiGetPageCount function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

The GdiGetPageCount function does not return until all pages have been spooled, even if the print server administrator has specified that print jobs should be printed during spooling. Therefore, this function should not be used unless it is necessary to obtain the total page count before document processing can begin, such as for printing pages in reverse order.

Usually, a better method for determining the page count is to count the number of calls made to [GdiGetPageHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetpagehandle).

For additional information about this set of functions, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).
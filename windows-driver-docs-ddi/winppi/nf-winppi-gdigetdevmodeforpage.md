# GdiGetDevmodeForPage function

## Description

The **GdiGetDevmodeForPage** function returns [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structures for the specified and previous pages of a print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

### `dwPageNumber`

Caller-supplied number of the page for which [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) contents are to be returned.

### `pCurrDM`

Caller-supplied location to receive a pointer to a DEVMODE structure for the page specified by *dwPageNumber*.

### `pLastDM`

Caller-supplied location to receive a pointer to a DEVMODE structure for the page previous to the one specified by *dwPageNumber*.

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise it returns **FALSE**.

## Remarks

The **GdiGetDevmodeForPage** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

Before calling [GdiPlayPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiplaypageemf) to execute a page's EMF instructions, a print processor must call **GdiGetDevmodeForPage** to determine if the DEVMODE structure associated with the page to be printed is the same as that of the last page printed. If the two returned DEVMODE structures are not identical, the print processor must perform the following steps, in order, before calling **GdiPlayPageEMF** for the page:

1. Call [GdiEndPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiendpageemf).
2. Call [GdiResetDCEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiresetdcemf), specifying the DEVMODE pointed to by *pCurrDM*.
3. Call [GdiStartPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdistartpageemf).

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).
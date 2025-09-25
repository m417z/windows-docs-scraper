# GdiResetDCEMF function

## Description

The **GdiResetDCEMF** function resets a printer's device context during playback of a spooled EMF print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

### `pCurrDM`

Caller-supplied pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, obtained by a previous call to [GdiGetDevmodeForPage](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetdevmodeforpage).

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**.

## Remarks

The **GdiResetDCEMF** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

Print processors must call **GdiResetDCEMF** whenever it is necessary to reset the printer's device context. The function must be called whenever the [GdiGetDevmodeForPage](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetdevmodeforpage) function indicates that the current document page's [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure is not identical to that of the previous document page.

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).
# GdiGetDC function

## Description

The **GdiGetDC** function returns a handle to a printer's device context.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

## Return value

If the operation succeeds, the function returns a device context handle. Otherwise the function returns **NULL**.

## Remarks

The **GdiGetDC** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

A print processor can call **GdiGetDC** to obtain a printer's device context handle anytime after calling [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle). The print processor can use the context handle to call Win32 device context functions, in order to perform such operations as applying transformations on the print image.

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).
## Description

The **GdiGetPageHandle** function returns a handle to the specified page within a print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

### `Page`

Caller-supplied page number.

### `pdwPageType`

Caller-supplied pointer to a location that receives the page type. The possible page types are shown in the following table:

| Page Type | Meaning |
|---|---|
| EMF_PP_FORM | The page is a form or has a watermark. (Not currently supported.) |
| EMF_PP_NORMAL | The page is a normal page. |

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**, and an error code can be obtained by calling **GetLastError**.

## Remarks

The **GdiGetPageHandle** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

Print processors must obtain a page handle before calling [GdiPlayPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiplaypageemf) to draw a page. If a Page value is specified that is too large, the function returns ERROR_NO_MORE_ITEMS.

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).
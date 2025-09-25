# GdiPlayPageEMF function

## Description

The **GdiPlayPageEMF** function plays the EMF records within a specified rectangle for one document page of a spooled print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

### `hemf`

Caller-supplied page handle, obtained by calling [GdiGetPageHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetpagehandle), identifying the page for which records are to be played.

### `prectDocument`

Caller-supplied pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure specifying the rectangle into which the page is to be drawn.

### `prectBorder`

Caller-supplied pointer to a RECT structure specifying the page's border rectangle (if any). Can be **NULL**.

### `prectClip`

Caller-supplied pointer to a RECT structure specifying the coordinates of the page's clip region (if any). Can be **NULL**.

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**, and an error code can be obtained by calling **GetLastError**.

## Remarks

The **GdiPlayPageEMF** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

The **GdiPlayPageEMF** function is the means by which a print processor positions a document page or a specified rectangular region of a document page on a physical page. Note that **GdiPlayPageEMF** does not actually print on the device context, but instead prepares a data structure that describes the text and graphics that are to be printed on the physical page(s). The text and graphics are printed to the device context when [GdiEndPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiendpageemf) is called.

The print processor uses *prectClip* to describe the rectangular region to be printed, and *prectDocument* to describe a rectangle into which the document page (or clipped region) must fit. If *prectClip* is **NULL**, the entire document page will be printed. For non-**NULL** values of *prectClip*, only the portion of the document page within the clip region will be printed. The **GdiPlayPageEMF** function then performs the scaling and translation operations required to make the document page (or selected portion) fit into the rectangle.

The *prectBorder* parameter, if it is non-**NULL**, describes a solid-line border rectangle to be drawn around the document page. If *prectBorder* is **NULL**, no such border will be drawn.

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).

## See also

[GdiEndPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiendpageemf)
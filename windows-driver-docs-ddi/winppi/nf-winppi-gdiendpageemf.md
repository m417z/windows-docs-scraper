# GdiEndPageEMF function

## Description

The **GdiEndPageEMF** function ends EMF playback operations for a physical page of an EMF-formatted print job.

## Parameters

### `SpoolFileHandle`

Caller-supplied spool file handle, obtained by a previous call to [GdiGetSpoolFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetspoolfilehandle).

### `dwOptimization`

Caller-supplied flags. The following flag is defined:

#### EMF_PP_COLOR_OPTIMIZATION

Enable color optimization. For more information, see Remarks.

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**, and an error code can be obtained by calling **GetLastError**.

## Remarks

The **GdiEndPageEMF** function is exported by gdi32.dll for use within a print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function.

The **GdiEndPageEMF** function ends the processing of a physical page and causes it to be ejected from the printer. A print processor should call **GdiEndPageEMF** at the following times:

* After the appropriate number of document pages have been placed on the physical page by making calls to [GdiPlayPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiplaypageemf). Note that **GdiPlayPageEMF** does not actually print on the device context, but instead prepares a data structure that describes the text and graphics that are to be printed on the physical page(s). The text and graphics are printed to the device context when **GdiEndPageEMF** is called.
* Whenever a call to [GdiGetDevmodeForPage](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdigetdevmodeforpage) indicates a document page's [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure is different from the previous page's DEVMODE structure.

If this function is called with the *dwOptimization* parameter set to EMF_PP_COLOR_OPTIMIZATION, color optimization is enabled. If *dwOptimization* is set to 0, no optimization is performed. When color optimization is enabled, the presence of color in the spool file causes the spool file to be played in color; the lack of color in the spool file causes the spool file to be played in monochrome.

If you are creating a Unidrv rendering plug-in to generate color watermarks, be advised that color optimization causes color watermarks to be printed in black and white when they are printed on black-and-white documents. To ensure that color watermarks print correctly with color and black-and-white documents, disable color optimization.

The color optimization controlled by the *dwOptimization* parameter can also be controlled by setting the **dwColorOptimization** member of the [ATTRIBUTE_INFO_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2) or [ATTRIBUTE_INFO_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3) structures. This optimization also can be controlled by the Unidrv ***ChangeColorModeOnDoc?** color attribute (see [Color Attributes](https://learn.microsoft.com/windows-hardware/drivers/print/color-attributes)).

For additional information, see [Using GDI Functions in Print Processors](https://learn.microsoft.com/windows-hardware/drivers/print/using-gdi-functions-in-print-processors).

## See also

[GdiPlayPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiplaypageemf)

[GdiStartPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdistartpageemf)
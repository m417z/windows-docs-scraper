# IPdfRendererNative::RenderPageToSurface (windows.data.pdf.interop.h)

## Description

Outputs a single page of a Portable Document Format (PDF) file to a Microsoft DirectX image-data object.

## Parameters

### `pdfPage` [in]

The **IPdfPage** interface as an instance of the [PdfPage](https://learn.microsoft.com/uwp/api/windows.data.pdf.pdfpage) class type-casted to the **IUnknown** interface, `page.as().get()`, representing the page to be output.

### `pSurface` [in]

An instance of the target image-data object.

### `offset` [in]

An x- and y-coordinate offset within the target image-data object to output the page.

### `pRenderParams` [in, optional]

A set of page output properties, such as rendering only a portion of the page, rendering a scaled version of the page, setting the page's background color, and whether the page is shown in high contrast mode.

Provide a null pointer for this parameter to specify default page output properties. For the list of defaults, see [PDF_RENDER_PARAMS](https://learn.microsoft.com/windows/desktop/api/windows.data.pdf.interop/ns-windows-data-pdf-interop-pdf_render_params).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The page output operation succeeded. |

## See also

[IPdfRendererNative](https://learn.microsoft.com/windows/desktop/api/windows.data.pdf.interop/nn-windows-data-pdf-interop-ipdfrenderernative)
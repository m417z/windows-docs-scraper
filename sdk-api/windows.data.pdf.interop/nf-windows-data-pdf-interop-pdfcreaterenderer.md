# PdfCreateRenderer function

## Description

Gets an instance of the [IPdfRendererNative](https://learn.microsoft.com/windows/desktop/api/windows.data.pdf.interop/nn-windows-data-pdf-interop-ipdfrenderernative) interface for displaying a single page of a Portable Document Format (PDF) file.

## Parameters

### `pDevice` [in]

An instance of a Microsoft DirectX Graphics Infrastructure (DXGI) object that is used for producing image data.

### `ppRenderer` [out]

An instance of the high-performance [IPdfRendererNative](https://learn.microsoft.com/windows/desktop/api/windows.data.pdf.interop/nn-windows-data-pdf-interop-ipdfrenderernative) interface for rendering PDF content on a DirectX surface.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function call succeeded. |

## Remarks

 This function is specifically designed for DirectX apps that use C++ and Extensible Application Markup Language (XAML).

The **PdfCreateRenderer** function should be called to display single pages of a PDF file, one at a time. While you could call this function in parallel to display multiple pages at the same time, this could lead to unexpected results.
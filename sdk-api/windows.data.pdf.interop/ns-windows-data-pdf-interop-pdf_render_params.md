# PDF_RENDER_PARAMS structure

## Description

Represents a set of properties for outputting a single page of a Portable Document Format (PDF) file.

## Members

### `pdf.interop.PDF_RENDER_PARAMS.SourceRect`

### `pdf.interop.PDF_RENDER_PARAMS.DestinationWidth`

### `pdf.interop.PDF_RENDER_PARAMS.DestinationHeight`

### `pdf.interop.PDF_RENDER_PARAMS.BackgroundColor`

### `pdf.interop.PDF_RENDER_PARAMS.IgnoreHighContrast`

### `BackgroundColor`

Outputs the page with the specified background color. The default is {1.f, 1.f, 1.f, 1.f}, which represents the values 1.0 for red, green, blue, and alpha channel, respectively. These values, taken together, represent white at full opacity.

### `DestinationHeight`

Outputs the page at the specified height. The default is 0.f.

### `DestinationWidth`

Outputs the page at the specified width. The default is 0.f.

### `IgnoreHighContrast`

False to use the system's high contrast display settings; otherwise true. The default is true.

### `SourceRect`

Outputs a rectangular portion of the original page, as defined by the **D2D_RECT_F** structure's upper-left and lower-right corner x- and y-coordinates. The default value is 0.f for all coordinates.

## Remarks

This structure is used by the [RenderPageToDeviceContext](https://learn.microsoft.com/windows/desktop/api/windows.data.pdf.interop/nf-windows-data-pdf-interop-ipdfrenderernative-renderpagetodevicecontext) and [RenderPageToSurface](https://learn.microsoft.com/windows/desktop/api/windows.data.pdf.interop/nf-windows-data-pdf-interop-ipdfrenderernative-renderpagetosurface) methods.
# PdfRenderParams function

## Description

Populates a [PDF_RENDER_PARAMS](https://learn.microsoft.com/windows/desktop/api/windows.data.pdf.interop/ns-windows-data-pdf-interop-pdf_render_params) structure. A PDF_RENDER_PARAMS structure represents a set of properties for outputting a single page of a Portable Document Format (PDF) file.

## Parameters

### `srcRect` [in]

The rectangular portion of the original page, as defined by the D2D_RECT_F structure's upper-left and lower-right corner x- and y-coordinates. The default value is 0.f for all coordinates.

### `destinationWidth` [in]

The specified width of the page. The default is 0.f.

### `destinationHeight` [in]

The specified height of the page. The default is 0.f.

### `bkColor` [in]

The specified background color of the page. The default is {1.f, 1.f, 1.f, 1.f}, which represents the values 1.0 for red, green, blue, and alpha channel, respectively. These values, taken together, represent white at full opacity.

### `ignoreHighContrast` [in]

False to use the system's high contrast display settings; otherwise true. The default is true.

## Return value

Represents a set of properties for outputting a single page of a Portable Document Format (PDF) file.
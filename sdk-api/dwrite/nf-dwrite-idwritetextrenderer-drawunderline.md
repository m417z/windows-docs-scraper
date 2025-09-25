# IDWriteTextRenderer::DrawUnderline

## Description

 IDWriteTextLayout::[Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwriteinlineobject-draw) calls this function to instruct the client to draw
an underline.

## Parameters

### `clientDrawingContext`

Type: **void***

The application-defined drawing context passed to
IDWriteTextLayout::[Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwriteinlineobject-draw).

### `baselineOriginX`

Type: **FLOAT**

The pixel location (X-coordinate) at the baseline origin of the run where underline applies.

### `baselineOriginY`

Type: **FLOAT**

The pixel location (Y-coordinate) at the baseline origin of the run where underline applies.

### `underline` [in]

Type: **const [DWRITE_UNDERLINE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_underline)***

Pointer to a structure containing underline logical information.

### `clientDrawingEffect`

Type: **IUnknown***

 Application-defined effect to apply to the underline. Usually this argument represents effects such as the foreground brush filling the interior of a line.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 A single underline can be broken into multiple calls, depending on
how the formatting changes attributes. If font sizes/styles change
within an underline, the thickness and offset will be averaged
weighted according to characters.
To get an appropriate starting pixel position, add underline::offset
to the baseline. Otherwise there will be no spacing between the text.
The x coordinate will always be passed as the left side, regardless
of text directionality. This simplifies drawing and reduces the
problem of round-off that could potentially cause gaps or a double
stamped alpha blend. To avoid alpha overlap, round the end points
to the nearest device pixel.

## See also

[IDWriteTextRenderer](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextrenderer)
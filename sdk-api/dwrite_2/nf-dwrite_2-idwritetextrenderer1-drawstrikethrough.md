# IDWriteTextRenderer1::DrawStrikethrough

## Description

 IDWriteTextLayout::[Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwriteinlineobject-draw) calls this function to instruct the client to draw
a strikethrough.

## Parameters

### `clientDrawingContext`

Type: **void***

The application-defined drawing context passed to
IDWriteTextLayout::[Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwriteinlineobject-draw).

### `baselineOriginX`

Type: **FLOAT**

The pixel location (X-coordinate) at the baseline origin of the run where strikethrough applies.

### `baselineOriginY`

Type: **FLOAT**

The pixel location (Y-coordinate) at the baseline origin of the run where strikethrough applies.

### `orientationAngle`

Type: **[DWRITE_GLYPH_ORIENTATION_ANGLE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_glyph_orientation_angle)**

Orientation of the strikethrough.

### `strikethrough` [in]

Type: **const [DWRITE_STRIKETHROUGH](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_strikethrough)***

Pointer to a structure containing strikethrough logical information.

### `clientDrawingEffect`

Type: **IUnknown***

Application-defined effect to apply to the strikethrough. Usually this argument represents effects such as the foreground brush filling the interior of a line.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 A single strikethrough can be broken into multiple calls, depending on
how the formatting changes attributes. Strikethrough is not averaged
across font sizes/styles changes.
To get an appropriate starting pixel position, add strikethrough::offset
to the baseline.
Like underlines, the x coordinate will always be passed as the left side,
regardless of text directionality.

## See also

[IDWriteTextRenderer1](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextrenderer1)
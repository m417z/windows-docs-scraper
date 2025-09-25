# IDWriteTextRenderer1::DrawGlyphRun

## Description

 IDWriteTextLayout::[Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwriteinlineobject-draw) calls this function to instruct the client to
render a run of glyphs.

## Parameters

### `clientDrawingContext`

Type: **void***

The application-defined drawing context passed to
[IDWriteTextLayout::Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-draw).

### `baselineOriginX`

Type: **FLOAT**

The pixel location (X-coordinate) at the baseline origin of the glyph run.

### `baselineOriginY`

Type: **FLOAT**

The pixel location (Y-coordinate) at the baseline origin of the glyph run.

### `orientationAngle`

Type: **[DWRITE_GLYPH_ORIENTATION_ANGLE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_glyph_orientation_angle)**

Orientation of the glyph run.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

The measuring method for glyphs in the run, used with the other properties to determine the rendering mode.

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run)***

Pointer to the glyph run instance to render.

### `glyphRunDescription` [in]

Type: **const [DWRITE_GLYPH_RUN_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run_description)***

A pointer to the glyph run description instance which contains properties of the characters
associated with this run.

### `clientDrawingEffect`

Type: **IUnknown***

Application-defined drawing effects for the glyphs to render. Usually this argument represents effects such as the foreground brush filling the interior of text.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IDWriteTextLayout::Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-draw) function calls this callback function with all the information about glyphs to render. The application implements this callback by mostly delegating the call to the underlying platform's graphics API such as [Direct2D](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-portal) to draw glyphs on the drawing context. An application that uses GDI can implement this callback in terms of the [IDWriteBitmapRenderTarget::DrawGlyphRun](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritebitmaprendertarget-drawglyphrun) method.

## See also

[IDWriteTextRenderer1](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextrenderer1)
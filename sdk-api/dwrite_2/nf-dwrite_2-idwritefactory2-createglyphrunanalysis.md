# IDWriteFactory2::CreateGlyphRunAnalysis

## Description

Creates a glyph run analysis object, which encapsulates information used to render a glyph run.

## Parameters

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run)***

Structure specifying the properties of the glyph run.

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

Optional transform applied to the glyphs and their positions. This transform is applied after the
scaling specified by the emSize and pixelsPerDip.

### `renderingMode`

Type: **DWRITE_RENDERING_MODE**

Specifies the rendering mode, which must be one of the raster rendering modes (i.e., not default
and not outline).

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

Specifies the method to measure glyphs.

### `gridFitMode`

Type: **[DWRITE_GRID_FIT_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_2/ne-dwrite_2-dwrite_grid_fit_mode)**

How to grid-fit glyph outlines. This must be non-default.

### `antialiasMode`

Type: **[DWRITE_TEXT_ANTIALIAS_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_text_antialias_mode)**

Specifies the antialias mode.

### `baselineOriginX`

Type: **FLOAT**

Horizontal position of the baseline origin, in DIPs.

### `baselineOriginY`

Type: **FLOAT**

Vertical position of the baseline origin, in DIPs.

### `glyphRunAnalysis` [out]

Type: **[IDWriteGlyphRunAnalysis](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteglyphrunanalysis)****

Receives a pointer to the newly created object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefactory2)
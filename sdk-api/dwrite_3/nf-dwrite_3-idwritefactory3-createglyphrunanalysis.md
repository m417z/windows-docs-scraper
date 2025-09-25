# IDWriteFactory3::CreateGlyphRunAnalysis

## Description

Creates a glyph-run-analysis object that encapsulates info that [DirectWrite](https://learn.microsoft.com/windows/win32/DirectWrite/direct-write-portal) uses to render a glyph run.

## Parameters

### `glyphRun` [in]

Type: **[DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run)**

A [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run) structure that contains the properties of the glyph run.

### `transform` [in, optional]

Type: **[DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)**

A [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix) structure that describes the optional transform to be applied to glyphs and their positions.

### `renderingMode`

Type: **[DWRITE_RENDERING_MODE1](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_rendering_mode1)**

A [DWRITE_RENDERING_MODE1](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_rendering_mode1)-typed value that specifies the rendering mode, which must be one of the raster rendering modes (that is, not default and not outline).

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

A [DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)-typed value that specifies the measuring method for glyphs in the run. This method uses this value with the other properties to determine the rendering mode.

### `gridFitMode`

Type: **[DWRITE_GRID_FIT_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_2/ne-dwrite_2-dwrite_grid_fit_mode)**

A [DWRITE_GRID_FIT_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_2/ne-dwrite_2-dwrite_grid_fit_mode)-typed value that specifies how to grid-fit glyph outlines. This value must be non-default.

### `antialiasMode`

Type: **[DWRITE_TEXT_ANTIALIAS_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_text_antialias_mode)**

A [DWRITE_TEXT_ANTIALIAS_MODE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_text_antialias_mode)-typed value that specifies the type of antialiasing to use for text when the rendering mode calls for antialiasing.

### `baselineOriginX`

Type: **FLOAT**

The horizontal position of the baseline origin, in DIPs, relative to the upper-left corner of the DIB.

### `baselineOriginY`

Type: **FLOAT**

The vertical position of the baseline origin, in DIPs, relative to the upper-left corner of the DIB.

### `glyphRunAnalysis` [out]

Type: **[IDWriteGlyphRunAnalysis](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteglyphrunanalysis)****

A pointer to a memory block that receives a pointer to a [IDWriteGlyphRunAnalysis](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteglyphrunanalysis) interface for the newly created glyph-run-analysis object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory3)
# IDWriteFactory2::TranslateColorGlyphRun

## Description

This method is called on a glyph run to translate it in to multiple color glyph runs.

## Parameters

### `baselineOriginX`

Type: **FLOAT**

The horizontal baseline origin of the original glyph run.

### `baselineOriginY`

Type: **FLOAT**

The vertical baseline origin of the original glyph run.

### `glyphRun` [in]

Type: **const [DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run)***

Original glyph run containing monochrome glyph IDs.

### `glyphRunDescription` [in, optional]

Type: **const [DWRITE_GLYPH_RUN_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run_description)***

Optional glyph run description.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

Measuring mode used to compute glyph positions if the run contains color glyphs.

### `worldToDeviceTransform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

World transform multiplied by any DPI scaling. This is needed to compute glyph positions if the run contains color glyphs and the
measuring mode is not [DWRITE_MEASURING_MODE_NATURAL](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode).
If this parameter is **NULL**, and identity transform is assumed.

### `colorPaletteIndex`

Type: **UINT32**

Zero-based index of the color palette to use. Valid indices are less than the number of palettes in the font, as
returned by [IDWriteFontFace2::GetColorPaletteCount](https://learn.microsoft.com/windows/win32/api/dwrite_2/nf-dwrite_2-idwritefontface2-getcolorpalettecount).

### `colorLayers` [out]

Type: **[IDWriteColorGlyphRunEnumerator](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritecolorglyphrunenumerator)****

If the original glyph run contains color glyphs, this parameter receives a pointer to
an [IDWriteColorGlyphRunEnumerator](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritecolorglyphrunenumerator) interface.
The client uses the returned interface to get information about glyph runs and associated colors to render instead of the original glyph run.
If the original glyph run does not contain color glyphs, this method returns **DWRITE_E_NOCOLOR** and the output pointer is **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the code calls this method with a glyph run that contains no color information, the method returns **DWRITE_E_NOCOLOR** to
let the application know that it can just draw the original glyph run. If the glyph run contains color information, the function returns an object
that can be enumerated through to expose runs and associated colors. The application then
calls [DrawGlyphRun](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextrenderer-drawglyphrun) with each of the returned glyph runs and foreground colors.

## See also

[IDWriteFactory2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefactory2)
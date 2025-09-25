# IDWriteFactory4::TranslateColorGlyphRun

## Description

Translates a glyph run to a sequence of color glyph runs, which can be rendered to produce a color representation of the original "base" run.

## Parameters

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

Horizontal and vertical origin of the base glyph run in pre-transform coordinates.

### `glyphRun` [in]

Type: **[DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run)**

Pointer to the original "base" glyph run.

### `glyphRunDescription` [in, optional]

Type: **[DWRITE_GLYPH_RUN_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run_description)**

Optional glyph run description.

### `desiredGlyphImageFormats`

Type: **[DWRITE_GLYPH_IMAGE_FORMATS](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_glyph_image_formats)**

Which data formats the runs should be split into.

### `measuringMode`

Type: **[DWRITE_MEASURING_MODE](https://learn.microsoft.com/windows/win32/api/dcommon/ne-dcommon-dwrite_measuring_mode)**

Measuring mode, needed to compute the origins of each glyph.

### `worldAndDpiTransform` [in, optional]

Type: **[DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)**

Matrix converting from the client's coordinate space to device coordinates (pixels), i.e., the world transform multiplied by any DPI scaling.

### `colorPaletteIndex`

Type: **UINT32**

Zero-based index of the color palette to use.
Valid indices are less than the number of palettes in the font, as returned
by [IDWriteFontFace2::GetColorPaletteCount](https://learn.microsoft.com/windows/win32/api/dwrite_2/nf-dwrite_2-idwritefontface2-getcolorpalettecount).

### `colorLayers` [out]

Type: **[IDWriteColorGlyphRunEnumerator1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritecolorglyphrunenumerator1)****

If the function succeeds, receives a pointer to an enumerator object that can be used to obtain the color glyph runs.
If the base run has no color glyphs, then the output pointer is NULL and the method returns DWRITE_E_NOCOLOR.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns DWRITE_E_NOCOLOR if the font has no color information, the glyph run
does not contain any color glyphs, or the specified color palette index
is out of range. In this case, the client should render the original glyph
run. Otherwise, returns a standard HRESULT error code.

## Remarks

Calling [IDWriteFactory2::TranslateColorGlyphRun](https://learn.microsoft.com/windows/win32/api/dwrite_2/nf-dwrite_2-idwritefactory2-translatecolorglyphrun) is equivalent
to calling **IDWriteFactory4::TranslateColorGlyph** run with the following formats specified: DWRITE_GLYPH_IMAGE_FORMATS_TRUETYPE|DWRITE_GLYPH_IMAGE_FORMATS_CFF|DWRITE_GLYPH_IMAGE_FORMATS_COLR.

## See also

[IDWriteFactory4](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory4)
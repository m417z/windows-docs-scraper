## Description

Converts glyph run placements to glyph origins.

## Parameters

### `glyphRun`

Type: **[DWRITE_GLYPH_RUN](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_glyph_run)**

Structure containing the properties of the glyph run.

### `baselineOrigin`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The position of the baseline origin, in DIPs, relative to the upper-left corner of the DIB.

### `glyphOrigins`

Type: [out] **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)***

On return contains the glyph origins for the glyphrun.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

The transform and DPI have no effect on the origin scaling. They are solely used to compute glyph advances when not supplied and align glyphs in pixel aligned measuring modes.

## See also

[IDWriteFactory4](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory4)
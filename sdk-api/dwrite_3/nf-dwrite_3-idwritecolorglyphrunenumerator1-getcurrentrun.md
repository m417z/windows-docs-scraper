# IDWriteColorGlyphRunEnumerator1::GetCurrentRun

## Description

Gets the current color glyph run.

## Parameters

### `colorGlyphRun` [out]

Type: **[DWRITE_COLOR_GLYPH_RUN1](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_color_glyph_run1)**

Receives a pointer to the color glyph run. The pointer remains valid until the next call to
MoveNext or until the interface is released.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Standard HRESULT error code. An error is returned if there is
no current glyph run, i.e., if MoveNext has not yet been called
or if the end of the sequence has been reached.

## See also

[IDWriteColorGlyphRunEnumerator1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritecolorglyphrunenumerator1)
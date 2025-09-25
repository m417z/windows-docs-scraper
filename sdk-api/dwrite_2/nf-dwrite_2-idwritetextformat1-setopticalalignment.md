# IDWriteTextFormat1::SetOpticalAlignment

## Description

Sets the optical margin alignment for the text format.

By default, glyphs are aligned to the margin by the default origin and side-bearings of the glyph. If you specify **DWRITE_OPTICAL_ALIGNMENT_USING_SIDE_BEARINGS**, then the alignment Suses the side bearings to offset the glyph from the aligned edge to ensure the ink of the glyphs are aligned.

## Parameters

### `opticalAlignment`

The optical alignment to set.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextFormat1](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextformat1)
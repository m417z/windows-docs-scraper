# IDWriteTextLayout::GetOverhangMetrics

## Description

Returns the overhangs (in DIPs) of the layout and all
objects contained in it, including text glyphs and inline objects.

## Parameters

### `overhangs` [out]

Type: **[DWRITE_OVERHANG_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_overhang_metrics)***

Overshoots of visible extents (in DIPs) outside the layout.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Underlines and strikethroughs do not contribute to the black box determination, since these are actually drawn by the renderer, which is allowed to draw them in any variety of styles.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)
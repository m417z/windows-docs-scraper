# IDWriteTextLayout3::InvalidateLayout

## Description

Invalidates the layout, forcing layout to remeasure before calling the
metrics or drawing functions. This is useful if the locality of a font
changes, and layout should be redrawn, or if the size of a client
implemented IDWriteInlineObject changes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritetextlayout3)
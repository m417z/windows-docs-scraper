# IDWriteInlineObject::GetOverhangMetrics

## Description

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout) calls this callback function to get the visible extents (in DIPs) of the inline object. In the case of a simple bitmap, with no padding and no overhang, all the overhangs will
simply be zeroes.

The overhangs should be returned relative to the reported size of the object (see [DWRITE_INLINE_OBJECT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_inline_object_metrics)), and should not be baseline
adjusted.

## Parameters

### `overhangs` [out]

Type: **[DWRITE_OVERHANG_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_overhang_metrics)***

Overshoot of visible extents (in DIPs) outside the object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)
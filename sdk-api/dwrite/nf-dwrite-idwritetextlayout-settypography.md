# IDWriteTextLayout::SetTypography

## Description

 Sets font typography features for text within a specified text range.

## Parameters

### `typography`

Type: **[IDWriteTypography](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetypography)***

Pointer to font typography settings.

### `textRange`

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)**

Text range to which this change applies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)
# IDWriteTextLayout::SetFontFamilyName

## Description

 Sets null-terminated font family name for text within a specified text range.

## Parameters

### `fontFamilyName` [in]

Type: **const WCHAR***

The font family name that applies to the entire text string within the range specified by *textRange*.

### `textRange`

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)**

Text range to which this change applies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)
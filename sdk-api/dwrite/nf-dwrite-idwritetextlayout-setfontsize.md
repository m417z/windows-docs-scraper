# IDWriteTextLayout::SetFontSize

## Description

Sets the font size in DIP units for text within a specified text range.

## Parameters

### `fontSize`

Type: **FLOAT**

The font size in DIP units to be set for text in the range specified by *textRange*.

### `textRange`

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)**

Text range to which this change applies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)
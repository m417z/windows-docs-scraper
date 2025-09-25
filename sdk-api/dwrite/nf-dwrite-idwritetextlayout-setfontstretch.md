# IDWriteTextLayout::SetFontStretch

## Description

 Sets the font stretch for text within a specified text range.

## Parameters

### `fontStretch`

Type: **[DWRITE_FONT_STRETCH](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_stretch)**

A value which indicates the type of font stretch for text within the range specified by *textRange*.

### `textRange`

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)**

Text range to which this change applies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)
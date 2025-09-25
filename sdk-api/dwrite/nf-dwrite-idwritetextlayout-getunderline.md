# IDWriteTextLayout::GetUnderline

## Description

 Gets the underline presence of the text at the specified position.

## Parameters

### `currentPosition`

Type: **UINT32**

The current text position.

### `hasUnderline` [out]

Type: **BOOL***

A Boolean flag that indicates whether underline is present at the position indicated by *currentPosition*.

### `textRange` [out, optional]

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)***

The range of text that has the same formatting as the text at the position specified by *currentPosition*. This means the run has the exact formatting as the position specified, including but not limited to the underline.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)
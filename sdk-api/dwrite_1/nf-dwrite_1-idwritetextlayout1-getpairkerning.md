# IDWriteTextLayout1::GetPairKerning

## Description

Gets whether or not pair-kerning is enabled at given position.

## Parameters

### `currentPosition`

Type: **UINT32**

The current text position.

### `isPairKerningEnabled` [out]

Type: **BOOL***

The flag that indicates whether text is pair-kerned.

### `textRange` [out, optional]

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)***

The position range of the current format.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextlayout1)
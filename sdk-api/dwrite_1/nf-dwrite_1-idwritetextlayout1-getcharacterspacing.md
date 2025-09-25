# IDWriteTextLayout1::GetCharacterSpacing

## Description

Gets the spacing between characters.

## Parameters

### `currentPosition`

Type: **UINT32**

The current text position.

### `leadingSpacing` [out]

Type: **FLOAT***

The spacing before each character, in reading order.

### `trailingSpacing` [out]

Type: **FLOAT***

The spacing after each character, in reading order.

### `minimumAdvanceWidth` [out]

Type: **FLOAT***

The minimum advance of each character, to prevent characters from becoming too thin or zero-width. This must be zero or greater.

### `textRange` [out, optional]

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)***

The position range of the current format.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextlayout1)
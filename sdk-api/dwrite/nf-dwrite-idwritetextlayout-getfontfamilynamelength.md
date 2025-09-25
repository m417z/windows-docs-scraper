# IDWriteTextLayout::GetFontFamilyNameLength

## Description

 Get the length of the font family name at the current position.

## Parameters

### `currentPosition`

Type: **UINT32**

The current text position.

### `nameLength` [out]

Type: **UINT32***

When this method returns, contains the size of the character array containing the font family name, in character count, not including the terminated **NULL** character.

### `textRange` [out, optional]

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)***

The range of text that has the same formatting as the text at the position specified by *currentPosition*. This means the run has the exact formatting as the position specified, including but not limited to the font family.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)
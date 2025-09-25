# IDWriteTextLayout::GetLocaleName

## Description

 Gets the locale name of the text at the specified position.

## Parameters

### `currentPosition`

Type: **UINT32**

The position of the text to inspect.

### `localeName` [out]

Type: **WCHAR***

When this method returns, contains the character array receiving the current locale name.

### `nameSize`

Type: **UINT32**

Size of the character array, in character count, including the terminated **NULL** character.

### `textRange` [out, optional]

Type: **[DWRITE_TEXT_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_range)***

The range of text that has the same formatting as the text at the position specified by *currentPosition*. This means the run has the exact formatting as the position specified, including but not limited to the locale name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)
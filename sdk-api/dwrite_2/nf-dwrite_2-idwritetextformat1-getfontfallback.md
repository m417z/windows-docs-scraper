# IDWriteTextFormat1::GetFontFallback

## Description

Gets the current fallback. If none was ever set since creating the layout, it will be nullptr.

## Parameters

### `fontFallback` [out]

Type: **[IDWriteFontFallback](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefontfallback)****

Contains an address of a pointer to the current font fallback object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextFormat1](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextformat1)
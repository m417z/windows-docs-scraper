# IDWriteTextLayout2::SetFontFallback

## Description

Apply a custom font fallback onto layout. If none is specified, the layout uses the system fallback list.

## Parameters

### `fontFallback`

Custom font fallback created from [IDWriteFontFallbackBuilder::CreateFontFallback](https://learn.microsoft.com/windows/win32/api/dwrite_2/nf-dwrite_2-idwritefontfallbackbuilder-createfontfallback) or [IDWriteFactory2::GetSystemFontFallback](https://learn.microsoft.com/windows/win32/api/dwrite_2/nf-dwrite_2-idwritefactory2-getsystemfontfallback).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritetextlayout2)
# IDWriteFactory2::CreateFontFallbackBuilder

## Description

Creates a font fallback builder object.

A font fall back builder allows you to create Unicode font fallback mappings and create a font fall back object from those mappings.

## Parameters

### `fontFallbackBuilder` [out]

Type: **[IDWriteFontFallbackBuilder](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefontfallbackbuilder)****

Contains an address of a pointer to the newly created font fallback builder object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory2](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefactory2)
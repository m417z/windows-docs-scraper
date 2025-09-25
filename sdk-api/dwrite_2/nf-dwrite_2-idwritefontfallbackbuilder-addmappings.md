## Description

Adds all the mappings from an existing font fallback object, which can be used to compose larger fallback definitions. A common scenario is to start with the system fallback from [IDWriteFactory2::GetSystemFontFallback](https://learn.microsoft.com/windows/win32/api/dwrite_2/nf-dwrite_2-idwritefactory2-getsystemfontfallback) to cover the majority of Unicode characters, but then customize a few ranges with additional application-specific entries, either appending them first (to have priority over the system default) before calling **AddMappings**; or calling **AddMappings** first, and then appending custom ranges to fill in any custom gaps.

## Parameters

### `fontFallback`

Type: **[IDWriteFontFallback](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefontfallback)***

An existing font fallback object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFallbackBuilder](https://learn.microsoft.com/windows/win32/api/dwrite_2/nn-dwrite_2-idwritefontfallbackbuilder)
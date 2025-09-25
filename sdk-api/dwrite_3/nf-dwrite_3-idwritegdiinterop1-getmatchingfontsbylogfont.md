# IDWriteGdiInterop1::GetMatchingFontsByLOGFONT

## Description

Gets a list of matching fonts based on the specified LOGFONT values. Only fonts
of that family name will be returned.

## Parameters

### `logFont` [in]

Type: **LOGFONT**

Structure containing a GDI-compatible font description.

### `fontSet` [in]

Type: **[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)***

The font set to search.

### `filteredSet` [out]

Type: **[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)****

>Receives the filtered font set if successful.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteGdiInterop1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritegdiinterop1)
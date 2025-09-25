# IDWriteGdiInterop1::CreateFontFromLOGFONT

## Description

Creates a font object that matches the properties specified by the LOGFONT structure.

## Parameters

### `logFont` [in]

Type: **LOGFONTW**

Structure containing a GDI-compatible font description.

### `fontCollection` [in, optional]

Type: **[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)***

The font collection to search. If NULL, the local system font collection is used.

### `font` [out]

Type: **[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)****

Receives a newly created font object if successful, or NULL in case of error.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteGdiInterop1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritegdiinterop1)
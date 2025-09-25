# IDWriteGdiInterop::CreateFontFromLOGFONT

## Description

 Creates a font object that matches the properties specified by the **LOGFONT** structure.

## Parameters

### `logFont` [in]

Type: **const LOGFONTW***

A structure containing a GDI-compatible font description.

### `font` [out]

Type: **[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)****

When this method returns, contains an address of a pointer to a newly created [IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont) object if successful; otherwise, **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteGdiInterop](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritegdiinterop)
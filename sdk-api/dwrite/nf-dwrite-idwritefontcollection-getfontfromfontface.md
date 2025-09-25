# IDWriteFontCollection::GetFontFromFontFace

## Description

 Gets the font object that corresponds to the same physical font as the specified font face object. The specified physical font must belong
to the font collection.

## Parameters

### `fontFace`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontface)***

A font face object that specifies the physical font.

### `font` [out]

Type: **[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)****

When this method returns, contains the address of a pointer to the newly created font object if successful; otherwise, **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)
# IDWriteFontList::GetFont

## Description

 Gets a font given its zero-based index.

## Parameters

### `index`

Type: **UINT32**

Zero-based index of the font in the font list.

### `font` [out]

Type: **[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)****

When this method returns, contains the address of a pointer to the newly created [IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontList](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontlist)
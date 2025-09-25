# IDWriteFontCollection::GetFontFamily

## Description

 Creates a font family object given a zero-based font family index.

## Parameters

### `index`

Type: **UINT32**

Zero-based index of the font family.

### `fontFamily` [out]

Type: **[IDWriteFontFamily](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfamily)****

When this method returns, contains the address of a pointer to the newly created font family object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)
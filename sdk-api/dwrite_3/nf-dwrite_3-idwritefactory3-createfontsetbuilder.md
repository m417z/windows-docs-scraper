# IDWriteFactory3::CreateFontSetBuilder

## Description

Creates an empty font set builder to add font face references
and create a custom font set.

## Parameters

### `fontSetBuilder` [out]

Type: **[IDWriteFontSetBuilder](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontsetbuilder)****

Holds the newly created font set builder object, or NULL in case of failure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory3)
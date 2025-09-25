# IDWriteFontSetBuilder::AddFontSet

## Description

Appends an existing font set to the one being built, allowing
one to aggregate two sets or to essentially extend an existing one.

## Parameters

### `fontSet` [in]

Type: **[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)***

Font set to append font face references from.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontSetBuilder](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontsetbuilder)
# IDWriteFontSetBuilder::AddFontFaceReference(IDWriteFontFaceReference)

## Description

Adds a reference to a font to the set being built. The necessary metadata will automatically be extracted from the font upon calling CreateFontSet.

## Parameters

### `fontFaceReference` [in]

Type: **[IDWriteFontFaceReference](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontfacereference)***

Font face reference object to add to the set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontSetBuilder](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontsetbuilder)
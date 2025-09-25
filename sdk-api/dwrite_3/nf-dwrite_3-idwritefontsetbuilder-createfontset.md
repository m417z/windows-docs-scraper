# IDWriteFontSetBuilder::CreateFontSet

## Description

Creates a font set from all the font face references added so
far with AddFontFaceReference.

## Parameters

### `fontSet` [out]

Type: **[IDWriteFontSet](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset)****

Contains the newly created font set object, or nullptr in case of failure.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creating a font set takes less time if the references were added with metadata rather than needing to extract the metadata from the
font file.

## See also

[IDWriteFontSetBuilder](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontsetbuilder)
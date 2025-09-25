# IDWriteFontSetBuilder1::AddFontFile

## Description

Adds references to all the fonts in the specified font file. The method parses the font file to determine the fonts and their properties.

## Parameters

### `fontFile` [in]

Type: **IDWriteFontFile***

Font file reference object to add to the set. If the file is not a supported OpenType font file, then a DWRITE_E_FILEFORMAT error will be returned.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[Creating a custom font set using font data loaded into memory](https://learn.microsoft.com/windows/win32/directwrite/custom-font-sets-win10#creating-a-custom-font-set-using-font-data-loaded-into-memory)

[Creating a font set using arbitrary fonts in the local file system](https://learn.microsoft.com/windows/win32/directwrite/custom-font-sets-win10#creating-a-font-set-using-arbitrary-fonts-in-the-local-file-system)

[IDWriteFontSetBuilder1](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontsetbuilder1)
# IDWriteFont::GetFaceNames

## Description

 Gets a localized strings collection containing the face names for the font (such as Regular or Bold), indexed by locale name.

## Parameters

### `names` [out]

Type: **[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)****

When this method returns, contains an address to a pointer to the newly created localized strings object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)
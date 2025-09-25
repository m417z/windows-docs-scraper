# IDWriteTextFormat::GetFontFamilyName

## Description

 Gets a copy of the font family name.

## Parameters

### `fontFamilyName` [out]

Type: **WCHAR***

When this method returns, contains a pointer to a character array, which is null-terminated, that receives the current font family name. The buffer allocated for this array should be at least the size, in elements, of *nameSize*.

### `nameSize`

Type: **UINT32**

The size of the *fontFamilyName* character array, in character count, including the terminated **NULL** character. To find the size of *fontFamilyName*, use [GetFontFamilyNameLength](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextformat-getfontfamilynamelength).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)
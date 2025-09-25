# IDWriteTextFormat::GetLocaleName

## Description

 Gets a copy of the locale name.

## Parameters

### `localeName` [out]

Type: **WCHAR***

Contains a character array that receives the current locale name.

### `nameSize`

Type: **UINT32**

The size of the character array, in character count, including the terminated **NULL** character. Use [GetLocaleNameLength](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextformat-getlocalenamelength) to get the size of the locale name character array.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)
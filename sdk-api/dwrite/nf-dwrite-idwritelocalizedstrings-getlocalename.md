# IDWriteLocalizedStrings::GetLocaleName

## Description

 Copies the locale name with the specified index to the specified array.

## Parameters

### `index`

Type: **UINT32**

Zero-based index of the locale name to be retrieved.

### `localeName` [out]

Type: **WCHAR***

When this method returns, contains a character array, which is null-terminated, that receives the locale name from the language/string pair. The buffer allocated for this array must be at least the size of *size*, in element count.

### `size`

Type: **UINT32**

The size of the array in characters. The size must include space for the terminating
null character.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)
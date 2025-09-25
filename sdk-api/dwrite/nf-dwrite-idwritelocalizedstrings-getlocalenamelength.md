# IDWriteLocalizedStrings::GetLocaleNameLength

## Description

 Gets the length in characters (not including the null terminator) of the locale name with the specified index.

## Parameters

### `index`

Type: **UINT32**

Zero-based index of the locale name to be retrieved.

### `length` [out]

Type: **UINT32***

When this method returns, contains the length in characters of the locale name, not including the null terminator.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)
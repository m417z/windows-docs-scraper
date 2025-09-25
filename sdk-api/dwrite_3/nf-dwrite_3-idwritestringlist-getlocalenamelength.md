# IDWriteStringList::GetLocaleNameLength

## Description

Gets the length in characters (not including the null terminator) of the locale name with the specified index.

## Parameters

### `listIndex`

Type: **UINT32**

Zero-based index of the locale name.

### `length` [out]

Type: **UINT32***

Receives the length in characters, not including the null terminator.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteStringList](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritestringlist)
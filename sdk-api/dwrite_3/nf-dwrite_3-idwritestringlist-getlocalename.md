# IDWriteStringList::GetLocaleName

## Description

Copies the locale name with the specified index to the specified array.

## Parameters

### `listIndex`

Type: **UINT32**

Zero-based index of the locale name.

### `localeName` [out]

Type: **WCHAR***

Character array that receives the locale name.

### `size`

Type: **UINT32**

Size of the array in characters. The size must include space for the terminating null character.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteStringList](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritestringlist)
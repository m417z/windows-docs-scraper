# IDWriteFontCollection::FindFamilyName

## Description

 Finds the font family with the specified family name.

## Parameters

### `familyName` [in]

Type: **const WCHAR***

An array of characters, which is null-terminated, containing the name of the font family. The name is not case-sensitive but must otherwise exactly match a family name in the collection.

### `index` [out]

Type: **UINT32***

When this method returns, contains the zero-based index of the matching font family if the family name was found; otherwise, **UINT_MAX**.

### `exists` [out]

Type: **BOOL***

When this method returns, **TRUE** if the family name exists; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontCollection](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontcollection)
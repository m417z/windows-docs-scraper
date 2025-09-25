# IQueryAssociations::GetKey

## Description

Searches for and retrieves a file or protocol association-related key from the registry.

## Parameters

### `flags` [in]

Type: **[ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str)**

The [ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str) value that can be used to control the search.

### `key` [in]

Type: **[ASSOCKEY](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assockey)**

The [ASSOCKEY](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assockey) value that specifies the type of key that is to be returned.

### `pszExtra` [in, optional]

Type: **LPCWSTR**

A pointer to an optional null-terminated Unicode string with information about the location of the key. It is normally set to a Shell verb such as **open**. Set this parameter to **NULL** if it is not used.

### `phkeyOut` [out]

Type: **HKEY***

A pointer to the key's HKEY value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations)
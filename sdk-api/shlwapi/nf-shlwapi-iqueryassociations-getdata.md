# IQueryAssociations::GetData

## Description

Searches for and retrieves file or protocol association-related binary data from the registry.

## Parameters

### `flags` [in]

Type: **[ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str)**

The [ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str) value that can be used to control the search.

### `data` [in]

Type: **[ASSOCDATA](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assocdata)**

The [ASSOCDATA](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assocdata) value that specifies the type of data that is to be returned.

### `pszExtra` [in, optional]

Type: **LPCWSTR**

A pointer to an optional, null-terminated Unicode string with information about the location of the data. It is normally set to a Shell verb such as **open**. Set this parameter to **NULL** if it is not used.

### `pvOut` [out, optional]

Type: **void***

A pointer to a value that, when this method returns successfully, receives the requested data value.

### `pcbOut` [in, out, optional]

Type: **DWORD***

A pointer to a value that, when this method is called, holds the size of *pvOut*, in bytes. When this method returns successfully, the value contains the size of the data actually retrieved.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations)
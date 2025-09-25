# IMetaDataTables::GetUserString

## Description

Gets the hard-coded string at the specified index in the string column in the current scope.

## Parameters

### `ixUserString` [in]

The index value from which the hard-coded string will be retrieved.

### `pcbData` [out]

A pointer to the size of *ppData*.

### `ppData` [out]

A pointer to a pointer to the returned string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataTables](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables)
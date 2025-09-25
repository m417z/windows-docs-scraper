# IMetaDataTables::GetBlob

## Description

Gets a pointer to the binary large object (BLOB) at the specified column index.

## Parameters

### `ixBlob` [in]

The memory address from which to get *ppData*.

### `pcbData` [out]

A pointer to the size, in bytes, of *ppData*.

### `ppData` [out]

A pointer to a pointer to the binary data retrieved.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataTables](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables)
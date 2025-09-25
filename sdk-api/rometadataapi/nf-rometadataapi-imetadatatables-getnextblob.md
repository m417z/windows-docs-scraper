# IMetaDataTables::GetNextBlob

## Description

Gets the index of the next binary large object (BLOB) in the table.

## Parameters

### `ixBlob` [in]

The index, as returned from a column of BLOBs.

### `pNext` [out]

A pointer to the index of the next BLOB.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataTables](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables)
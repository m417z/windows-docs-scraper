# IMetaDataTables::GetColumn

## Description

Gets a pointer to the value contained in the cell of the specified column and row in the given table.

## Parameters

### `ixTbl` [in]

The index of the table.

### `ixCol` [in]

The index of the column in the table.

### `rid` [in]

The index of the row in the table.

### `pVal` [out]

A pointer to the value in the cell.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataTables](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables)
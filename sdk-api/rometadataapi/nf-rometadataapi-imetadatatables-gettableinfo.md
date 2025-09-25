# IMetaDataTables::GetTableInfo

## Description

Gets the name, row size, number of rows, number of columns, and key column index of the specified table.

## Parameters

### `ixTbl` [in]

The identifier of the table whose properties to return.

### `pcbRow` [out]

A pointer to the size, in bytes, of a table row.

### `pcRows` [out]

A pointer to the number of rows in the table.

### `pcCols` [out]

 A pointer to the number of columns in the table.

### `piKey` [out]

A pointer to the index of the key column, or -1 if the table has no key column.

### `ppName` [out]

A pointer to a pointer to the table name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataTables](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables)
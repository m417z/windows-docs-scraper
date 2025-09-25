# IMetaDataTables::GetColumnInfo

## Description

Gets data about the specified column in the specified table.

## Parameters

### `ixTbl` [in]

The index of the desired table.

### `ixCol` [in]

The index of the desired column.

### `poCol` [out]

A pointer to the offset of the column in the row.

### `pcbCol` [out]

 A pointer to the size, in bytes, of the column.

### `pType` [out]

A pointer to the type of the values in the column.

### `ppName` [out]

A pointer to a pointer to the column name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataTables](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables)
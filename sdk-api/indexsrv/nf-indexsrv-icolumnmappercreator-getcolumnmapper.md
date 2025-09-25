# IColumnMapperCreator::GetColumnMapper

## Description

Retrieves a column mapper object.

## Parameters

### `wcsMachineName` [in]

Machine on which the catalog exists.

### `wcsCatalogName` [in]

Catalog for which column mapper is requested.

### `ppColumnMapper` [out]

Stores the outgoing column mapper pointer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IColumnMapperCreator](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-icolumnmappercreator)
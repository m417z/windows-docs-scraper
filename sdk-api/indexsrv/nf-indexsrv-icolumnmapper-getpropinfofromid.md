# IColumnMapper::GetPropInfoFromId

## Description

Gets the property information from the DBID.

## Parameters

### `pPropId` [in]

Pointer to the property to look up.

### `pwcsName` [out]

The return property name.

### `pPropType` [out]

The return type of the property.

### `puiWidth` [out]

The return property width.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IColumnMapper](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-icolumnmapper)
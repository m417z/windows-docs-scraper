# IColumnMapper::EnumPropInfo

## Description

Gets the i-th entry from the list of properties.

## Parameters

### `iEntry` [in]

i-th entry to retrieve. Note that the entries are 0-based.

### `pwcsName` [out]

The return property name.

### `ppPropId` [out]

The Id of the property.

### `pPropType` [out]

The return type of the property.

### `puiWidth` [out]

The return property width.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IColumnMapper](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-icolumnmapper)
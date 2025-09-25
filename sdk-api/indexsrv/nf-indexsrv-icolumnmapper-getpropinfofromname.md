# IColumnMapper::GetPropInfoFromName

## Description

Gets property information from a name. This will return a DBID pointer in parameter *ppPropId* which now has to be freed by the caller and not by the callee (this class).

## Parameters

### `wcsPropName` [in]

The property name to look up.

### `ppPropId` [out]

The return Id of the property.

### `pPropType` [out]

The return type of the property.

### `puiWidth` [out]

The return property width.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IColumnMapper](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-icolumnmapper)
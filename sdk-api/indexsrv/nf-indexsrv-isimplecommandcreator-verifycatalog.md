# ISimpleCommandCreator::VerifyCatalog

## Description

Validates the catalog location.

## Parameters

### `pwszMachine`

Machine on which the catalog exists.

### `pwszCatalogName`

The catalog name.

## Return value

If the catalog is accessible, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISimpleCommandCreator](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-isimplecommandcreator)
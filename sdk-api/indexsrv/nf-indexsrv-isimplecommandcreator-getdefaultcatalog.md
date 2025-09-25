# ISimpleCommandCreator::GetDefaultCatalog

## Description

Determines the default catalog for the system.

## Parameters

### `pwszCatalogName`

The catalog name.

### `cwcIn`

The size in characters of *pwszCatalogName*.

### `pcwcOut`

Size of the catalog name.

## Return value

If this method succeeds, it returns the contents of the IsapiDefaultCatalogDirectory registry value. Otherwise, it returns an **HRESULT** error code.

## See also

[ISimpleCommandCreator](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-isimplecommandcreator)
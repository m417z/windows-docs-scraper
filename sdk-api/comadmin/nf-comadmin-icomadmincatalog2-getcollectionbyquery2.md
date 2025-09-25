# ICOMAdminCatalog2::GetCollectionByQuery2

## Description

Retrieves a collection of items in the COM+ catalog that satisfy the specified set of query keys.

## Parameters

### `bstrCollectionName` [in]

The name of the collection to be retrieved from the catalog. Possible collection names can be found in the table of collections at [COM+ Administration Collections](https://learn.microsoft.com/windows/desktop/cossdk/com--administration-collections).

### `pVarQueryStrings` [in]

The query keys.

### `ppCatalogCollection` [out, retval]

A pointer to an [ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection) interface pointer containing the result of the query.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
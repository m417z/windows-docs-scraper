# ICOMAdminCatalog::GetCollection

## Description

Retrieves a top-level collection on the COM+ catalog.

## Parameters

### `bstrCollName` [in]

The name of the collection to be retrieved.

### `ppCatalogCollection` [out, retval]

The [ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection) interface for the collection.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

This method retrieves a top-level collection, such as the [Applications](https://learn.microsoft.com/windows/desktop/cossdk/applications) collection, from the COM+ catalog. For related collections that are not top-level collections, such as [Components](https://learn.microsoft.com/windows/desktop/cossdk/components), use the [GetCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-getcollection) method available from the parent collection.

The catalog collection retrieved by **GetCollection** does not contain data from the catalog for items contained within the collection. Use the [Populate](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-populate) method to read in data for items in the collection.

For a complete list of collections in the COM+ catalog, see [COM+ Administration Collections](https://learn.microsoft.com/windows/desktop/cossdk/com--administration-collections).

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
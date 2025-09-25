# ICatalogCollection::GetCollection

## Description

Retrieves a collection from the COM+ catalog that is related to the current collection.

## Parameters

### `bstrCollName` [in]

The name of the collection to be retrieved.

### `varObjectKey` [in]

The [Key](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogobject-get_key) property value of the parent item of the collection to be retrieved.

### `ppCatalogCollection` [out, retval]

The [ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection) interface for the retrieved collection.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

This method does not read in data for items in the retrieved collection from the catalog data store. Use the [Populate](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-populate) method to read in data for items in the collection.

## See also

[ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection)
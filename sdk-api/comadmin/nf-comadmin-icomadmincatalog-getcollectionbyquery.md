# ICOMAdminCatalog::GetCollectionByQuery

## Description

Retrieves a collection on the COM+ catalog given the key property values for all of its parent items.

## Parameters

### `bstrCollName` [in]

The name of the collection to be retrieved.

### `ppsaVarQuery` [in]

A reference to an array consisting of key property values for all parent items of the collection to be retrieved.

### `ppCatalogCollection` [out, retval]

The [ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection) interface for the collection.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The [ICatalogObject::Key](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogobject-get_key) property value for an item is a GUID that serves to uniquely identify it in the COM+ catalog.

The **GetCollectionByQuery** method retrieves any collection on the catalog, given the key values for all of its parent items. However, with the [ErrorInfo](https://learn.microsoft.com/windows/desktop/cossdk/errorinfo), [PropertyInfo](https://learn.microsoft.com/windows/desktop/cossdk/propertyinfo), and [RelatedCollectionInfo](https://learn.microsoft.com/windows/desktop/cossdk/relatedcollectioninfo) collections, this method behaves differently. If you specify any of these collections, **GetCollectionByQuery** always returns that named collection immediately relative to the [Root](https://learn.microsoft.com/windows/desktop/cossdk/root) collection.

To get the [ErrorInfo](https://learn.microsoft.com/windows/desktop/cossdk/errorinfo), [PropertyInfo](https://learn.microsoft.com/windows/desktop/cossdk/propertyinfo), or [RelatedCollectionInfo](https://learn.microsoft.com/windows/desktop/cossdk/relatedcollectioninfo) collection that is relative to an arbitrary collection in the catalog and not relative to the [Root](https://learn.microsoft.com/windows/desktop/cossdk/root) collection, use the [GetCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-getcollection) method from the parent collection.

For a complete list of available collections, see [COM+ Administration Collections](https://learn.microsoft.com/windows/desktop/cossdk/com--administration-collections).

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
# ICatalogCollection::Remove

## Description

Removes an item from the collection, given its index, and re-indexes the items with higher index values.

## Parameters

### `lIndex` [in]

The zero-based index of the item to be removed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The [RemoveEnabled](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-get_removeenabled) property indicates whether the collection supports this method.

When an object is removed, the [Count](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-get_count) property is decremented to reflect the change.

These changes are not reflected in the COM+ catalog data store until you call [SaveChanges](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-savechanges).

## See also

[ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection)
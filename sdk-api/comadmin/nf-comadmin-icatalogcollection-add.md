# ICatalogCollection::Add

## Description

Adds an item to the collection, giving it the high index value.

## Parameters

### `ppCatalogObject` [out, retval]

A pointer to the [ICatalogObject](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogobject) interface pointer for the new object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The [AddEnabled](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-get_addenabled) property indicates whether the collection supports this method.

When an object is added, the [Count](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-get_count) property is incremented to reflect the change.

This change is not reflected in the persisted COM+ catalog data store until you use [SaveChanges](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-savechanges).

## See also

[ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection)
# ICatalogCollection::SaveChanges

## Description

Saves all pending changes made to the collection and the items it contains to the COM+ catalog data store.

## Parameters

### `pcChanges` [out, retval]

The number of changes to the collection that are being attempted; if no changes are pending, the value is zero. If some changes fail, this returned value does not reflect the failure; it is still the number of changes attempted.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## Remarks

For a given item, **SaveChanges** writes all properties to the catalog at the same time. That is, if the write succeeds for that item, all properties as they are set in the item you held are reflected in the catalog. The rule with multiple parties writing the same item in a collection is that the last writer wins entirely. There are no partial updates.

## See also

[ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection)
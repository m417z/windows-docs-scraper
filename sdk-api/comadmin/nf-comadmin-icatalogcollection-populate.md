# ICatalogCollection::Populate

## Description

Populates the collection with data for all items contained in the collection.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## Remarks

Call the [SaveChanges](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-savechanges) method prior to calling the **Populate** method if you want to save pending changes. Unsaved changes made to the collection are lost when you call the **Populate** method.

## See also

[ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection)
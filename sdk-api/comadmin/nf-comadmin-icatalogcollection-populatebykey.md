# ICatalogCollection::PopulateByKey

## Description

Populates a selected list of items in the collection from the COM+ catalog, based on the specified keys.

## Parameters

### `psaKeys` [in]

The [Key](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogobject-get_key) property value of the objects for which data is to be read.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## Remarks

Call the [SaveChanges](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogcollection-savechanges) method prior to calling **PopulateByKey** if you want to save pending changes. Unsaved changes made to the collection are lost when you call **PopulateByKey**.

## See also

[ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection)
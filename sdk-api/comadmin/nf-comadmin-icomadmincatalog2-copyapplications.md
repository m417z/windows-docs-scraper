# ICOMAdminCatalog2::CopyApplications

## Description

Copies the specified COM+ applications from one partition to another.

## Parameters

### `bstrSourcePartitionIDOrName` [in]

The partition GUID or the name of the source partition.

### `pVarApplicationID` [in]

The applications to be copied. Each element of the **Variant** may be a **String** containing an application name or ID, a single catalog object, or a catalog collection (as returned, for example, by the [GetCollectionByQuery2](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-getcollectionbyquery2) method).

### `bstrDestinationPartitionIDOrName` [in]

The partition GUID or the name of the destination partition.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
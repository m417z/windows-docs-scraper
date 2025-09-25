# ICOMAdminCatalog2::GetPartitionName

## Description

Retrieves the name of the specified COM+ application.

## Parameters

### `bstrApplicationIDOrName` [in]

The application ID or name of a COM+ application.

### `pbstrPartitionName` [out, retval]

The partition name associated with the specified application.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_AMBIGUOUS_APPLICATION_NAME** | The named application exists in multiple partitions. To avoid this error, use an application ID instead of a name. |

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
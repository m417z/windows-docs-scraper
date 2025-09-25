# ICOMAdminCatalog2::GetComponentVersionCount

## Description

Retrieves the number of partitions in which a specified component is installed.

## Parameters

### `bstrCLSIDOrProgID` [in]

The class ID or program ID of the component.

### `plVersionCount` [out, retval]

The number of different partitions in which the component is installed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
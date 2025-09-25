# ICOMAdminCatalog2::GetApplicationInstanceIDFromProcessID

## Description

Retrieves the application instance identifier for the specified process identifier.

## Parameters

### `lProcessID` [in]

The process ID.

### `pbstrApplicationInstanceID` [out, retval]

The corresponding application instance ID.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
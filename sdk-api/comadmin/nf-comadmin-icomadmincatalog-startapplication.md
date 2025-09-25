# ICOMAdminCatalog::StartApplication

## Description

Starts the specified COM+ server application. The application components are launched in a dedicated server process.

## Parameters

### `bstrApplIdOrName` [in]

The GUID or name of the application. If a GUID is used, it must be surrounded by braces.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
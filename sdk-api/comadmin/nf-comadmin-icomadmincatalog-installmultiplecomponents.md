# ICOMAdminCatalog::InstallMultipleComponents

## Description

Installs components from multiple files into a COM+ application.

## Parameters

### `bstrApplIDOrName` [in]

The GUID or name of the application.

### `ppsaVarFileNames` [in]

An array of the names of the DLL files that contains the components to be installed.

### `ppsaVarCLSIDs` [in]

An array of CLSIDs for the components to be installed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
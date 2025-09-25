# ICOMAdminCatalog::ShutdownApplication

## Description

Initiates shutdown of a COM+ server application process.

## Parameters

### `bstrApplIDOrName` [in]

The GUID or name of the application.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECT_DOES_NOT_EXIST** | The application does not exist. |

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
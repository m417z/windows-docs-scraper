# ICOMAdminCatalog::RestoreREGDB

## Description

Restores the COM+ class registration database (RegDB) from the specified file. For this to take effect, a system reboot is required.

## Parameters

### `bstrBackupFilePath` [in]

The name of the file to which the database was backed up.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The method is not implemented. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
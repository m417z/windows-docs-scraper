# ICOMAdminCatalog::InstallApplication

## Description

Installs a COM+ application or application proxy from the specified file.

## Parameters

### `bstrApplicationFile` [in]

The name of the file containing the application to be installed.

### `bstrDestinationDirectory` [in, optional]

Where to install the components. If this parameter is blank, the default directory is used.

### `lOptions` [in, optional]

The option flags. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **COMAdminInstallNoUsers**<br><br>0 | Do not install users saved in application file (default). |
| **COMAdminInstallUsers**<br><br>1 | Install users saved in an application file. |
| **COMAdminInstallForceOverwriteOfFiles**<br><br>2 | Overwrite files. |

### `bstrUserId` [in, optional]

The user ID under which to run the application.

### `bstrPassword` [in, optional]

The password under which to run the application.

### `bstrRSN` [in, optional]

A remote server name to use for an application proxy.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **ERROR_INSTALL_FAILURE** | A fatal error occurred during installation. |
| **COMADMIN_E_OBJECT_DOES_NOT_EXIST** | The application does not exist. |
| **COMADMIN_E_OBJECTERRORS** | An error occurred accessing one or more objects. |

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
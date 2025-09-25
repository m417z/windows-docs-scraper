# ICOMAdminCatalog2::InstallPartition

## Description

Imports a partition from a file.

## Parameters

### `bstrFileName` [in]

The file from which the partition is to be imported.

### `bstrDestDirectory` [in]

The path to the directory in which to install the partition components.

### `lOptions` [in]

The install options. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **COMAdminInstallNoUsers**<br><br>0 | Do not install users saved in the partition (default). |
| **COMAdminInstallUsers**<br><br>1 | Install users saved in the partition. |
| **COMAdminInstallForceOverwriteOfFile**<br><br>2 | Overwrite existing files. |

### `bstrUserID` [in]

The user ID under which to install the partition.

### `bstrPassword` [in]

The password for the specified user.

### `bstrRSN` [in]

The name of a remote server to use as a proxy.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
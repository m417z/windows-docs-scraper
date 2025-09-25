# ICOMAdminCatalog2::ExportPartition

## Description

Exports a partition to a file.

An exported partition can be imported using the [InstallPartition](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-installpartition) method.

## Parameters

### `bstrPartitionIDOrName` [in]

The partition GUID or name of the partition.

### `bstrPartitionFileName` [in]

The file to which the specified partition is exported. If no path is specified, the current directory is used. If no file name is specified, the application name is used.

### `lOptions` [in]

The option flags. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **COMAdminExportNoUsers**<br><br>0 | Do not export users with roles (default). |
| **COMAdminExportUsers**<br><br>1 | Export users with roles. |
| **COMAdminExportApplicationProxy**<br><br>2 | Export applications as proxies. |
| **COMAdminExportForceOverwriteOfFile**<br><br>4 | Overwrite existing files. |
| **COMAdminExportIn10Format**<br><br>16 | Export in COM+ 1.0 format. |

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECT_DOES_NOT_EXIST** | The specified partition does not exist. |

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
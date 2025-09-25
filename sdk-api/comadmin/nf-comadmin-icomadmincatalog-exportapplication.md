# ICOMAdminCatalog::ExportApplication

## Description

Exports a COM+ application or application proxy to a file, ready for installation on different computers.

## Parameters

### `bstrApplIDOrName` [in]

The GUID or application name of the application to be exported.

### `bstrApplicationFile` [in]

The name of the file to export the application to, including the file path. If this parameter is **NULL** or an empty string, the **ExportApplication** method returns E_INVALIDARG.
If the path is not specified, the current directory is used.
If a relative path is entered, the path is relative to the current directory.

### `lOptions` [in]

Specifies the application export options. This parameter can be one of more of the following values from the **COMAdminApplicationExportOptions** enumeration type.

| Value | Meaning |
| --- | --- |
| **COMAdminExportNoUsers**<br><br>0 | Export without the users assigned to application roles. |
| **COMAdminExportUsers**<br><br>1 | Export with the users assigned to application roles. |
| **COMAdminExportApplicationProxy**<br><br>2 | Export applications as proxies. |
| **COMAdminExportForceOverwriteOfFile**<br><br>4 | Overwrite existing files. |
| **COMAdminExportIn10Format**<br><br>16 | Export in COM+ 1.0 (Windows 2000) format. |

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECT_DOES_NOT_EXIST** | The application does not exist. |

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
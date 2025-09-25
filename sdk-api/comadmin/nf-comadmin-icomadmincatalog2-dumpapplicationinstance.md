# ICOMAdminCatalog2::DumpApplicationInstance

## Description

Creates a dump file containing an image of the state of the specified application instance (process).

**Note** As of Windows Server 2003, only administrators have read access privileges to the COM+ dump files.

## Parameters

### `bstrApplicationInstanceID` [in]

The GUID of the application instance.

### `bstrDirectory` [in]

The complete path to the directory into which the dump file is placed. Do not include the file name. If this parameter is **NULL**, the default directory is %SystemRoot%\system32\com\dmp.

### `lMaxImages` [in]

The maximum number of dump files that may exist in the dump directory. Specifying this variable prevents dump files from consuming too much storage space.

### `pbstrDumpFile` [out, retval]

The name of the dump file containing the resulting application instance image.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_APP_NOT_RUNNING** | The specified process is not running. |

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
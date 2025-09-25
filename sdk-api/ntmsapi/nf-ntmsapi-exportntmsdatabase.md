# ExportNtmsDatabase function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**ExportNtmsDatabase** function creates a consistent set of database files in the RSM database directory.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access to one or more RSM objects is denied. |
| **ERROR_DATABASE_FAILURE** | The database query or update failed. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is not valid. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_SHARING_VIOLATION** | One of the files that the function must write to is open. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**ExportNtmsDatabase** function is used by backup applications to create a copy of the RSM database. Any existing files in the Export directory are overwritten by this function.

The default location of the database is%SystemRoot%\System32\NtmsData, but this can be set by defining a registry value:

**HKLM**\**System**\**CurrentControlSet**\**Control**\**NTMS**\**NtmsData**

This function creates a subdirectory called Export and places the consistent files there.

## See also

[Database Backup and Recovery Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[ImportNtmsDatabase](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-importntmsdatabase)
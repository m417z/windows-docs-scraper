# ImportNtmsDatabase function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**ImportNtmsDatabase** function causes RSM to import the database files from the database Export directory at the next restart of the RSM.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access to at least one RSM object is denied. |
| **ERROR_DATABASE_FAILURE** | The database query or update failed. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is not valid. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

The
**ImportNtmsDatabase** function is used by backup applications during disaster recovery.

## See also

[Database Backup and Recovery Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[ExportNtmsDatabase](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-exportntmsdatabase)
# SisFreeBackupStructure function

The **SisFreeBackupStructure** function frees the specified SIS backup structure.

## Parameters

*sisBackupStructure* \[in\]

Pointer to the SIS backup structure returned from [**SisCreateBackupStructure**](https://learn.microsoft.com/windows/win32/backup/siscreatebackupstructure).

## Return value

This function returns **TRUE** if it completes successfully and **FALSE** otherwise. Call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get more information about the reason the call failed.

## Remarks

This function should be called after the backup operation is completed for the volume identified by the value of the *sisBackupStructure* parameter.

Note that it is not safe to assume that this only deallocates memory. For example, this function may also perform additional administrative operations for the SIS architecture. Therefore, call this function even if your backup operation will exit immediately afterward.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Sisbkup.h |
| Library<br> | Sisbkup.lib |
| DLL<br> | Sisbkup.dll |

## See also

[**SisCreateBackupStructure**](https://learn.microsoft.com/windows/win32/backup/siscreatebackupstructure)


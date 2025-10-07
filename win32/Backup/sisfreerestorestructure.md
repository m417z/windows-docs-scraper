# SisFreeRestoreStructure function

The **SisFreeRestoreStructure** function frees the memory allocated for the specified SIS restore structure, and performs tasks that prepare the SIS filter to properly set up the links created during the restore operation.

## Parameters

*sisRestoreStructure* \[in\]

Pointer to a SIS restore structure returned from [**SisCreateRestoreStructure**](https://learn.microsoft.com/windows/win32/backup/siscreaterestorestructure).

## Return value

This function returns **TRUE** if it completes successfully and **FALSE** otherwise. Call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get more information about the reason the call failed.

## Remarks

Accessing the SIS links before the call to this function completes can result in a volume check or a partial read of the link's contents.

Note that it is not safe to assume that this only deallocates memory. For example, this function may also perform additional administrative operations for the SIS architecture. Therefore, call this function even if your restore operation will exit immediately afterward.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Sisbkup.h |
| Library<br> | Sisbkup.lib |
| DLL<br> | Sisbkup.dll |

## See also

[**SisCreateRestoreStructure**](https://learn.microsoft.com/windows/win32/backup/siscreaterestorestructure)


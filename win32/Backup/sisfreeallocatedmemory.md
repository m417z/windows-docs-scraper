# SisFreeAllocatedMemory function

The **SisFreeAllocatedMemory** function frees memory allocated by SIS API functions.

## Parameters

*allocatedSpace* \[in\]

Pointer to the memory allocated by the SIS API.

## Return value

This function does not return a value.

## Remarks

After the call to this function completes, the caller may no longer access the freed memory.

This call should be used to deallocate the memory allocated for the *commonStoreRootPathname* parameter strings returned from [**SisCreateBackupStructure**](https://learn.microsoft.com/windows/win32/backup/siscreatebackupstructure) and [**SisCreateRestoreStructure**](https://learn.microsoft.com/windows/win32/backup/siscreaterestorestructure), and the array of strings containing common-store file names returned from **SisCreateBackupStructure**, [**SisCSFilesToBackupForLink**](https://learn.microsoft.com/windows/win32/backup/siscsfilestobackupforlink), **SisCreateRestoreStructure**, and [**SisRestoredLink**](https://learn.microsoft.com/windows/win32/backup/sisrestoredlink). In the latter case, the array itself also must be freed by calling **SisFreeAllocatedMemory**.

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

[**SisCreateRestoreStructure**](https://learn.microsoft.com/windows/win32/backup/siscreaterestorestructure)

[**SisCSFilesToBackupForLink**](https://learn.microsoft.com/windows/win32/backup/siscsfilestobackupforlink)

[**SisRestoredLink**](https://learn.microsoft.com/windows/win32/backup/sisrestoredlink)


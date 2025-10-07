# SisCreateRestoreStructure function

The **SisCreateRestoreStructure** function creates a SIS restore structure based on the supplied information.

## Parameters

*volumeRoot* \[in\]

File name of the volume root, without the trailing backslash, of the volume to be backed up. For example, specify "C:" and not "C:\\". The volume cannot be the system or boot volume.

*sisRestoreStructure* \[out\]

Returned SIS restore structure. This structure should be treated as opaque by the caller.

*commonStoreRootPathname* \[out\]

Fully qualified path name of the specified volume's common store. For example, "c:\\SIS Common Store".

*countOfCommonStoreFilesToRestore* \[out\]

Number of files listed in the *commonStoreFilesToRestore* parameter.

*commonStoreFilesToRestore* \[out\]

Pointer to an array of file names that specifies the list of internal files used by SIS to manage the specified volume. These files should be restored at the same time and in the same manner as the common-store files requested by [**SisCSFilesToBackupForLink**](https://learn.microsoft.com/windows/win32/backup/siscsfilestobackupforlink).

## Return value

This function returns **TRUE** if it completes successfully and **FALSE** otherwise. Call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get more information about the reason the call failed.

## Remarks

This function establishes the restore environment on the specified volume in the way that [**SisCreateBackupStructure**](https://learn.microsoft.com/windows/win32/backup/siscreatebackupstructure) establishes the backup environment on the specified volume.

Note that this function will not necessarily identify the common-store file or files corresponding to a set of SIS links on the backup media if those common store file or files still exist on disk. The contents of a common-store file's data stream never change once it is created, so if the file already exists on the disk there is no need to restore it.

Common-store file names are globally unique to ensure the integrity of the restore operation even if it does not occur on the same SIS-enabled volume that the backup operation has accessed.

After the restore operation is complete, deallocate the memory used by the *commonStoreFilesToRestore* array of strings by calling [**SisFreeAllocatedMemory**](https://learn.microsoft.com/windows/win32/backup/sisfreeallocatedmemory).

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

[**SisCSFilesToBackupForLink**](https://learn.microsoft.com/windows/win32/backup/siscsfilestobackupforlink)

[**SisFreeAllocatedMemory**](https://learn.microsoft.com/windows/win32/backup/sisfreeallocatedmemory)

[**SisFreeBackupStructure**](https://learn.microsoft.com/windows/win32/backup/sisfreebackupstructure)


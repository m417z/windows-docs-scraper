# SisCreateBackupStructure function

The **SisCreateBackupStructure** function creates a SIS backup structure based on the supplied information.

## Parameters

*volumeRoot* \[in\]

File name of the volume root, without the trailing backslash, of the volume to be backed up. For example, specify "C:" and not "C:\\".

*sisBackupStructure* \[out\]

Returned SIS backup structure.

*commonStoreRootPathname* \[out\]

Fully qualified path name of the specified volume's common store. For example, "c:\\SIS Common Store".

*countOfCommonStoreFilesToBackUp* \[out\]

Number of files listed in the *commonStoreFilesToBackUp* parameter.

*commonStoreFilesToBackUp* \[out\]

Pointer to an array of file names that specifies a list of internal files used by SIS to manage the specified volume. These files should be backed up at the same time and in the same manner as the common-store files requested by [**SisCSFilesToBackupForLink**](https://learn.microsoft.com/windows/win32/backup/siscsfilestobackupforlink)

## Return value

This function returns **TRUE** if it completes successfully and **FALSE** otherwise. Call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get more information about the reason the call failed.

## Remarks

This function creates a SIS backup structure, which is used by the SIS backup API to create and maintain a list of the file links on the volume and the original files the links point to. This function should be called only once for each SIS-enabled volume being backed up. All files within the specified volume should be treated as common-store files and backed up only if SIS indicates that they should.

The *countOfCommonStoreFilesToBackUp* and *commonStoreFilesToBackUp* parameters together return a list of files that must be backed up regardless of which links are backed up.

If *countOfCommonStoreFilesToBackUp* is 0, *commonStoreFilesToBackUp* may be a **NULL** pointer. The value of the *commonStoreFilesToBackUp* parameter should be ignored.

After the backup operation is complete, deallocate the memory used by the *commonStoreFilesToBackUp* array of strings by calling [**SisFreeAllocatedMemory**](https://learn.microsoft.com/windows/win32/backup/sisfreeallocatedmemory).

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

[**SisCSFilesToBackupForLink**](https://learn.microsoft.com/windows/win32/backup/siscsfilestobackupforlink)

[**SisFreeAllocatedMemory**](https://learn.microsoft.com/windows/win32/backup/sisfreeallocatedmemory)


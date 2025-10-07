# SisRestoredLink function

The **SisRestoredLink** function returns the names of the common-store file or files pointed to by the specified restored SIS link.

## Parameters

*sisRestoreStructure* \[in\]

Pointer to a SIS restore structure returned from [**SisCreateRestoreStructure**](https://learn.microsoft.com/windows/win32/backup/siscreaterestorestructure).

*restoredFileName* \[in\]

Fully qualified file name of the restored SIS link file.

*reparseData* \[in\]

Pointer to the contents of the SIS reparse point. This reparse point contains data describing the restored SIS link. To retrieve the reparse point data for a file, use the [**FSCTL\_GET\_REPARSE\_POINT**](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_reparse_point) control code.

*reparseDataSize* \[in\]

Size of the contents of the SIS reparse point pointed to by *reparseData*, in bytes.

*countOfCommonStoreFilesToRestore* \[out\]

Number of files listed in the *commonStoreFilesToRestore* parameter.

*commonStoreFilesToRestore* \[out\]

Pointer to an array of common-store file names. These files should be restored at the same time and in the same manner as the common-store files requested by [**SisCSFilesToBackupForLink**](https://learn.microsoft.com/windows/win32/backup/siscsfilestobackupforlink).

If the value of the *countOfCommonStoreFilesToRestore* parameter is not 0, the value of the *commonStoreFilesToRestore* parameter will contain the names of the common-store files to be restored as a result of restoring the SIS link. If the value is 0, then either the common-store files have been returned once, or they are already present on the volume.

## Return value

This function returns **TRUE** if it completes successfully and **FALSE** otherwise. Call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get more information about the reason the call failed.

## Remarks

You should call this function for each SIS link that has been restored.

This function will return each common-store file at most once for each restore operation; any attempt to restore additional SIS links that see the same common-store file will not result in that common-store file name being returned.

This function will not return a common-store file that was not also returned in a call to [**SisCSFilesToBackupForLink**](https://learn.microsoft.com/windows/win32/backup/siscsfilestobackupforlink) during the backup operation, assuming that the SIS reparse data stored on the media has not been corrupted.

When restoring a SIS link, your restore operation should create only the appropriate sparse file, initialize any allocated ranges, and then write the SIS reparse data exactly as it was read during the backup operation. It is crucial that your restore operation create sparse files with unallocated ranges rather than sparse files (or nonsparse files) initialized with zeroes.

Note that this function will not necessarily identify the common-store file or files corresponding to a set of SIS links on the backup media if those common-store file or files still exist on disk. The contents of a common-store file's data stream never changes once it is created, so if the file already exists on the disk there is no need to restore it.

Common-store file names are globally unique to ensure the integrity of the restore operation even if it does not occur on the same SIS-enabled volume that the backup operation has accessed.

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


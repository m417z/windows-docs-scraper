# SisRestoredCommonStoreFile function

The **SisRestoredCommonStoreFile** function reports to the SIS architecture that a common-store file has been written.

## Parameters

*sisRestoreStructure* \[in\]

Pointer to a SIS restore structure returned from [**SisCreateRestoreStructure**](https://learn.microsoft.com/windows/win32/backup/siscreaterestorestructure).

*commonStoreFileName* \[in\]

Name of the restored common-store file.

## Return value

This function returns **TRUE** if it completes successfully and **FALSE** otherwise. Call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get more information about the reason the call failed.

## Remarks

This function should be called after you have restored a common-store file. It notifies the SIS architecture that a new common-store file has been written, so that the SIS architecture can perform internal maintenance tasks such as initializing its internal data structures or fixing the links to the common-store file.

Your restore operation should restore only common-store files reported by [**SisRestoredLink**](https://learn.microsoft.com/windows/win32/backup/sisrestoredlink), even if there are additional common-store files on the backup media. Your restore operation can restore the SIS links and common-store files in any order it chooses; however, it must call **SisRestoredLink** after it restores any link, and it must call this function after it restores any common-store file. Because your restore operation cannot identify which common-store files will be restored until the file names are reported to it as a result of restoring a link, your restore operation will always restore a common-store file after at least one link referring to it is restored. However, you can then restore additional SIS links that point to that common-store file.

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

[**SisRestoredLink**](https://learn.microsoft.com/windows/win32/backup/sisrestoredlink)


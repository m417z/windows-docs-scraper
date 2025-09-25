# SetupRemoveFromDiskSpaceListA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupRemoveFromDiskSpaceList** function removes a file delete or copy operation from a disk-space list.

## Parameters

### `DiskSpace` [in]

Handle to a disk-space list.

### `TargetFilespec` [in]

Pointer to a null-terminated string that specifies the file name of the file to remove from the disk-space list. This is typically a fully qualified path. Otherwise, the path must be relative to the current directory.

### `Operation` [in]

File operation to be removed from the list. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILEOP_DELETE** | A file delete operation. |
| **FILEOP_COPY** | A file copy operation. |

### `Reserved1` [in]

Must be zero.

### `Reserved2` [in]

Must be zero.

## Return value

If the file was not in the list, the
**SetupRemoveFromDiskSpaceList** function returns a nonzero value and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_DRIVE or ERROR_INVALID_NAME. If the file was in the list then upon success the routine returns a nonzero value and
**GetLastError** returns NO_ERROR.

If the routine fails for some other reason, it returns zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns extended error information.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupAddToDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupaddtodiskspacelista)

[SetupRemoveInstallSectionFromDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremoveinstallsectionfromdiskspacelista)

[SetupRemoveSectionFromDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremovesectionfromdiskspacelista)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupRemoveFromDiskSpaceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
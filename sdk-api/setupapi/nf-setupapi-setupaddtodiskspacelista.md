# SetupAddToDiskSpaceListA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupAddToDiskSpaceList** function adds a single delete or copy operation to a disk-space list. To add all the file operations in a section of an INF file, use either
[SetupAddSectionToDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupaddsectiontodiskspacelista), or
[SetupAddInstallSectionToDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupaddinstallsectiontodiskspacelista).

Target disk compression is ignored by this function. Files are assumed to occupy their full size on the target disk.

## Parameters

### `DiskSpace` [in]

Handle to the disk-space list.

### `TargetFilespec` [in]

File name of the file to be added to the disk-space list. You should use a null-terminated string that specifies a fully qualified path. Otherwise, the path must be relative to the current directory.

### `FileSize` [in]

Uncompressed size of the file as it will exist in the target directory, in bytes. You can use
[SetupGetSourceFileSize](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourcefilesizea) to retrieve this information from an INF file. This parameter is ignored for FILEOP_DELETE operations.

### `Operation` [in]

File operation to be added to the list. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILEOP_DELETE** | A file delete operation. |
| **FILEOP_COPY.** | A file copy operation. |

### `Reserved1` [in]

Must be zero.

### `Reserved2` [in]

Must be zero.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupAddToDiskSpaceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
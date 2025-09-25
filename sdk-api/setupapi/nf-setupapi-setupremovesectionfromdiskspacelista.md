# SetupRemoveSectionFromDiskSpaceListA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupRemoveSectionFromDiskSpaceList** function removes the file delete or copy operations listed in a **Copy Files** section of an INF file from a disk-space list.

## Parameters

### `DiskSpace` [in]

Handle to the disk-space list.

### `InfHandle` [in]

Handle to an open INF file that contains the **SourceDisksFiles** section. If *ListInfHandle* is not specified, this INF file must also contain the section specified by *SectionName*.

### `ListInfHandle` [in]

Optional handle to an open INF file that contains the section to remove from the disk-space list. Otherwise, *InfHandle* must contain the section specified by *SectionName*.

### `SectionName` [in]

Pointer to a null-terminated string that specifies the name of the **Copy Files** or **Delete Files** section to remove from the disk-space list.

### `Operation` [in]

File operation to remove from the list. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILEOP_DELETE** | A file delete operation. |
| **FILEOP_COPY** | A file copy operation. |

### `Reserved1` [in]

Must be zero.

### `Reserved2` [in]

Must be zero.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The file operations removed by the
**SetupRemoveSectionFromDiskSpaceList** function are typically those that have been added to the list by using the
[SetupAddSectionToDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupaddsectiontodiskspacelista) function, though this is not a requirement. The
**SetupRemoveSectionFromDiskSpaceList** function ignores files in the INF section that are not listed in the disk-space list.

This function requires a Windows INF file. Some older INF file formats may not be supported.

> [!NOTE]
> The setupapi.h header defines SetupRemoveSectionFromDiskSpaceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupAddSectionToDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupaddsectiontodiskspacelista)

[SetupRemoveFromDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremovefromdiskspacelista)

[SetupRemoveInstallSectionFromDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremoveinstallsectionfromdiskspacelista)
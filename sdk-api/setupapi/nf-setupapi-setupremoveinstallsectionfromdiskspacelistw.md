# SetupRemoveInstallSectionFromDiskSpaceListW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupRemoveInstallSectionFromDiskSpaceList** function searches an **Install** section of an INF file for **CopyFiles** and **DelFiles** lines, and removes the file operations specified in those sections from a disk-space list.

## Parameters

### `DiskSpace` [in]

Handle to a disk-space list.

### `InfHandle` [in]

Handle to an open INF file that contains the **Install** section. If *LayoutInfHandle* is not specified, the INF file must also contain the section specified by *SectionName*.

### `LayoutInfHandle` [in]

Optional handle to the INF file that contains the **SourceDisksFiles** sections. Otherwise, that section is assumed to exist in the INF file specified by *InfHandle*.

### `SectionName` [in]

Pointer to a null-terminated string that specifies the name of the section to be added to the disk-space list.

### `Reserved1` [in]

Must be zero.

### `Reserved2` [in]

Must be zero.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function requires a Windows INF file. Some older INF file formats may not be supported.

> [!NOTE]
> The setupapi.h header defines SetupRemoveInstallSectionFromDiskSpaceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupAddInstallSectionToDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupaddinstallsectiontodiskspacelista)

[SetupRemoveFromDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremovefromdiskspacelista)

[SetupRemoveSectionFromDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremovesectionfromdiskspacelista)
# SetupAdjustDiskSpaceListW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The **SetupAdjustDiskSpaceList** function adjusts the amount of required space for a specified drive.

## Parameters

### `DiskSpace` [in]

Handle to a disk-space list.

### `DriveRoot` [in]

Specifies a valid Win32 drive root. An entry is added to the disk-space list if the specified drive is not currently in the disk-space list.

### `Amount` [in]

Specifies the amount of space to add or remove. Use a negative number to remove space and use a positive number to add space.

### `Reserved1`

Unused, must be zero.

### `Reserved2`

Unused, must be zero.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupAdjustDiskSpaceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
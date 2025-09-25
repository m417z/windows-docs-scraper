# SetupDuplicateDiskSpaceListW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The SetupDuplicateDiskSpaceList function duplicates a disk-space list as a new independent disk-space list.

## Parameters

### `DiskSpace` [in]

Handle to the disk-space list to be duplicated.

### `Reserved1`

Unused, must be zero.

### `Reserved2`

Unused, must be zero.

### `Flags`

Unused, must be zero.

## Return value

If the function succeeds, it returns a handle to the new disk-space list.

If the function fails, it returns null. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDuplicateDiskSpaceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
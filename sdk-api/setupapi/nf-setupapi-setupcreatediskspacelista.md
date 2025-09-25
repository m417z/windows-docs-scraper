# SetupCreateDiskSpaceListA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupCreateDiskSpaceList** function creates a disk-space list.

## Parameters

### `Reserved1` [in]

Unused, must be zero.

### `Reserved2` [in]

Unused, must be zero.

### `Flags` [in]

This parameter can be the following value.

#### SPDSL_IGNORE_DISK

File operations added to the list will ignore files that already exist on the disk. For example, if the disk contains a 5000-byte file, C:\MyDir\MyFile, and you add a Copy operation to the disk-space list for a new version, C:\MyDir\MyFile, that is 6500 bytes, the space required will be 6500 bytes (instead of 1500 bytes, which is the value returned if you do not set SPDSL_IGNORE_DISK).

## Return value

If the function succeeds, it returns a handle to the disk-space list.

If the function fails, it returns null. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupDestroyDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdestroydiskspacelist)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupCreateDiskSpaceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
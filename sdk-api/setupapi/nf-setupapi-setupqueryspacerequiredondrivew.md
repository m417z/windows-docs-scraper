# SetupQuerySpaceRequiredOnDriveW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQuerySpaceRequiredOnDrive** function examines a disk space list to determine the space that is required to perform all the file operations listed for a specific drive.

## Parameters

### `DiskSpace` [in]

The handle to a disk space list.

### `DriveSpec` [in]

A pointer to a null-terminated string that specifies the drive where space information is to be returned.

This should be in the form "x:" or "\\server\share".

### `SpaceRequired` [out]

If the function succeeds, this parameter receives the amount of additional space that is required to process all the file operations listed in the disk space list for the drive that *DriveSpec* specifies.

The
**SetupQuerySpaceRequiredOnDrive** function calculates the additional space required on the target drive by checking for preexisting versions of the files on the target drive.

For example, if a file operation copies a 2000-byte file, FIRST.EXE, to the directory, C:\MYPROG\, the
**SetupQuerySpaceRequiredOnDrive** function automatically checks for a preexisting version of that file in that directory. If a preexisting version of C:\MYPROG\FIRST.EXE has a file size of 500 bytes, the additional space required on the drive C for that operation is 1500 bytes.

The value received can be 0 (zero) or a negative number, if additional space is not required, or if space is freed on the target drive.

If FIRST.EXE in the preceding example is being deleted from the drive C, the amount of space required is 2000 bytes, or the space freed on drive C.

If the preexisting version has a file size of 5000 bytes, then the disk space required to replace it with the 2000-byte FIRST.EXE is 3000 bytes.

File sizes are rounded to disk cluster boundaries.

### `Reserved1` [in]

Reserved; must be 0 (zero).

### `Reserved2` [in]

Reserved; must be 0 (zero).

## Return value

If the function succeeds, the return value is a nonzero value and *SpaceRequired* receives the amount of space required by the file operations listed in the current disk space list.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_DRIVE** | The specified drive is not on the disk-space list. |
| **ERROR_INVALID_HANDLE** | The specified *DiskSpace* handle is invalid. |
| **ERROR_INVALID_PARAMETER** | The specified *DriveSpec* string is invalid. |

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupQueryDrivesInDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupquerydrivesindiskspacelista)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupQuerySpaceRequiredOnDrive as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
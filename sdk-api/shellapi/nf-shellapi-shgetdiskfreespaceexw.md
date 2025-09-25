# SHGetDiskFreeSpaceExW function

## Description

Retrieves disk space information for a disk volume.

## Parameters

### `pszDirectoryName` [in]

Type: **LPCTSTR**

A null-terminated string that specifies the volume for which size information is retrieved. This can be a drive letter, UNC name, or the path of a folder. You cannot use **NULL** to represent the current drive.

### `pulFreeBytesAvailableToCaller` [out, optional]

Type: **[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1)***

Pointer to a value that receives the number of bytes on the volume available to the calling application. If the operating system implements per-user quotas, this value may be less than the total number of free bytes on the volume.

### `pulTotalNumberOfBytes` [out, optional]

Type: **[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1)***

Pointer to a value that receives the total size of the volume, in bytes.

### `pulTotalNumberOfFreeBytes` [out, optional]

Type: **[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1)***

Pointer to a value that receives the number of bytes of free space on the volume.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, **FALSE** otherwise.

## Remarks

The similarly named function [SHGetDiskFreeSpace](https://learn.microsoft.com/previous-versions/bb762176(v=vs.85)) is merely an alias for **SHGetDiskFreeSpaceEx**. When you call **SHGetDiskFreeSpace** you actually call this function.

This function calls the [GetDiskFreeSpaceEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespaceexa) function if it is available on the operating system. If **GetDiskFreeSpaceEx** is not available, it is emulated by calling the [GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) function and manipulating the return values. For additional information, see the documentation for **GetDiskFreeSpaceEx**.

> [!NOTE]
> The shellapi.h header defines SHGetDiskFreeSpaceEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetDiskFreeSpaceEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespaceexa)

[SHGetDiskFreeSpace](https://learn.microsoft.com/previous-versions/bb762176(v=vs.85))
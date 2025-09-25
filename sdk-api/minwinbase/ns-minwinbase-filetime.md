# FILETIME structure

## Description

Contains a 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601 (UTC).

## Members

### `dwLowDateTime`

The low-order part of the file time.

### `dwHighDateTime`

The high-order part of the file time.

## Remarks

To convert a
**FILETIME** structure into a time that is easy to display to a user, use the
[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime) function.

It is not recommended that you add and subtract values from the
**FILETIME** structure to obtain relative times. Instead, you should copy the low- and high-order parts of the file time to a [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1) structure, perform 64-bit arithmetic on the **QuadPart** member, and copy the **LowPart** and **HighPart** members into the **FILETIME** structure.

Do not cast a pointer to a **FILETIME** structure to either a **ULARGE_INTEGER*** or **__int64*** value because it can cause alignment faults on 64-bit Windows.

Not all file systems can record creation and last access time and not all file systems record them in the same manner. For example, on NT FAT, create time has a resolution of 10 milliseconds, write time has a resolution of 2 seconds, and access time has a resolution of 1 day (really, the access date). On NTFS, access time has a resolution of 1 hour. Therefore, the
[GetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletime) function may not return the same file time information set using the
[SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) function. Furthermore, FAT records times on disk in local time. However, NTFS records times on disk in UTC. For more information, see
[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times).

 A function using the **FILETIME** structure can allow for values outside of zero or positive values typically specified by the **dwLowDateTime** and **dwHighDateTime** members. For example, the [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) function uses 0xFFFFFFFF to specify that a file's previous access time should be preserved. For more information, see the topic for the function you are calling.

#### Examples

For an example, see
[Changing a File Time to the Current Time](https://learn.microsoft.com/windows/desktop/SysInfo/changing-a-file-time-to-the-current-time) or [Retrieving the Last-Write Time](https://learn.microsoft.com/windows/desktop/SysInfo/retrieving-the-last-write-time).

## See also

[CompareFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-comparefiletime)

[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times)

[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)

[GetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletime)

[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1)
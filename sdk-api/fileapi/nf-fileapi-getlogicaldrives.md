# GetLogicalDrives function

## Description

Retrieves a bitmask representing the currently available disk drives.

## Return value

If the function succeeds, the return value is a bitmask representing the currently available disk drives. Bit position 0 (the least-significant bit) is drive A, bit position 1 is drive B, bit position 2 is drive C, and so on.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Note that, in this context, "available" means the drive letter is currently assigned to an existing logical drive (for example, a local volume, removable media, or a mapped network share). Bits that are cleared indicate drive letters that are not currently assigned and therefore could be used for future mount points.

Starting in Windows 8 and Windows Server 2012, this function is supported by the following technologies:

| Technology | Supported |
|------------|-----------|
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB does not support volume management functions.

## See also

[GetLogicalDriveStrings](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getlogicaldrivestringsw)

[Volume Management Functions](https://learn.microsoft.com/windows/win32/FileIO/volume-management-functions)
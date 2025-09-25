# GetDiskFreeSpaceExA function

## Description

Retrieves information about the amount of space that is available on a disk volume, which is the total
amount of space, the total amount of free space, and the total amount of free space available to the user that is
associated with the calling thread.

## Parameters

### `lpDirectoryName` [in, optional]

A directory on the disk.

If this parameter is **NULL**, the function uses the root of the current disk.

If this parameter is a UNC name, it must include a trailing backslash, for example,
"\\\\MyServer\\MyShare\\".

This parameter does not have to specify the root directory on a disk. The function accepts any directory on a
disk.

The calling application must have **FILE_LIST_DIRECTORY** access rights for this
directory.

### `lpFreeBytesAvailableToCaller` [out, optional]

A pointer to a variable that receives the total number of free bytes on a disk that are available to the user
who is associated with the calling thread.

This parameter can be **NULL**.

If per-user quotas are being used, this value may be less than the total number of free bytes on a disk.

### `lpTotalNumberOfBytes` [out, optional]

A pointer to a variable that receives the total number of bytes on a disk that are available to the user who
is associated with the calling thread.

This parameter can be **NULL**.

If per-user quotas are being used, this value may be less than the total number of bytes on a disk.

To determine the total number of bytes on a disk or volume, use
[IOCTL_DISK_GET_LENGTH_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_length_info).

### `lpTotalNumberOfFreeBytes` [out, optional]

A pointer to a variable that receives the total number of free bytes on a disk.

This parameter can be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The values obtained by this function are of the type
[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1). Do not truncate these values to 32
bits.

The **GetDiskFreeSpaceEx** function returns zero (0)
for *lpTotalNumberOfFreeBytes* and *lpFreeBytesAvailable* for all
CD requests unless the disk is an unwritten CD in a CD-RW drive.

Symbolic link behavior—If the path points to a symbolic link, the operation is performed
on the target.

> [!NOTE]
> The fileapi.h header defines GetDiskFreeSpaceEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Disk Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-functions)

[GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea)

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)
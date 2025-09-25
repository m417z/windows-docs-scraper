# GetDiskFreeSpaceW function

## Description

Retrieves information about the specified disk, including the amount of free space on the
disk.

## Parameters

### `lpRootPathName` [in]

The root directory of the disk for which information is to be returned. If this parameter is
**NULL**, the function uses the root of the current disk. If this parameter is a UNC name,
it must include a trailing backslash (for example, "\\\\MyServer\\MyShare\\"). Furthermore, a drive
specification must have a trailing backslash (for example, "C:\\"). The calling application must
have **FILE_LIST_DIRECTORY** access rights for this directory.

### `lpSectorsPerCluster` [out]

A pointer to a variable that receives the number of sectors per cluster.

### `lpBytesPerSector` [out]

A pointer to a variable that receives the number of bytes per sector.

### `lpNumberOfFreeClusters` [out]

A pointer to a variable that receives the total number of free clusters on the disk that are available to the
user who is associated with the calling thread.

If per-user disk quotas are in use, this value may be less than the total number of free clusters on the
disk.

### `lpTotalNumberOfClusters` [out]

A pointer to a variable that receives the total number of clusters on the disk that are available to the user
who is associated with the calling thread.

If per-user disk quotas are in use, this value may be less than the total number of clusters on the disk.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [GetDiskFreeSpaceEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespaceexa) function lets
you avoid some of the arithmetic that is required by the
**GetDiskFreeSpace** function.

Symbolic link behavior—If the path points to a symbolic link, the operation is performed
on the target.

> [!NOTE]
> The fileapi.h header defines GetDiskFreeSpace as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Disk Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-functions)

[GetDiskFreeSpaceEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespaceexa)

[GetDriveType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdrivetypea)
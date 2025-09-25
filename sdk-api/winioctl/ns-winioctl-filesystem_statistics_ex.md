# FILESYSTEM_STATISTICS_EX structure

## Description

Contains statistical information from the file system.Support for this structure started with Windows 10.

## Members

### `FileSystemType`

The type of file system.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILESYSTEM_STATISTICS_TYPE_EXFAT**<br><br>3 | The file system is an exFAT file system.<br><br>If this value is set, this structure is followed by an [EXFAT_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-exfat_statistics) structure.<br><br>**Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Vista with SP1. |
| **FILESYSTEM_STATISTICS_TYPE_FAT**<br><br>2 | The file system is a FAT file system.<br><br>If this value is set, this structure is followed by a [FAT_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-fat_statistics) structure. |
| **FILESYSTEM_STATISTICS_TYPE_NTFS**<br><br>1 | The file system is the NTFS file system.<br><br>If this value is set, this structure is followed by an [NTFS_STATISTICS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-ntfs_statistics_ex) structure. |

### `Version`

This member is set to 1 (one).

### `SizeOfCompleteStructure`

The size of this structure plus the size of the file system-specific structure that follows this
structure, multiplied by the number of processors.

This value must be a multiple of 64. For example, if the size of
**FILESYSTEM_STATISTICS_EX** is 0x68, the size of
[NTFS_STATISTICS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-ntfs_statistics_ex) is 0x1D8, and if there are 2
processors, the buffer allocated must be 0x480.

sizeof(**FILESYSTEM_STATISTICS_EX**) =
0x68

sizeof([NTFS_STATISTICS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-ntfs_statistics_ex)) = 0x1D8

Total Size = 0x240

size of the complete structure = 0x240 (which is the aligned length, a multiple of 64)

multiplied by 2 (the number of processors) = 0x480

### `UserFileReads`

The number of read operations on user files.

### `UserFileReadBytes`

The number of bytes read from user files.

### `UserDiskReads`

The number of read operations on user files.

This value includes sub-read operations.

### `UserFileWrites`

The number of write operations on user files.

### `UserFileWriteBytes`

The number of bytes written to user files.

### `UserDiskWrites`

The number of write operations on user files.

This value includes sub-write operations.

### `MetaDataReads`

The number of read operations on metadata files.

### `MetaDataReadBytes`

The number of bytes read from metadata files.

### `MetaDataDiskReads`

The number of read operations on metadata files.

This value includes sub-read operations.

### `MetaDataWrites`

The number of write operations on metadata files.

### `MetaDataWriteBytes`

The number of bytes written to metadata files.

### `MetaDataDiskWrites`

The number of write operations on metadata files.

This value includes sub-write operations.

## Remarks

There are two types of files: user and metadata. User files are available for the user. Metadata files are
system files that contain information, which the file system uses for its internal organization.

The number of read and write operations measured is the number of paging operations.

## See also

[EXFAT_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-exfat_statistics)

[FAT_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-fat_statistics)

[FSCTL_FILESYSTEM_GET_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_filesystem_get_statistics)

[NTFS_STATISTICS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-ntfs_statistics_ex)
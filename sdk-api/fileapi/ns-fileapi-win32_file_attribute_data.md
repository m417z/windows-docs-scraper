# WIN32_FILE_ATTRIBUTE_DATA structure

## Description

Contains attribute information for a file or directory. The
[GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa) function uses this
structure.

## Members

### `dwFileAttributes`

The file system attribute information for a file or directory.

For possible values and their descriptions, see [File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

### `ftCreationTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies when the file or
directory is created.

If the underlying file system does not support creation time, this member is zero.

### `ftLastAccessTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

For a file, the structure specifies when the file is last read from or written to.

For a directory, the structure specifies when the directory is created.

For both files and directories, the specified date is correct, but the time of day is always set to midnight.
If the underlying file system does not support last access time, this member is zero.

### `ftLastWriteTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

For a file, the structure specifies when the file is last written to.

For a directory, the structure specifies when the directory is created.

If the underlying file system does not support last write time, this member is zero.

### `nFileSizeHigh`

The high-order
**DWORD** of the file size.

This member does not have a meaning for directories.

### `nFileSizeLow`

The low-order **DWORD** of the file size.

This member does not have a meaning for directories.

## Remarks

Not all file systems can record creation and last access time, and not all file systems record them in the
same manner. For example, on the FAT file system, create time has a resolution of 10 milliseconds, write time has
a resolution of 2 seconds, and access time has a resolution of 1 day. On the NTFS file
system, access time has a resolution of 1 hour. For more information, see
[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times).

## See also

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa)
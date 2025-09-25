# BY_HANDLE_FILE_INFORMATION structure

## Description

Contains information that the
[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle) function
retrieves.

## Members

### `dwFileAttributes`

The file attributes. For possible values and their descriptions, see
[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

### `ftCreationTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies when a file or
directory is created. If the underlying file system does not support creation time, this member is
zero (0).

### `ftLastAccessTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure. For a file, the structure
specifies the last time that a file is read from or written to. For a directory, the structure specifies when the
directory is created. For both files and directories, the specified date is correct, but the time of day is
always set to midnight. If the underlying file system does not support the last access time, this member is
zero (0).

### `ftLastWriteTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure. For a file, the structure
specifies the last time that a file is written to. For a directory, the structure specifies when the directory
is created. If the underlying file system does not support the last write time, this member is zero (0).

### `dwVolumeSerialNumber`

The serial number of the volume that contains a file.

### `nFileSizeHigh`

The high-order part of the file size.

### `nFileSizeLow`

The low-order part of the file size.

### `nNumberOfLinks`

The number of links to this file. For the FAT file system this member is always 1. For the NTFS file
system, it can be more than 1.

### `nFileIndexHigh`

The high-order part of a unique identifier that is associated with a file. For more information, see
**nFileIndexLow**.

### `nFileIndexLow`

The low-order part of a unique identifier that is associated with a file.

The identifier (low and high parts) and the volume serial number uniquely identify a file on a single
computer. To determine whether two open handles represent the same file, combine the identifier and the volume
serial number for each file and compare them.

The ReFS file system, introduced with Windows Server 2012, includes 128-bit file identifiers. To
retrieve the 128-bit file identifier use the
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) function
with **FileIdInfo** to retrieve the
[FILE_ID_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_info) structure. The 64-bit identifier in this
structure is not guaranteed to be unique on ReFS.

## Remarks

The identifier that is stored in the **nFileIndexHigh** and
**nFileIndexLow** members is called the file ID. Support for file IDs is file
system-specific. File IDs are not guaranteed to be unique over time, because file systems are free to reuse them.
In some cases, the file ID for a file can change over time.

In the FAT file system, the file ID is generated from the first cluster of the containing directory and the
byte offset within the directory of the entry for the file. Some defragmentation products change this byte offset.
(Windows in-box defragmentation does not.) Thus, a FAT file ID can change over time. Renaming a file in the FAT
file system can also change the file ID, but only if the new file name is longer than the old one.

In the NTFS file system, a file keeps the same file ID until it is deleted. You can replace one file with
another file without changing the file ID by using the
[ReplaceFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-replacefilea) function. However, the file ID of the
replacement file, not the replaced file, is retained as the file ID of the resulting file.

Not all file systems can record creation and last access time, and not all file systems record them in the
same manner. For example, on a Windows FAT file system, create time has a resolution of 10 milliseconds, write
time has a resolution of 2 seconds, and access time has a resolution of 1 day (the access date). On the NTFS file
system, access time has a resolution of 1 hour. For more information, see
[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times).

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[FILE_ID_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_info)

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)
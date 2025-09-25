# FILE_FULL_DIR_INFO structure

## Description

Contains directory information for a file. This structure is returned from the
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) function when
**FileFullDirectoryInfo** or **FileFullDirectoryRestartInfo** is
passed in the *FileInformationClass* parameter.

## Members

### `NextEntryOffset`

The offset for the next **FILE_FULL_DIR_INFO**
structure that is returned. Contains zero (0) if no other entries follow this one.

### `FileIndex`

The byte offset of the file within the parent directory. This member is undefined for file systems, such as
NTFS, in which the position of a file within the parent directory is not fixed and can be changed at any time to
maintain sort order.

### `CreationTime`

The time that the file was created.

### `LastAccessTime`

The time that the file was last accessed.

### `LastWriteTime`

The time that the file was last written to.

### `ChangeTime`

The time that the file was last changed.

### `EndOfFile`

The absolute new end-of-file position as a byte offset from the start of the file to the end of the default
data stream of the file. Because this value is zero-based, it actually refers to the first free byte in the
file. In other words, **EndOfFile** is the offset to the byte that immediately follows
the last valid byte in the file.

### `AllocationSize`

The number of bytes that are allocated for the file. This value is usually a multiple of the sector or
cluster size of the underlying physical device.

### `FileAttributes`

The file attributes. This member can be any valid combination of the following attributes:

#### FILE_ATTRIBUTE_ARCHIVE (0x00000020)

#### FILE_ATTRIBUTE_COMPRESSED (0x00000800)

#### FILE_ATTRIBUTE_DIRECTORY (0x00000010)

#### FILE_ATTRIBUTE_HIDDEN (0x00000002)

#### FILE_ATTRIBUTE_NORMAL (0x00000080)

#### FILE_ATTRIBUTE_READONLY (0x00000001)

#### FILE_ATTRIBUTE_SYSTEM (0x00000004)

#### FILE_ATTRIBUTE_TEMPORARY (0x00000100)

### `FileNameLength`

The length of the file name.

### `EaSize`

The size of the extended attributes for the file.

### `FileName`

The first character of the file name string. This is followed in memory by the remainder of the
string.

## Remarks

The **FILE_FULL_DIR_INFO** structure is a subset of the
information in the [FILE_ID_BOTH_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_both_dir_info) structure.
If the additional information is not needed then the operation will be faster as it comes from the directory
entry; **FILE_ID_BOTH_DIR_INFO** contains information
from both the directory entry and the Master File Table (MFT).

No specific access rights are required to
query this information.

All dates and times are in absolute system-time format. Absolute system time is the number of 100-nanosecond
intervals since the start of the year 1601.

This **FILE_FULL_DIR_INFO** structure must be aligned
on a **LONGLONG** (8-byte) boundary. If a buffer contains two or more of these
structures, the **NextEntryOffset** value in each entry, except the last, falls on an
8-byte boundary.

To compile an application that uses this structure, define the **_WIN32_WINNT** macro
as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)
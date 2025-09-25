## Description

Contains the basic information for a file. Used for file handles.

## Members

### `CreationTime`

The time the file was created in [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format,
which is a 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601 (UTC).

### `LastAccessTime`

The time the file was last accessed in [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)
format.

### `LastWriteTime`

The time the file was last written to in [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)
format.

### `ChangeTime`

The time the file was changed in [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)
format.

> [!NOTE]
> The distinction between *ChangeTime* and *LastWriteTime*, is that *LastWriteTime* relates to the underlying data-stream, while *ChangeTime* refers to changes to file metadata, such as renames and attribute changes.

### `FileAttributes`

The file attributes. For a list of attributes, see
[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants). If this is set
to 0 in a **FILE_BASIC_INFO** structure passed to
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle) then none of the
attributes are changed.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)
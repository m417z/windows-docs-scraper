# FILE_STANDARD_INFO structure

## Description

Receives extended information for the file. Used for file handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex).

## Members

### `AllocationSize`

The amount of space that is allocated for the file.

### `EndOfFile`

The end of the file.

### `NumberOfLinks`

The number of links to the file.

### `DeletePending`

**TRUE** if the file in the delete queue; otherwise,
**false**.

### `Directory`

**TRUE** if the file is a directory; otherwise,
**false**.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)
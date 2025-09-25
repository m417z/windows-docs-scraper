# FILE_STREAM_INFO structure

## Description

Receives file stream information for the specified file. Used for any handles. Use only when calling [GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex).

## Members

### `NextEntryOffset`

The offset for the next **FILE_STREAM_INFO** entry that is returned. This member is zero if no other entries follow this one.

### `StreamNameLength`

The length, in bytes, of **StreamName**.

### `StreamSize`

The size, in bytes, of the data stream.

### `StreamAllocationSize`

The amount of space that is allocated for the stream, in bytes. This value is usually a multiple of the sector or cluster size of the underlying physical device.

### `StreamName`

The stream name.

## Remarks

The **FILE_STREAM_INFO** structure is used to enumerate the streams for a file.

Support for named data streams is file-system-specific.

The **FILE_STREAM_INFO** structure must be aligned on a **LONGLONG** (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)
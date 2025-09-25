# GetFileInformationByHandleEx function

## Description

Retrieves file information for the specified file.

For a more basic version of this function for desktop apps, see
[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle).

To set file information using a file handle, see
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle).

## Parameters

### `hFile` [in]

A handle to the file that contains the information to be retrieved.

This handle should not be a pipe handle.

### `FileInformationClass` [in]

A [FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class) enumeration
value that specifies the type of information to be retrieved.

For a table of valid values, see the Remarks section.

### `lpFileInformation` [out]

A pointer to the buffer that receives the requested file information. The structure that is returned
corresponds to the class that is specified by *FileInformationClass*. For a table of
valid structure types, see the Remarks section.

### `dwBufferSize` [in]

The size of the *lpFileInformation* buffer, in bytes.

## Return value

If the function succeeds, the return value is nonzero and file information data is contained in the buffer
pointed to by the *lpFileInformation* parameter.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If *FileInformationClass* is **FileStreamInfo** and the calls
succeed but no streams are returned, the error that is returned by
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is
**ERROR_HANDLE_EOF**.

Certain file information classes behave slightly differently on different operating system releases. These
classes are supported by the underlying drivers, and any information they return is subject to change between
operating system releases.

The following table shows the valid file information class types and their corresponding data structure types
for use with this function.

| *FileInformationClass* value | *lpFileInformation* type |
| --- | --- |
| **FileBasicInfo** (0) | [FILE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_basic_info) |
| **FileStandardInfo** (1) | [FILE_STANDARD_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_standard_info) |
| **FileNameInfo** (2) | [FILE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_name_info) |
| **FileStreamInfo** (7) | [FILE_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_stream_info) |
| **FileCompressionInfo** (8) | [FILE_COMPRESSION_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_compression_info) |
| **FileAttributeTagInfo** (9) | [FILE_ATTRIBUTE_TAG_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_attribute_tag_info) |
| **FileIdBothDirectoryInfo** (0xa) | [FILE_ID_BOTH_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_both_dir_info) |
| **FileIdBothDirectoryRestartInfo** (0xb) | [FILE_ID_BOTH_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_both_dir_info) |
| **FileRemoteProtocolInfo** (0xd) | [FILE_REMOTE_PROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_remote_protocol_info) |
| **FileFullDirectoryInfo** (0xe) | [FILE_FULL_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_full_dir_info) |
| **FileFullDirectoryRestartInfo** (0xf) | [FILE_FULL_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_full_dir_info) |
| **FileStorageInfo** (0x10) | [FILE_STORAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_storage_info) |
| **FileAlignmentInfo** (0x11) | [FILE_ALIGNMENT_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_alignment_info) |
| **FileIdInfo** (0x12) | [FILE_ID_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_info) |
| **FileIdExtdDirectoryInfo** (0x13) | [FILE_ID_EXTD_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_extd_dir_info) |
| **FileIdExtdDirectoryRestartInfo** (0x14) | [FILE_ID_EXTD_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_extd_dir_info) |

### Transacted Operations

If there is a transaction bound to the thread at the time of the call, then the function returns the
compressed file size of the isolated file view. For more information, see
[About Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/about-transactional-ntfs).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)
# FILE_INFO_BY_HANDLE_CLASS enumeration

## Description

Identifies the type of file information that
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) should retrieve
or [SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle) should
set.

## Constants

### `FileBasicInfo`

Minimal information for the file should be retrieved or set. Used for file handles. See
[FILE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_basic_info).

### `FileStandardInfo`

Extended information for the file should be retrieved. Used for file handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_STANDARD_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_standard_info).

### `FileNameInfo`

The file name should be retrieved. Used for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_name_info).

### `FileRenameInfo`

The file name should be changed. Used for file handles. Use only when calling
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle). See
[FILE_RENAME_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_rename_info).

### `FileDispositionInfo`

The file should be deleted. Used for any handles. Use only when calling
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle). See
[FILE_DISPOSITION_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_disposition_info).

### `FileAllocationInfo`

The file allocation information should be changed. Used for file handles. Use only when calling
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle). See
[FILE ALLOCATION INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_allocation_info).

### `FileEndOfFileInfo`

The end of the file should be set. Use only when calling
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle). See
[FILE_END_OF_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_end_of_file_info).

### `FileStreamInfo`

File stream information for the specified file should be retrieved. Used for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_stream_info).

### `FileCompressionInfo`

File compression information should be retrieved. Used for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_COMPRESSION_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_compression_info).

### `FileAttributeTagInfo`

File attribute information should be retrieved. Used for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_ATTRIBUTE_TAG_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_attribute_tag_info).

### `FileIdBothDirectoryInfo`

Files in the specified directory should be retrieved. Used for directory handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). The number
of files returned for each call to
**GetFileInformationByHandleEx** depends on
the size of the buffer that is passed to the function. Any subsequent calls to
**GetFileInformationByHandleEx** on the same
handle will resume the enumeration operation after the last file is returned. See
[FILE_ID_BOTH_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_both_dir_info).

### `FileIdBothDirectoryRestartInfo`

Identical to **FileIdBothDirectoryInfo**, but forces the enumeration operation to
start again from the beginning. See
[FILE_ID_BOTH_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_both_dir_info).

### `FileIoPriorityHintInfo`

Priority hint information should be set. Use only when calling
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle). See
[FILE_IO_PRIORITY_HINT_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_io_priority_hint_info).

### `FileRemoteProtocolInfo`

File remote protocol information should be retrieved. Use for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_REMOTE_PROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_remote_protocol_info).

### `FileFullDirectoryInfo`

Files in the specified directory should be retrieved. Used for directory handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_FULL_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_full_dir_info).

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012

### `FileFullDirectoryRestartInfo`

Identical to **FileFullDirectoryInfo**, but forces the enumeration operation to
start again from the beginning. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_FULL_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_full_dir_info).

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012

### `FileStorageInfo`

File storage information should be retrieved. Use for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_STORAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_storage_info).

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012

### `FileAlignmentInfo`

File alignment information should be retrieved. Use for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_ALIGNMENT_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_alignment_info).

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012

### `FileIdInfo`

File information should be retrieved. Use for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_ID_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_info).

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012

### `FileIdExtdDirectoryInfo`

Files in the specified directory should be retrieved. Used for directory handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_ID_EXTD_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_extd_dir_info).

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012

### `FileIdExtdDirectoryRestartInfo`

Identical to **FileIdExtdDirectoryInfo**, but forces the enumeration operation to
start again from the beginning. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). See
[FILE_ID_EXTD_DIR_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_extd_dir_info).

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012

### `FileDispositionInfoEx`

### `FileRenameInfoEx`

### `MaximumFileInfoByHandleClass`

This value is used for validation. Supported values are less than this value.

## Remarks

As noted in the preceding section, some file information classes are valid only for use with
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex). Others are
valid only for use with
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle). Where neither
function is mentioned, the information class is valid with both functions.

## See also

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)
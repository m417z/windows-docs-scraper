# FILE_FULL_DIR_INFORMATION structure

## Description

The **FILE_FULL_DIR_INFORMATION** structure is used to query detailed information for the files in a directory.

## Members

### `NextEntryOffset`

Byte offset of the next **FILE_FULL_DIR_INFORMATION** entry, if multiple entries are present in a buffer. This member is zero if no other entries follow this one.

### `FileIndex`

Byte offset of the file within the parent directory. This member is undefined for file systems, such as NTFS, in which the position of a file within the parent directory is not fixed and can be changed at any time to maintain sort order.

### `CreationTime`

Time when the file was created.

### `LastAccessTime`

Last time the file was accessed.

### `LastWriteTime`

Last time information was written to the file.

### `ChangeTime`

Last time the file was changed.

### `EndOfFile`

Absolute new end-of-file position as a byte offset from the start of the file. **EndOfFile** specifies the byte offset to the end of the file. Because this value is zero-based, it actually refers to the first free byte in the file. In other words, **EndOfFile** is the offset to the byte immediately following the last valid byte in the file.

### `AllocationSize`

File allocation size, in bytes. Usually, this value is a multiple of the sector or cluster size of the underlying physical device.

### `FileAttributes`

File attributes, which can be any valid combination of the following:

* FILE_ATTRIBUTE_READONLY
* FILE_ATTRIBUTE_HIDDEN
* FILE_ATTRIBUTE_SYSTEM
* FILE_ATTRIBUTE_DIRECTORY
* FILE_ATTRIBUTE_ARCHIVE
* FILE_ATTRIBUTE_NORMAL
* FILE_ATTRIBUTE_TEMPORARY
* FILE_ATTRIBUTE_COMPRESSED

### `FileNameLength`

Specifies the length of the file name string.

### `EaSize`

Combined length, in bytes, of the extended attributes (EA) for the file.

### `FileName`

Specifies the first character of the file name string. This is followed in memory by the remainder of the string.

## Remarks

This information can be queried in either of the following ways:

* Call [**ZwQueryDirectoryFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory), passing FileFullDirectoryInformation as the value of **FileInformationClass** and passing a caller-allocated, FILE_FULL_DIR_INFORMATION-structured buffer as the value of **FileInformation**.

* Create an IRP with major function code IRP_MJ_DIRECTORY_CONTROL and minor function code IRP_MN_QUERY_DIRECTORY.

No specific access rights are required to query this information.

All dates and times are in absolute system-time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601.

This structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

## See also

[**FsRtlNotifyFullChangeDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory)

[**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)

[**ZwQueryDirectoryFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvirtualmemory)
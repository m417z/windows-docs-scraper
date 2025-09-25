# FILE_NAMES_INFORMATION structure

## Description

A **FILE_NAMES_INFORMATION** structure used to query detailed information about the names of files in a directory.

## Members

### `NextEntryOffset`

Byte offset for the next **FILE_NAMES_INFORMATION** entry, if multiple entries are present in a buffer. This member is zero if no other entries follow this one.

### `FileIndex`

Byte offset of the file within the parent directory. This member is undefined for file systems, such as NTFS, in which the position of a file within the parent directory is not fixed and can be changed at any time to maintain sort order.

### `FileNameLength`

Length of the file name string.

### `FileName`

The first character of the file name string. This is followed in memory by the remainder of the string.

## Remarks

This information can be queried in either of the following ways:

* Call [**ZwQueryDirectoryFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfile), passing **FileNamesInformation** as the value of **FileInformationClass** and passing a caller-allocated, **FILE_NAMES_INFORMATION**-structured buffer as the value of **FileInformation**.

* Create an IRP with major function code IRP_MJ_DIRECTORY_CONTROL and minor function code IRP_MN_QUERY_DIRECTORY.

No specific access rights are required to query this information.

This structure must be aligned on a LONG (4-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on a 4-byte boundary.

## See also

[**FsRtlNotifyFullChangeDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory)

[**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)

[**ZwQueryDirectoryFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfile)
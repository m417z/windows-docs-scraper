# FILE_STREAM_INFORMATION structure

## Description

The **FILE_STREAM_INFORMATION** structure is used to enumerate the streams for a file.

## Members

### `NextEntryOffset`

The offset of the next FILE_STREAM_INFORMATION entry. This member is zero if no other entries follow this one.

### `StreamNameLength`

Length, in bytes, of the **StreamName** string.

### `StreamSize`

Size, in bytes, of the stream.

### `StreamAllocationSize`

File stream allocation size, in bytes. Usually this value is a multiple of the sector or cluster size of the underlying physical device.

### `StreamName`

Unicode string that contains the name of the stream.

## Remarks

The FILE_STREAM_INFORMATION structure is used to enumerate the streams for a file. This operation can be performed in either of the following ways:

* By calling [**FltQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile) or [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) and specifying FileStreamInformation for the **FileInformationClass** parameter. On return, the **FileInformation** buffer contains a FILE_STREAM_INFORMATION structure for each file stream.

* By sending an IRP_MJ_QUERY_INFORMATION request to the file system and specifying FileStreamInformation for the **FileInformationClass** parameter. On return, **Irp->AssociatedIrp.SystemBuffer** contains a FILE_STREAM_INFORMATION structure for each file stream.

No specific access rights are required to query this information. Thus this information is available as long as the file is open.

Support for stream enumeration is file system-dependent. If a file system does not support stream enumeration, it should return STATUS_INVALID_PARAMETER or STATUS_NOT_IMPLEMENTED for these requests.

If a file system supports stream enumeration, but the file has no streams other than the default data stream, which is unnamed, the file system should return a single FILE_STREAM_INFORMATION structure containing either "::$DATA" or a zero-length Unicode string as the **StreamName**.

NTFS returns "::$DATA" as the **StreamName** for the default data stream.

For a named data stream, NTFS appends ":$DATA" to the stream name. For example, for a user data stream with the name "Authors," NTFS returns ":Authors:$DATA" as the **StreamName**.

When calling a routine such as [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) to open a named file stream, the ":$DATA" portion of the name can be omitted. For example, to open the "Authors" stream of a file named "Book," the caller can specify "Book:Authors" or "Book:Authors:$DATA" as the stream name. Both names are equivalent.

The size of the buffer passed in the **FileInformation** parameter to [**FltQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile) or [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) must be at least **sizeof** (FILE_STREAM_INFORMATION). If this buffer is not large enough to hold a FILE_STREAM_INFORMATION structure for each file stream, **FltQueryInformationFile** or **ZwQueryInformationFile** returns STATUS_BUFFER_OVERFLOW or STATUS_BUFFER_TOO_SMALL. Because such an unsuccessful call to **FltQueryInformationFile** or **ZwQueryInformationFile** does not return the required buffer size, filter drivers must make one or more additional calls to **FltQueryInformationFile** or **ZwQueryInformationFile**, passing a larger buffer in each call, until the buffer is large enough.

Support for named data streams is file-system-specific. File system filter drivers can determine whether a file system supports named streams in either of the following ways:

* By calling [**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile) and specifying FileFsAttributeInformation for the **FsInformationClass** parameter. On return, the **FsInformation** buffer contains a FILE_FS_ATTRIBUTE_INFORMATION structure. If the FILE_NAMED_STREAMS bit is set in the **FileSystemAttributes** member of this structure, the file system supports named streams.

* By sending an IRP_MJ_QUERY_VOLUME_INFORMATION request to the file system and specifying FileFsAttributeInformation for the **FsInformationClass** parameter. On return, **Irp->AssociatedIrp.SystemBuffer** contains a FILE_FS_ATTRIBUTE_INFORMATION structure. If the FILE_NAMED_STREAMS bit is set in the **FileSystemAttributes** member of this structure, the file system supports named streams.

The FILE_STREAM_INFORMATION structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

## See also

[**FltQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile)

[**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[**IRP_MJ_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information)

[**IRP_MJ_QUERY_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)
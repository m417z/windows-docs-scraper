# ZwFlushBuffersFileEx function

## Description

The **ZwFlushBuffersFileEx** routine is called by a file system filter driver to send a flush request for a given file to the file system. An optional flush operation flag can be set to control how file data is written to storage.

## Parameters

### `FileHandle` [in]

Handle returned by [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [ZwOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile) for the file whose buffers will be flushed. This parameter is required and cannot be **NULL**.

### `FLags`

Flush operation flags. *Flags* can be 0 or one of the following values.

| Value | Meaning |
| --- | --- |
| **FLUSH_FLAGS_FILE_DATA_ONLY** | If the file is on an NTFS file system, file data in the file cache will be written. No metadata is written and the underlying storage is not synchronized to flush its cache. This flag is not valid with volume handles. |
| **FLUSH_FLAGS_NO_SYNC** | If the file is on an NTFS file system, file data and metadata in the file cache will be written. The underlying storage is not synchronized to flush its cache. This flag is not valid with volume handles. |

### `Parameters`

Address of the caller's I/O status block. This parameter is required and cannot be **NULL**.

### `ParametersSize`

The size, in bytes, of the parameters block.

### `IoStatusBlock` [out]

Address of the caller's I/O status block. This parameter is required and cannot be **NULL**.

## Return value

**ZwFlushBuffersFileEx** returns **STATUS_SUCCESS** or an appropriate **NTSTATUS** value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_MEDIA_WRITE_PROTECTED** | The file resides on a write-protected volume; this is an error code. |
| **STATUS_VOLUME_DISMOUNTED** | The file resides on a volume that is not currently mounted; this is an error code. |
| **STATUS_ACCESS_DENIED** | The file does has neither write or append access. |

## Remarks

A file system filter driver can call **ZwFlushBuffersFileEx** to issue an [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers) request to the file system for a given file. The flush operation is synchronous.

Minifilter drivers should call [FltFlushBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers) instead of calling **ZwFlushBuffersFileEx**.

Callers of **ZwFlushBuffersFileEx** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

**Note** If the call to the **ZwFlushBuffersFileEx** function occurs in user mode, you should use the name "**NtFlushBuffersFileEx**" instead of "**ZwFlushBuffersFileEx**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[FltFlushBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers)

[IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[ZwOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile)
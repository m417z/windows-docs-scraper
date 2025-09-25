# NtFlushBuffersFileEx function

## Description

The **NtFlushBuffersFileEx** routine sends a flush request for a given file to the file system. An optional flush operation flag can be set to control how file data is written to storage.

## Parameters

### `FileHandle` [in]

Handle returned by [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [**NtOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile) for the file whose buffers will be flushed. This parameter is required and cannot be NULL.

### `Flags` [in]

Flush operation flags. *Flags* can be one of the following values:

| Value | Meaning |
| ----- | ------- |
| 0 (normal) | File data and metadata in the file cache will be written, and the underlying storage is synchronized to flush its cache. Windows file systems supported: NTFS, ReFS, FAT, exFAT. |
| FLUSH_FLAGS_FILE_DATA_ONLY | File data in the file cache will be written. No metadata is written and the underlying storage is not synchronized to flush its cache. This flag is not valid with volume handles. Windows file systems supported: NTFS, FAT, exFAT. |
| FLUSH_FLAGS_NO_SYNC | File data and metadata in the file cache will be written. The underlying storage is not synchronized to flush its cache. This flag is not valid with volume handles. Windows file systems supported: NTFS, FAT, exFAT. |
| FLUSH_FLAGS_FILE_DATA_SYNC_ONLY | Data from the given file will be written from the Windows in-memory cache. Only metadata that is necessary for data retrieval will be flushed (timestamp updating will be skipped as much as possible). The underlying storage is synchronized to flush its cache. This flag is not valid with volume or directory handles. Windows file systems supported: NTFS. |

### `Parameters` [in]

Pointer to a block with additional parameters. This parameter must currently be set to NULL.

### `ParametersSize` [in]

The size, in bytes, of the block that *Parameters* point to. This parameter must currently be set to 0.

### `IoStatusBlock` [out]

Address of the caller's I/O status block. This parameter is required and cannot be NULL.

## Return value

**NtFlushBuffersFileEx** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_MEDIA_WRITE_PROTECTED | The file resides on a write-protected volume; this is an error code. |
| STATUS_VOLUME_DISMOUNTED | The file resides on a volume that is not currently mounted; this is an error code. |
| STATUS_ACCESS_DENIED | The file does has neither write or append access. |

## Remarks

Minifilter drivers should call [**FltFlushBuffers2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers2) instead of calling **NtFlushBuffersFileEx**.

A legacy file system filter driver can call **NtFlushBuffersFileEx** to issue an [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers) request to the file system for a given file. The flush operation is synchronous.

Callers of **NtFlushBuffersFileEx** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FltFlushBuffers2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers2)

[IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**NtOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile)
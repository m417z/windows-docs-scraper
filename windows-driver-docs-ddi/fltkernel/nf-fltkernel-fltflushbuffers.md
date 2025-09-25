# FltFlushBuffers function

## Description

The **FltFlushBuffers** routine is used by the minifilter driver to send a flush request for a given file to the file system. Use [FltFlushBuffers2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers2) to specify different flush type options.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the file to be flushed. This parameter is required and cannot be **NULL**.

## Return value

**FltFlushBuffers** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_MEDIA_WRITE_PROTECTED** | The file resides on a write-protected volume. This is an error code. |
| **STATUS_VOLUME_DISMOUNTED** | The file resides on a volume that is not currently mounted. This is an error code. |

## Remarks

A minifilter driver can call **FltFlushBuffers** to issue an [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers) request to the file system for a given file. The flush operation is synchronous and is issued to the instance(s) below the specified *Instance*.

If *FileObject* is for a file, both the file data and metadata in the file cache will be written, and the underlying storage will be synchronized to flush its cache. If *FileObject* is for a volume, the file system will cause both the file data and metadata for all modified files on the volume will be written, and the underlying storage to be synchronized to flush its cache. Use [FltFlushBuffers2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers2) to more granularly control the flush type that the file system should do.

## See also

[FltFlushBuffers2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers2)

[IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers)
# FltFlushBuffers2 function

## Description

A minifilter driver calls **FltFlushBuffers2** to send a flush request to the file system for a given file.

## Parameters

### `Instance`

[in] Opaque instance pointer for the calling minifilter driver instance. This parameter is required and can't be NULL.

### `FileObject`

[in] File object pointer for the file or volume to be flushed. This parameter is required and can't be NULL.

### `FlushType`

[in] Specifies the type of flush that the file system should do on the file. **FlushType** can be one of the following:

| FlushType Operation Value | Description |
| ------------------------- | ----------- |
| 0 | If **FileObject** is for a file, both the file data and metadata in the file cache will be written, and the underlying storage will be synchronized to flush its cache. If **FileObject** is for a volume, the file system will cause both the file data and metadata for all modified files on the volume will be written, and the underlying storage to be synchronized to flush its cache. This operation is equivalent to [**FltFlushBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers). |
| FLT_FLUSH_TYPE_FLUSH_AND_PURGE | Same as 0 (**FltFlushBuffers**), except that the cache is also purged after the flush completes. |
| FLT_FLUSH_TYPE_FILE_DATA_ONLY | If the file is on an NTFS file system, only file data in the file cache will be written. No metadata is written and the underlying storage is not synchronized to flush its cache. This flag is not valid if **FileObject** is for a volume. |
| FLT_FLUSH_TYPE_NO_SYNC | If the file is on an NTFS file system, file data and metadata in the file cache will be written. The underlying storage will not be synchronized to flush its cache. This flag is not valid if **FileObject** is for a volume. |
| FLT_FLUSH_TYPE_DATA_SYNC_ONLY | If the file is on an NTFS file system, file data in the file cache will be written. No metadata is written. The underlying storage is synchronized to flush its cache. This flag is not valid if **FileObject** is for a volume or directory. |

### `CallbackData`

[in/optional] Pointer to optional [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure used to propagate the caller's IRP extension. See [**FltPropagateIrpExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpropagateirpextension).

## Return value

**FltFlushBuffers2** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_MEDIA_WRITE_PROTECTED** | The file resides on a write-protected volume. This is an error code. |
| **STATUS_VOLUME_DISMOUNTED** | The file resides on a volume that is not currently mounted. This is an error code. |

## Remarks

A minifilter driver can call **FltFlushBuffers2** to issue an [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers) request to the file system for a given file. The flush operation is synchronous and is issued to the instance(s) below the specified **Instance**.

If the file is on an NTFS file system, the minifilter can control the type of flush through the **FlushType** parameter.

## See also

[**FltFlushBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers)

[**FltPropagateIrpExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpropagateirpextension)

[IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers)
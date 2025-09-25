# FltWriteFile function

## Description

**FltWriteFile** is used to write data to an open file, stream, or device.

## Parameters

### `InitiatingInstance` [in]

An opaque instance pointer for the minifilter driver instance that the operation is to be sent to. The instance must be attached to the volume where the file resides. This parameter is required and cannot be NULL.

### `FileObject` [in]

Pointer to a [**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) for the file that the data is to be written to. This file object must be currently open. Calling **FltWriteFile** when the file object is not yet open or is no longer open (for example, in a pre-create or post-cleanup callback routine) causes the system to ASSERT on a checked build. This parameter is required and cannot be NULL.

### `ByteOffset` [in, optional]

Pointer to a caller-allocated variable that specifies the starting byte offset within the file where the read operation is to begin.

If **ByteOffset** is specified, the I/O is performed at that offset, regardless of the current value of the file object’s **CurrentByteOffset** field.

* If the file was opened for synchronous I/O (FO_SYNCHRONOUS_IO is set in the file object’s **Flags** field), the caller can set **ByteOffset->LowPart** to FILE_USE_FILE_POINTER_POSITION and **ByteOffset->HighPart** to -1 to have the I/O performed at the file object’s **CurrentByteOffset** field. If the file wasn't opened for synchronous I/O, using FILE_USE_FILE_POINTER_POSITION is an error.
* The caller can set **ByteOffset->LowPart** to FILE_WRITE_TO_END_OF_FILE and **ByteOffset->HighPart** to -1 to start the write at the end of the file (i.e., perform an appending write).

If **ByteOffset** isn't specified:

* If the file wasn't opened for synchronous I/O, that's an error.
* Otherwise, the I/O is performed at the file object’s **CurrentByteOffset**.

If the file object was opened for synchronous I/O, the **CurrentByteOffset** field gets updated unless the caller passes the FLTFL_IO_OPERATION_DO_NOT_UPDATE_BYTE_OFFSET flag.

* Note: the file system still updates **CurrentByteOffset** in this case. Filter Manager saves the **CurrentByteOffset** value before sending the I/O down the stack and restores it when the I/O returns. From the perspective of the caller of **FltWriteFile** (and filters at higher altitudes) the **CurrrentByteOffset** isn't updated. But filters below the caller see the updated **CurrentByteOffset** value in their post-read/write callbacks.

If the file object wasn't opened for synchronous I/O, the **CurrentByteOffset** field isn't updated regardless of the state of the **ByteOffset** parameter.

If the file object that **FileObject** points to was opened for asynchronous I/O, this parameter is required and can't be NULL.

Prior to Windows 8, the special constants FILE_WRITE_TO_END_OF_FILE and FILE_USE_FILE_POINTER_POSITION aren't supported for this parameter.

### `Length` [in]

Size, in bytes, of the buffer that the **Buffer** parameter points to.

### `Buffer` [in]

Pointer to a buffer that contains the data to be written to the file. If the file is opened for noncached I/O, this buffer be must be aligned in accordance with the alignment requirement of the underlying storage device. Minifilter drivers can allocate such an aligned buffer by calling [**FltAllocatePoolAlignedWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag).

### `Flags` [in]

Bitmask of flags specifying the type of write operation to be performed.

| Flag | Meaning |
| ---- | ------- |
| FLTFL_IO_OPERATION_DO_NOT_UPDATE_BYTE_OFFSET | Minifilter drivers can set this flag to specify that **FltWriteFile** will not update the file object's **CurrentByteOffset** field. |
| FLTFL_IO_OPERATION_NON_CACHED | Minifilter drivers can set this flag to specify a noncached write, even if the file object was not opened with FILE_NO_INTERMEDIATE_BUFFERING. |
| FLTFL_IO_OPERATION_PAGING | Minifilter drivers can set this flag to specify a paging write. |
| FLTFL_IO_OPERATION_SYNCHRONOUS_PAGING | Minifilter drivers can set this flag to specify a synchronous paging I/O write. Minifilter drivers that set this flag must also set the FLTFL_IO_OPERATION_PAGING flag. This flag is available starting with Windows Vista. |

### `BytesWritten` [out, optional]

Pointer to a caller-allocated variable that receives the number of bytes written to the file. If **CallbackRoutine** is not NULL, this parameter is ignored. Otherwise, this parameter is optional and can be NULL.

### `CallbackRoutine` [in, optional]

Pointer to a [**PFLT_COMPLETED_ASYNC_IO_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_completed_async_io_callback)-typed callback routine to call when the write operation is complete. This parameter is optional and can be NULL.

### `CallbackContext` [in, optional]

Context pointer to be passed to the **CallbackRoutine** if one is present. This parameter is optional and can be NULL. If **CallbackRoutine** is NULL, this parameter is ignored.

## Return value

**FltWriteFile** returns the NTSTATUS value that was returned by the file system.

## Remarks

A minifilter driver calls **FltWriteFile** to write data to an open file.

**FltWriteFile** causes a write request to be sent to the minifilter driver instances attached below the initiating instance and to the file system. The specified instance and the instances attached above it do not receive the write request.

**FltWriteFile** performs noncached I/O if either of the following is true:

* The caller set the FLTFL_IO_OPERATION_NON_CACHED flag in the **Flags** parameter.

* The file object was opened for noncached I/O. Usually, this is done by specifying the FILE_NO_INTERMEDIATE_BUFFERING **CreateOptions** flag in the preceding call to [**FltCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile), [**FltCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex), or [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile).

Noncached I/O imposes the following restrictions on the parameter values passed to **FltWriteFile**:

* The buffer that the **Buffer** parameter points to must be aligned in accordance with the alignment requirement of the underlying storage device. To allocate such an aligned buffer, call [**FltAllocatePoolAlignedWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag).

* The byte offset that the **ByteOffset** parameter points to must be a nonnegative multiple of the volume's sector size.

* The length specified in the **Length** parameter must be a nonnegative multiple of the volume's sector size.

If the value of the **CallbackRoutine** parameter is not NULL, the write operation is performed asynchronously.

If the value of the **CallbackRoutine** parameter is NULL, the write operation is performed synchronously. That is, **FltWriteFile** waits until the write operation is complete before returning. This is true even if the file object that **FileObject** points to was opened for asynchronous I/O.

If multiple threads call **FltWriteFile** for the same file object, and the file object was opened for synchronous I/O, the Filter Manager does not attempt to serialize I/O on the file. In this respect, **FltWriteFile** differs from [**ZwWriteFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwwritefile).

## See also

[**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[**FltAllocatePoolAlignedWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag)

[**FltCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile)

[**FltCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex)

[**FltReadFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile)

[**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[**PFLT_COMPLETED_ASYNC_IO_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_completed_async_io_callback)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile)

[**ZwReadFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwreadfile)

[**ZwWriteFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwwritefile)
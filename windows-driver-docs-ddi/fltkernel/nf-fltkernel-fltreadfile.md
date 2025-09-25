# FltReadFile function

## Description

**FltReadFile** reads data from an open file, stream, or device.

## Parameters

### `InitiatingInstance` [in]

Opaque instance pointer for the minifilter driver instance that the operation is to be sent to. The instance must be attached to the volume where the file resides. This parameter is required and cannot be NULL.

### `FileObject` [in]

Pointer to a [**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) for the file that the data is to be read from. This file object must be currently open. Calling **FltReadFile** when the file object is not yet open or is no longer open (for example, in a pre-create or post-cleanup callback routine) causes the system to ASSERT on a checked build. This parameter is required and cannot be NULL.

### `ByteOffset` [in, optional]

Pointer to a caller-allocated variable that specifies the starting byte offset within the file where the read operation is to begin.

If **ByteOffset** is specified, the I/O is performed at that offset, regardless of the current value of the file object’s **CurrentByteOffset** field.

* If the file was opened for synchronous I/O (FO_SYNCHRONOUS_IO is set in the file object’s **Flags** field), the caller can set **ByteOffset->LowPart** to FILE_USE_FILE_POINTER_POSITION and **ByteOffset->HighPart** to -1 to have the I/O performed at the file object’s **CurrentByteOffset** field. If the file wasn't opened for synchronous I/O, using FILE_USE_FILE_POINTER_POSITION is an error.

If **ByteOffset** isn't specified:

* If the file wasn't opened for synchronous I/O, that's an error.
* Otherwise, the I/O is performed at the file object’s **CurrentByteOffset**.

If the file object was opened for synchronous I/O, the **CurrentByteOffset** field gets updated unless the caller passes the FLTFL_IO_OPERATION_DO_NOT_UPDATE_BYTE_OFFSET flag.

* Note: the file system still updates **CurrentByteOffset** in this case. Filter Manager saves the **CurrentByteOffset** value before sending the I/O down the stack and restores it when the I/O returns. From the perspective of the caller of **FltReadFile** (and filters at higher altitudes) the **CurrrentByteOffset** isn't updated. But filters below the caller see the updated **CurrentByteOffset** value in their post-read/write callbacks.

If the file object wasn't opened for synchronous I/O, the **CurrentByteOffset** field isn't updated regardless of the state of the **ByteOffset** parameter.

### `Length` [in]

Size, in bytes, of the buffer that the **Buffer** parameter points to.

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the data that is read from the file.

### `Flags` [in]

Bitmask of flags specifying the type of read operation to be performed.

| Flag | Meaning |
| ---- | ------- |
| FLTFL_IO_OPERATION_DO_NOT_UPDATE_BYTE_OFFSET | Minifilter drivers can set this flag to specify that **FltReadFile** should not update the file object's **CurrentByteOffset** field. |
| FLTFL_IO_OPERATION_NON_CACHED | Minifilter drivers can set this flag to specify a noncached read, even if the file object was not opened with FILE_NO_INTERMEDIATE_BUFFERING. |
| FLTFL_IO_OPERATION_PAGING | Minifilter drivers can set this flag to specify a paging read. |
| FLTFL_IO_OPERATION_SYNCHRONOUS_PAGING | Minifilter drivers can set this flag to specify a synchronous paging I/O read. Minifilter drivers that set this flag must also set the FLTFL_IO_OPERATION_PAGING flag. Available starting in Windows Vista. |

### `BytesRead` [out, optional]

Pointer to a caller-allocated variable that receives the number of bytes read from the file. If **CallbackRoutine** is not NULL, this parameter is ignored. Otherwise, this parameter is optional and can be NULL.

### `CallbackRoutine` [in, optional]

Pointer to a [**PFLT_COMPLETED_ASYNC_IO_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_completed_async_io_callback)-typed callback routine to call when the read operation is complete. This parameter is optional and can be NULL.

### `CallbackContext` [in, optional]

Context pointer to be passed to the **CallbackRoutine** if one is present. This parameter is optional and can be NULL. If **CallbackRoutine** is NULL, this parameter is ignored.

## Return value

**FltReadFile** returns the NTSTATUS value that was returned by the file system.

## Remarks

A minifilter driver calls **FltReadFile** to read data from an open file.

**FltReadFile** creates a read request and sends it to the minifilter driver instances attached below the initiating instance, and to the file system. The specified instance and the instances attached above it do not receive the read request.

**FltReadFile** performs noncached I/O if either of the following is true:

* The caller set the FLTFL_IO_OPERATION_NON_CACHED flag in the **Flags** parameter.

* The file object was opened for noncached I/O. Usually, this is done by specifying the FILE_NO_INTERMEDIATE_BUFFERING **CreateOptions** flag in the preceding call to [**FltCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile), [**FltCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex), or [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile).

Noncached I/O imposes the following restrictions on the parameter values passed to **FltReadFile**:

* The buffer that the **Buffer** parameter points to must be aligned in accordance with the alignment requirement of the underlying storage device. To allocate such an aligned buffer, call [**FltAllocatePoolAlignedWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag).

* The byte offset that the **ByteOffset** parameter points to must be a nonnegative multiple of the volume's sector size.

* The length specified in the **Length** parameter must be a nonnegative multiple of the volume's sector size.

If an attempt is made to read beyond the end of the file, **FltReadFile** returns an error.

If the value of the **CallbackRoutine** parameter is not NULL, the read operation is performed asynchronously.

If the value of the **CallbackRoutine** parameter is NULL, the read operation is performed synchronously. That is, **FltReadFile** waits until the read operation is complete before returning. This is true even if the file object that **FileObject** points to was opened for asynchronous I/O.

If multiple threads call **FltReadFile** for the same file object, and the file object was opened for synchronous I/O, the Filter Manager does not attempt to serialize I/O on the file. In this respect, **FltReadFile** differs from [**ZwReadFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwreadfile).

## See also

[**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[**FltAllocatePoolAlignedWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatepoolalignedwithtag)

[**FltCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile)

[**FltCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex)

[**FltWriteFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile)

[**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[**PFLT_COMPLETED_ASYNC_IO_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_completed_async_io_callback)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile)

[**ZwReadFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwreadfile)

[**ZwWriteFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwwritefile)
# FltPerformAsynchronousIo function

## Description

A minifilter driver calls **FltPerformAsynchronousIo** to initiate an asynchronous I/O operation.

## Parameters

### `CallbackData` [in, out]

Pointer to a callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure allocated by a previous call to [FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata). This parameter is required and cannot be **NULL**. The caller is responsible for freeing this structure when it is no longer needed by calling [FltFreeCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreecallbackdata).

### `CallbackRoutine` [in]

Pointer to a [PFLT_COMPLETED_ASYNC_IO_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_completed_async_io_callback)-typed callback routine to be called when the I/O operation is completed. Note: The Filter Manager calls this routine after it calls the postoperation callback ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routines of any minifilter drivers whose instances are attached below the initiating instance (specified in the *Instance* parameter to [FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata)). This parameter is required and cannot be **NULL**. The Filter Manager always calls this routine, even when **FltPerformAsynchronousIo** fails.

### `CallbackContext` [in]

Context pointer to be passed to the *CallbackRoutine* This parameter is optional and can be **NULL**.

## Return value

**FltPerformAsynchronousIo** returns STATUS_SUCCESS to indicate that the I/O operation was completed by the file system, and the callback routine that *CallbackRoutine* points to has been called. Otherwise, it returns an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_INVALID_ASYNCHRONOUS_REQUEST | IRP_MJ_CREATE requests cannot be performed asynchronously. This is an error code. |
| STATUS_PENDING | The operation returned STATUS_PENDING. Filter Manager will call the callback routine that *CallbackRoutine* points to when the I/O operation is complete. This code indicates only that the operation was initiated. |
| STATUS_FLT_IO_COMPLETE | The operation was completed by the preoperation callback routine of the minifilter driver whose instances are attached below the initiating instance. |

## Remarks

A minifilter driver calls **FltPerformAsynchronousIo** to initiate an asynchronous I/O operation after calling [FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata) to allocate a callback data structure for the operation.

**FltPerformAsynchronousIo** sends the I/O operation only to the minifilter driver instances attached below the initiating instance (specified in the *Instance* parameter to [FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata)), and the file system. Minifilter drivers attached above the specified instance do not receive the I/O operation.

Minifilter drivers can only initiate IRP-based I/O operations. They cannot initiate fast I/O or file system filter (FSFilter) callback operations.

Minifilter drivers should use **FltPerformAsynchronousIo** only for asynchronous I/O operations for which routines such as the following cannot be used:

- [FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile)

- [FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile)

IRP_MJ_CREATE requests cannot be performed asynchronously.

The callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure can be freed or reused at any time after the callback routine that *CallbackRoutine* points to has been called. The caller can free the callback data structure by calling [FltFreeCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreecallbackdata) or prepare it for reuse by calling [FltReuseCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreusecallbackdata).

> [!NOTE]
> STATUS_SUCCESS and STATUS_FLT_IO_COMPLETE indicate that the I/O operation was completed, but do not indicate the final status of the I/O operation. To determine the actual operation status returned by the underlying minifilter drivers, filter drivers, and file system, the *CallbackRoutine* should examine the **IoStatus** member of the callback data structure received in the *CallbackRoutine*'s *CallbackContext* parameter.
>
> Because Filter Manager always calls the callback routine that *CallbackRoutine* points to, even when **FltPerformAsynchronousIo** fails, the minifilter driver can perform the freeing or reusing operations directly in the callback routine.

The caller of **FltPerformAsynchronousIo** can be running at IRQL <= APC_LEVEL if the IRP_PAGING_IO flag is set in the **IrpFlags** member of the [FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block) structure for the operation. (This flag is only valid for IRP_MJ_READ, IRP_MJ_WRITE, IRP_MJ_QUERY_INFORMATION, and IRP_MJ_SET_INFORMATION operations.) Otherwise, the caller must be running at IRQL PASSIVE_LEVEL.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[FltAllocateCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata)

[FltFreeCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreecallbackdata)

[FltPerformSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio)

[FltReuseCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreusecallbackdata)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[PFLT_COMPLETED_ASYNC_IO_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_completed_async_io_callback)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)
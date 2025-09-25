# FltReissueSynchronousIo function

## Description

**FltReissueSynchronousIo** initiates a new synchronous I/O operation that uses the parameters from a previously synchronized I/O operation.

## Parameters

### `InitiatingInstance` [in]

An opaque instance pointer to the minifilter driver instance that is reissuing the I/O operation. Must be the same instance that initiated the previous I/O operation. This parameter is required and cannot be set to NULL.

### `CallbackData` [in]

A pointer to the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure from a previously synchronized I/O operation. This parameter is required and cannot be set to NULL.

## Return value

None

## Remarks

A minifilter driver calls **FltReissueSynchronousIo** from a postoperation callback ([**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine to reissue a synchronized I/O request. It typically calls **FltReissueSynchronousIo** from a postoperation callback routine to reissue a failed operation with different parameters, or to handle a reparse bounce. However, it can also call **FltReissueSynchronousIo** to reissue I/O that the minifilter driver generated through calls to the [**FltAllocateCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata) and [**FltPerformSynchronousIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio) routines. In this situation, it does not matter whether it calls **FltReissueSynchronousIo** in a postoperation callback routine or outside the context of an operation callback routine. For calls outside the context of a postoperation callback routine, consider using the [**FltReuseCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreusecallbackdata) and **FltPerformSynchronousIo** routines instead.

The caller can modify the contents of the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure's I/O parameter block before reissuing the I/O request. If it does, it must call [**FltSetCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty) before calling **FltReissueSynchronousIo**.

For example, if a minifilter driver uses reparse points, and its post-create callback routine is called for a create operation that returned STATUS_REPARSE, the minifilter driver can reissue the create operation for its own reparse points. In this case, the minifilter driver will complete the following steps:

1. Set the FILE_OPEN_REPARSE_POINT flag in the callback data structure's I/O parameter block.

2. Call [**FltSetCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty).

3. Call **FltReissueSynchronousIo** to reissue the create request.

The Filter Manager sends the reissued I/O request only to the minifilter driver instances that are attached below the initiating instance (specified in the **InitiatingInstance** parameter) and to the file system. Minifilter driver instances attached above the initiating instance do not receive the reissued I/O request.

Only synchronized I/O operations can be reissued. To provide the driver with the ability to reissue, by calling **FltReissueSynchronousIo** in the postoperation callback routine, a minifilter driver must specifically return FLT_PREOP_SYNCHRONIZE in the preoperation callback routine.

> [!NOTE]
> The minifilter driver does not call the [**FltIsOperationSynchronous**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisoperationsynchronous) routine to determine whether the preoperation callback routine for this operation returned FLT_PREOP_SYNCHRONIZE. The minifilter driver calls **FltIsOperationSynchronous** to determine whether the operation itself is synchronous from the I/O manager's perspective.

Only IRP-based I/O operations can be reissued. Fast I/O operations and file system filter (FSFilter) callback operations cannot be reissued. To determine whether an I/O operation is IRP-based, use the [**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

A create (IRP_MJ_CREATE) operation that has been canceled cannot be reissued. Before calling **FltReissueSynchronousIo** for a create operation, callers should check the **Flags** member of the file object for the create operation. If the FO_FILE_OPEN_CANCELLED flag is set, this means that the create operation has been canceled, and a close ([**IRP_MJ_CLOSE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)) operation will be issued for this file object. If **FltReissueSynchronousIo** is called for a create operation that has been canceled, the Filter Manager fails the reissued I/O request with STATUS_CANCELLED.

> [!NOTE]
> When minifilter drivers re-issue the create in the post-create callback, they do not have to release and set the buffer that is associated with their reparse point (**TagData** field in **CallbackData**) to NULL. Instead, the Filter Manager releases and sets the buffer to NULL for them.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_FS_FILTER_OPERATION**](https://learn.microsoft.com/previous-versions/ff544648(v=vs.85))

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[**FLT_IS_REISSUED_IO**](https://learn.microsoft.com/previous-versions/ff544660(v=vs.85))

[**FLT_PARAMETERS for IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-create)

[**FltCancelFileOpen**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelfileopen)

[**FltIsOperationSynchronous**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisoperationsynchronous)

[**FltPerformSynchronousIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio)

[**FltReuseCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreusecallbackdata)

[**FltSetCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty)

[**IRP_MJ_CLOSE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

[**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)
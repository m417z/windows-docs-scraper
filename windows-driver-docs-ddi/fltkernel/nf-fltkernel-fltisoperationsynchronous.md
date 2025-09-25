# FltIsOperationSynchronous function

## Description

The **FltIsOperationSynchronous** routine determines whether a given callback data structure ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) represents a synchronous or asynchronous I/O operation.

## Parameters

### `CallbackData` [in]

Pointer to the callback data structure for the operation ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)).

## Return value

**FltIsOperationSynchronous** returns TRUE if the operation is synchronous, and FALSE if the operation is asynchronous.

## Remarks

**FltIsOperationSynchronous** determines whether a given callback data structure ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) represents a synchronous or asynchronous I/O operation, according to the following conditions:

* If the operation is not an IRP-based I/O operation, the operation is synchronous. To determine whether an operation is IRP-based, use the [**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

* If the operation is an asynchronous paging I/O operation, the operation is asynchronous, even if one of the other conditions in this list is true.

* If the operation is a synchronous paging I/O operation, the operation is synchronous.

* If the file object for the operation was opened for synchronous I/O, the operation is synchronous.

* If the IRP_SYNCHRONOUS_API flag is set in the IRP for the operation, the operation is synchronous. This flag is set for operations, such as IRP_MJ_QUERY_INFORMATION and IRP_MJ_SET_INFORMATION, that are always synchronous, even when performed on a file object that was opened for asynchronous I/O.

* If none of the above conditions is true, the operation is asynchronous.

> [!NOTE]
>
> **FltIsOperationSynchronous** also returns TRUE if the callback data structure represents an IRP_MJ_DEVICE_CONTROL, IRP_MJ_INTERNAL_DEVICE_CONTROL, or IRP_MJ_FILE_SYSTEM_CONTROL operation with an I/O control code (IOCTL) or file system control code (FSCTL) that was defined with METHOD_BUFFERED, even if the file object was opened for asynchronous I/O. Such a request is likely to be made synchronous by the file system, but this is not necessarily true in all cases.
>
> When **FltIsOperationSynchronous** returns TRUE, this does not indicate that the I/O operation is synchronized. That is, the TRUE value does not indicate that a minifilter driver returned FLT_PREOP_SYNCHRONIZE in the preoperation callback ([**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine for this operation. Instead, **FltIsOperationSynchronous** returns TRUE to indicate that the I/O operation is synchronous from the I/O manager's perspective.

**FltIsOperationSynchronous** can be called for all classes of operations: fast I/O, file system filter (FSFilter) callbacks, and IRP-based operations.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_FS_FILTER_OPERATION**](https://learn.microsoft.com/previous-versions/ff544648(v=vs.85))

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[**IoIsOperationSynchronous**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioisoperationsynchronous)
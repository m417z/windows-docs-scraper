# PFLT_POST_OPERATION_CALLBACK callback

## Description

A minifilter driver can register one or more routines of type PFLT_POST_OPERATION_CALLBACK to perform completion processing for I/O operations.

## Parameters

### `Data` [in, out]

A pointer to the callback data [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure for the I/O operation.

### `FltObjects` [in]

A pointer to a filter manager maintained [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure that contains opaque pointers for the objects related to the current I/O request.

### `CompletionContext` [in, optional]

A context pointer that was returned by the minifilter driver's pre-operation callback [PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback) routine. The *CompletionContext* pointer provides a way to communicate information from the pre-operation callback routine to the post-operation callback routine.

### `Flags` [in]

A bitmask of flags that specifies how the post-operation callback is to be performed.

| Flag | Meaning |
| ---- | ------- |
| FLTFL_POST_OPERATION_DRAINING | The filter manager sets this flag to indicate that the minifilter driver instance is being detached and that this post-operation callback routine is being called to clean up the minifilter driver's completion context. The post-operation callback should return FLT_POSTOP_FINISHED_PROCESSING. If this flag is set, the *Data* parameter points to a copy of the original callback data structure for the operation, not the original callback data structure. Additionally, when this flag is set, the post-operation callback routine is called at IRQL <= APC_LEVEL. |

## Return value

This callback routine returns one of the following status values:

| Return code | Description |
| --- | --- |
| **FLT_POSTOP_FINISHED_PROCESSING** | The minifilter driver has finished completion processing for the I/O operation and is returning control of the operation to the filter manager.<br><br>After the post-operation callback returns this status value, the filter manager continues completion processing of the I/O operation. |
| **FLT_POSTOP_MORE_PROCESSING_REQUIRED** | The minifilter driver has halted completion processing for the I/O operation, but it is not returning control of the operation to the filter manager.<br><br>A minifilter driver's post-operation callback can return this status value only if the minifilter driver's post-operation callback has posted the I/O operation to a work queue. The minifilter driver must eventually resume completion processing of the I/O operation.<br><br>After the post-operation callback returns FLT_POSTOP_MORE_PROCESSING_REQUIRED, the filter manager performs no further completion processing of the I/O operation, unless both of the following conditions are true:<br><br>* The post-operation callback has posted the I/O operation to a work queue.<br>* After the work routine performs completion processing for the operation, it calls [FltCompletePendedPostOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation) to return control of the operation to the filter manager.<br><br>This status value can only be returned for IRP-based I/O operations. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro. |
| **FLT_POSTOP_DISALLOW_FSFILTER_IO** | The minifilter driver is disallowing a fast QueryOpen operation and forcing the operation down the slow path. Doing so causes the I/O manager to service the request by performing an open/query/close of the file. Minifilter drivers should only return this status for QueryOpen. |

## Remarks

A minifilter driver's post-operation callback routine performs completion processing for one or more types of I/O operations.

Post-operation callback routines are similar to the completion routines used by legacy file system filter drivers.

Post-operation callback routines are called in an arbitrary thread context, at IRQL <= DISPATCH_LEVEL. Because this callback routine can be called at IRQL DISPATCH_LEVEL, it is subject to the following constraints:

* It cannot safely call any kernel-mode routine that must run at a lower IRQL.
* Any data structures used in this routine must be allocated from nonpaged pool.
* It cannot be made pageable.
* It cannot acquire resources, mutexes, or fast mutexes. However, it can acquire spin locks.
* It cannot get, set, or delete contexts, but it can release contexts.

Any I/O completion processing that needs to be performed at IRQL < DISPATCH_LEVEL cannot be performed directly in the postoperation callback routine. Instead, it must be posted to a work queue by calling a routine such as [FltDoCompletionProcessingWhenSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdocompletionprocessingwhensafe) or [FltQueueDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem).

Be aware that **FltDoCompletionProcessingWhenSafe** should never be called if the *Flags* parameter of the post-operation callback has the FLTFL_POST_OPERATION_DRAINING bit set. The following are exceptions to this rule:

* If a minifilter driver's pre-operation callback routine returns FLT_PREOP_SYNCHRONIZE for an IRP-based I/O operation, the corresponding post-operation callback routine is guaranteed to be called at IRQL <= APC_LEVEL, in the same thread context as the pre-operation callback.
* Post-create callback routines are guaranteed to be called at IRQL PASSIVE_LEVEL, in the context of the thread that originated the IRP_MJ_CREATE operation.

A minifilter driver registers a post-operation callback routine for a particular type of I/O operation by storing the callback routine's entry point in the **OperationRegistration** array of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure. The minifilter driver passes this structure as a parameter to [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) in its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

A minifilter driver can register a post-operation callback routine for a particular type of I/O operation without registering a pre-operation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine, and vice versa.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[FLT_IS_FASTIO_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FLT_IS_REISSUED_IO](https://learn.microsoft.com/previous-versions/ff544660(v=vs.85))

[FLT_IS_SYSTEM_BUFFER](https://learn.microsoft.com/previous-versions/ff544663(v=vs.85))

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[FltCancelFileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelfileopen)

[FltCompletePendedPostOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation)

[FltDoCompletionProcessingWhenSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdocompletionprocessingwhensafe)

[FltQueueDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[FltSetCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)
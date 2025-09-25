# PFLT_PRE_OPERATION_CALLBACK callback

## Description

A minifilter driver's **PFLT_PRE_OPERATION_CALLBACK** routine performs pre-operation processing for I/O operations.

## Parameters

### `Data` [in, out]

A pointer to the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation.

### `FltObjects` [in]

A pointer to an [**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure that contains opaque pointers for the objects related to the current I/O request.

### `CompletionContext` [out]

If this callback routine returns FLT_PREOP_SUCCESS_WITH_CALLBACK or FLT_PREOP_SYNCHRONIZE, this parameter is an optional context pointer to be passed to the corresponding post-operation callback routine. Otherwise, it must be NULL.

## Return value

This callback routine returns one of the following FLT_PREOP_CALLBACK_STATUS values.

| Return code | Description |
| ----------- | ----------- |
| FLT_PREOP_COMPLETE | The minifilter is completing the I/O operation. See Remarks for details. |
| FLT_PREOP_DISALLOW_FASTIO | The operation is a fast I/O operation, and the minifilter is not allowing the fast I/O path to be used for this operation. See Remarks for details.|
| FLT_PREOP_PENDING | The minifilter has pended the I/O operation, and the operation is still pending. See Remarks for details.|
| FLT_PREOP_SUCCESS_NO_CALLBACK | The minifilter is returning the I/O operation to *FltMgr* for further processing. In this case, *FltMgr* won't call the minifilter driver's post-operation callback, if one exists, during I/O completion. |
| FLT_PREOP_SUCCESS_WITH_CALLBACK | The minifilter is returning the I/O operation to *FltMgr* for further processing. In this case, *FltMgr* calls the minifilter's post-operation callback during I/O completion. |
| FLT_PREOP_SYNCHRONIZE | The minifilter is returning the I/O operation to *FltMgr* for further processing, but it is not completing the operation. See Remarks for details. |
| FLT_PREOP_DISALLOW_FSFILTER_IO | The minifilter is disallowing a fast QueryOpen operation and forcing the operation down the slow path. Doing so causes the I/O manager to service the request by performing an open/query/close of the file. Minifilter drivers should only return this status for QueryOpen. |

## Remarks

See [Writing pre-operation callback routines](https://learn.microsoft.com/windows-hardware/drivers/ifs/writing-preoperation-callback-routines) for additional information.

A minifilter's pre-operation callback routine processes one or more types of I/O operations. (This callback routine is similar to a [dispatch routine in the legacy filter model](https://learn.microsoft.com/windows-hardware/drivers/ifs/writing-irp-dispatch-routines).)

A minifilter registers a pre-operation callback routine for a particular type of I/O operation by storing the callback routine's entry point in the **OperationRegistration** array of the [**FLT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure. The minifilter passes this structure as a parameter to [**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) in its [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/ifs/writing-a-driverentry-routine-for-a-minifilter-driver) routine. A minifilter can register a pre-operation callback routine for a given type of I/O operation without registering a post-operation callback ([**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine and vice versa.

A minifilter driver's pre-operation or post-operation callback routine can modify the contents of the callback data structure for the operation. If it does, it must then call [**FltSetCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty), unless it has changed the contents of the callback data structure's **IoStatus** field.

The IRQL for this generic callback routine depends on its specific IO paths. You can quickly and cheaply call [**KeGetCurrentIRQL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql) if you need to know the current IRQL. See [Writing pre-operation callback routines](https://learn.microsoft.com/windows-hardware/drivers/ifs/writing-preoperation-callback-routines) for additional information about IRQL.

File systems round up write and read operations at end of file to a multiple of the sector size of the underlying file storage device. When processing pre-read or pre-write operations, filters that allocate and swap buffers need to round the size of an allocated buffer up to a multiple of the sector size of the associated device. If they do not, the length of data transferred from the underlying file system will exceed the allocated length of the buffer. For more information about swapping buffers, see the [SwapBuffers Minifilter Sample](https://learn.microsoft.com/samples/microsoft/windows-driver-samples/swapbuffer-file-system-minifilter-driver/).

Starting with Windows 8, **CompletionContext** uses the [**_Flt_CompletionContext_Outptr_**](https://learn.microsoft.com/windows-hardware/drivers/devtest/-flt-completioncontext-outptr--annotation) annotation which defines valid context values based on the operation result. The following is a usage example for the callback with the annotation for **CompletionContext**.

```cpp
FLT_PREOP_CALLBACK_STATUS
SwapPreReadBuffers(
    _Inout_ PFLT_CALLBACK_DATA Data,
    _In_ PCFLT_RELATED_OBJECTS FltObjects,
    _Flt_CompletionContext_Outptr_ PVOID *CompletionContext
    );

```

### Returning FLT_PREOP_COMPLETE

If this routine returns FLT_PREOP_COMPLETE, it must set the callback data structure's **IoStatus.Status** field to the final NTSTATUS value for the I/O operation. This NTSTATUS value cannot be STATUS_PENDING. For a cleanup or close operation, it must be a success NTSTATUS value other than STATUS_PENDING because cleanup and close operations cannot fail.

When this routine returns FLT_PREOP_COMPLETE, *FltMgr* won't send the I/O operation to any minifilter drivers below the caller in the driver stack or to the file system. In this case, *FltMgr* only calls the post-operation callback routines of the minifilter drivers above the caller in the driver stack.

### Returning FLT_PREOP_DISALLOW_FASTIO

If this routine returns FLT_PREOP_DISALLOW_FASTIO, it should not set the callback data structure's **IoStatus.Status** field because *FltMgr* automatically sets this field to STATUS_FLT_DISALLOW_FAST_IO.

FLT_PREOP_DISALLOW_FASTIO can only be returned for a fast I/O operation. To determine whether a given callback data structure represents a fast I/O operation, use the [**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation) macro.

When this routine returns FLT_PREOP_DISALLOW_FASTIO, *FltMgr* won't send the fast I/O operation to any minifilter drivers below the caller in the driver stack or to the file system. In this case, *FltMgr* only calls the post-operation callback routines of the minifilter drivers above the caller in the driver stack.

### Returning FLT_PREOP_PENDING

FLT_PREOP_PENDING can only be returned for IRP-based I/O operations because only IRP-based I/O operations can be pended. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_irp_operation) macro.

When this routine returns FLT_PREOP_PENDING, *FltMgr* won't process the I/O operation further until the minifilter driver calls [**FltCompletePendedPreOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation).

### Returning FLT_PREOP_SYNCHRONIZE

If a minifilter's pre-operation callback routine returns FLT_PREOP_SYNCHRONIZE, the minifilter must have registered a corresponding post-operation callback for the operation. When this routine returns FLT_PREOP_SYNCHRONIZE, *FltMgr* calls the minifilter's post-operation callback in the context of the current thread at IRQL <= APC_LEVEL.

FLT_PREOP_SYNCHRONIZE should only be returned for IRP-based I/O operations. If it is returned for an I/O operation that is not an IRP-based operation, *FltMgr* treats this return value as if it were FLT_PREOP_SUCCESS_WITH_CALLBACK.

Minifilter drivers should not return FLT_PREOP_SYNCHRONIZE for create operations, because these operations are already synchronized by *FltMgr*.

Minifilters must never return FLT_PREOP_SYNCHRONIZE for asynchronous read and write operations. Doing so can severely degrade both minifilter driver and system performance.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IO_PARAMETER_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_irp_operation)

[**FLT_IS_REISSUED_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_reissued_io)

[**FLT_IS_SYSTEM_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_system_buffer)

[**FLT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[**FltCompletePendedPostOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation)

[**FltCompletePendedPreOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation)

[**FltQueueDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem)

[**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[**FltSetCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty)

[**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[**_Flt_CompletionContext_Outptr_**](https://learn.microsoft.com/windows-hardware/drivers/devtest/-flt-completioncontext-outptr--annotation)

[**KeGetCurrentIRQL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql)
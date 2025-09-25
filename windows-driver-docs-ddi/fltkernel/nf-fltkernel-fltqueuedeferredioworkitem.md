# FltQueueDeferredIoWorkItem function

## Description

The **FltQueueDeferredIoWorkItem** routine posts an IRP-based I/O operation to a work queue.

## Parameters

### `FltWorkItem` [in]

A pointer to the work item to add to the work queue. The work item must have been allocated by calling [**FltAllocateDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatedeferredioworkitem).

### `Data` [in]

A pointer to the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure for the I/O operation. The operation must be an IRP-based I/O operation. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

### `WorkerRoutine` [in]

A pointer to a caller-supplied worker callback routine. This routine is declared as follows:

``` C
typedef VOID
(*PFLT_DEFERRED_IO_WORKITEM_ROUTINE) (
    _In_ PFLT_DEFERRED_IO_WORKITEM FltWorkItem,
    _In_ PFLT_CALLBACK_DATA CallbackData,
    _In_opt_ PVOID Context
    );
```

where:

* **FltWorkItem** is an opaque pointer to a deferred work item structure.
* **CallbackData** is a pointer to the callback data structure for the I/O operation.
* **Context** is an optional context information pointer that was passed as the **Context** parameter of **FltQueueDeferredIoWorkItem**.

### `QueueType` [in]

Specifies the queue into which the work item that **FltWorkItem** points to is to be inserted. **QueueType** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **CriticalWorkQueue** | Insert the work item into the queue from which a system thread with a real-time priority attribute processes the work item. |
| **DelayedWorkQueue** | Insert the work item into the queue from which a system thread with a variable priority attribute processes the work item. |

The **QueueType** value **HyperCriticalWorkQueue** is reserved for system use.

### `Context` [in]

A pointer to caller-defined context information to be passed as the **Context** parameter of the callback routine specified in the **WorkerRoutine** parameter.

## Return value

The **FltQueueDeferredIoWorkItem** routine returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_DELETING_OBJECT | The target instance for the I/O operation (**Data->Iopb->TargetInstance**) is being torn down. This is an error code. |
| STATUS_FLT_NOT_SAFE_TO_POST_OPERATION | The I/O operation cannot be posted safely to a worker thread. See Remarks for possible reasons why this error code is returned. |

## Remarks

The **FltQueueDeferredIoWorkItem** routine posts an I/O operation to a system work queue. The specified **WorkerRoutine** callback routine is called in the context of a system thread, at IRQL PASSIVE_LEVEL.

The operation must be an IRP-based I/O operation. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

**FltQueueDeferredIoWorkItem** returns STATUS_FLT_NOT_SAFE_TO_POST_OPERATION when the I/O operation cannot be posted safely to a worker thread. Possible reasons include the following:

* **FltQueueDeferredIoWorkItem** cannot post a paging I/O operation to a worker thread.

* **FltQueueDeferredIoWorkItem** cannot post an I/O operation to a worker thread if the **TopLevelIrp** field of the current thread is not **NULL**, because the resulting file system recursion could cause deadlocks or stack overflows. For more information, see [**IoGetTopLevelIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp).

A minifilter driver can use **FltQueueDeferredIoWorkItem** in a preoperation callback ([**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine as follows:

1. The preoperation callback calls [**FltAllocateDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatedeferredioworkitem) to allocate the work item.

2. The preoperation callback calls **FltQueueDeferredIoWorkItem** to post the operation to the work queue.

3. The preoperation callback returns FLT_PREOP_PENDING.

4. After processing the I/O operation, the work routine calls [**FltCompletePendedPreOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation) to return the I/O operation to the Filter Manager.

5. The work routine calls [**FltFreeDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreedeferredioworkitem) to free the work item.

A minifilter driver can use **FltQueueDeferredIoWorkItem** in a post-operation callback ([**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine as follows:

1. The post-operation callback calls [**FltAllocateDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatedeferredioworkitem) to allocate the work item.

2. The post-operation callback calls **FltQueueDeferredIoWorkItem** to post the operation to the work queue.

3. The post-operation callback returns FLT_POSTOP_MORE_PROCESSING_REQUIRED.

4. After processing the I/O operation, the work routine calls [**FltCompletePendedPostOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation) to return the I/O operation to the Filter Manager.

5. The work routine calls [**FltFreeDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreedeferredioworkitem) to free the work item.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[**FltAllocateDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatedeferredioworkitem)

[**FltCompletePendedPostOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation)

[**FltCompletePendedPreOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation)

[**FltFreeDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreedeferredioworkitem)

[**IoGetTopLevelIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp)

[**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)
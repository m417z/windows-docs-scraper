# FltQueueGenericWorkItem function

## Description

**FltQueueGenericWorkItem** posts a work item that is not associated with a specific I/O operation to a work queue.

## Parameters

### `FltWorkItem` [in]

Pointer to the work item to be added to the work queue. The work item must have been allocated by calling [FltAllocateGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocategenericworkitem).

### `FltObject` [in]

Opaque filter (PFLT_FILTER) or instance (PFLT_INSTANCE) pointer for the caller.

### `WorkerRoutine` [in]

Pointer to a caller-supplied worker routine. This routine is declared as follows:

```
typedef VOID
(*PFLT_GENERIC_WORKITEM_ROUTINE) (
 _In_ PFLT_GENERIC_WORKITEM FltWorkItem,
 _In_ PVOID FltObject,
 _In_opt_ PVOID Context
      );
```

#### FltWorkItem

Opaque pointer to a generic work item structure.

#### FltObject

Opaque filter pointer that was passed as the *FltObject* parameter of **FltQueueGenericWorkItem**.

#### Context

Context information pointer that was passed as the *Context* parameter of **FltQueueGenericWorkItem**. This parameter is optional.

### `QueueType` [in]

Specifies the queue into which the work item that *FltWorkItem* points to is to be inserted. *QueueType* can be either of the following:

| Value | Meaning |
| --- | --- |
| **CriticalWorkQueue** | Insert the work item into the queue from which a system thread with a real-time priority attribute processes the work item. |
| **DelayedWorkQueue** | Insert the work item into the queue from which a system thread with a variable priority attribute processes the work item. |

The *QueueType* value **HyperCriticalWorkQueue** is reserved for system use.

### `Context` [in, optional]

Pointer to caller-defined context information to be passed as the *Context* parameter of the callback routine specified in the *WorkerRoutine* parameter. This parameter is optional.

## Return value

**FltQueueGenericWorkItem** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The minifilter driver is being unloaded. This is an error code. |

## Remarks

**FltQueueGenericWorkItem** inserts a work item that is not associated with a specific I/O operation into a system work queue. The specified *WorkerRoutine* callback routine is called in the context of a system thread, at IRQL PASSIVE_LEVEL.

To allocate a work item, call [FltAllocateGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocategenericworkitem).

To free the work item when it is no longer needed, call [FltFreeGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreegenericworkitem).

## See also

[FltAllocateGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocategenericworkitem)

[FltFreeGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreegenericworkitem)
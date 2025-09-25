## Description

**ExInitializeWorkItem** initializes a work-queue item with a caller-supplied context and callback routine to be queued for execution when a system worker thread is given control.

> [!WARNING]
> Use this routine with extreme caution. See the **Remarks** section below.

## Parameters

### `Item` [in]

Pointer to a caller-allocated WORK_QUEUE_ITEM structure to be initialized. This structure must be allocated from nonpaged pool. The callback routine specified in the *Routine* parameter is responsible for freeing this work item when it is no longer needed by calling [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) or [ExFreePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag).

### `Routine` [in]

Pointer to a caller-defined routine that will be called to process the work item. This routine will be called in the context of a system thread at IRQL PASSIVE_LEVEL. This routine is declared as follows:

```cpp
VOID
(*PWORKER_THREAD_ROUTINE)(
    IN PVOID Parameter
    );
```

#### Parameter

Context information pointer that was passed in the *Context* parameter.

### `Context` [in]

Pointer to caller-supplied context information to be passed to the callback routine specified in the *Routine* parameter.

## Remarks

**ExInitializeWorkItem** initializes the work item with the specified callback routine and context pointer and **NULL** list pointers.

To add the work item to a system work queue, call [ExQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exqueueworkitem).

Work items are a limited resource, and drivers should only allocate them as needed. For example, do not allocate a work item in [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) for the driver's dedicated use.

**ExInitializeWorkItem** and [ExQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exqueueworkitem) can only be used in cases where the specified work item is not associated with any device object or device stack. In all other cases, drivers should use [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem), [IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem), and [IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem), because only these routines ensure that the device object associated with the specified work item remains available until the work item has been processed.

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[ExFreePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag)

[ExQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exqueueworkitem)

[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem)

[IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem)

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)

[**WORK_QUEUE_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_work_queue_item)
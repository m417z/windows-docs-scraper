# WdfInterruptTryToAcquireLock function

## Description

[Applies to KMDF and UMDF]

 The **WdfInterruptTryToAcquireLock** method attempts to acquire an interrupt object's passive lock.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Return value

**WdfInterruptTryToAcquireLock** returns TRUE if it successfully acquires the interrupt’s lock. Otherwise, the method returns FALSE.

## Remarks

Drivers that use [passive-level interrupt handling](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts) call **WdfInterruptTryToAcquireLock** to start a code sequence that executes at IRQL = PASSIVE_LEVEL while holding the passive-level interrupt lock that the driver configured in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

**WdfInterruptTryToAcquireLock** attempts to acquire the lock and then returns immediately, whether it has acquired the lock or not. If **WdfInterruptTryToAcquireLock** does successfully acquire the lock, the framework calls [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) before returning so that normal kernel APCs are disabled.

For passive-level interrupt objects, drivers must call **WdfInterruptTryToAcquireLock** instead of [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85)), when running in an arbitrary thread, such as a [queue object callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/). For example, the driver might call **WdfInterruptTryToAcquireLock** from [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read). Doing so avoids the possibility of deadlock, as described in the Remarks section of **WdfInterruptAcquireLock**.

When running in a non-arbitrary thread, such as a work item, the driver should use [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85)).

When the driver calls [WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85)), the framework releases the interrupt lock.

#### Examples

The following code example shows how an [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read) callback function, running in an arbitrary context, might call **WdfInterruptTryToAcquireLock** before performing interrupt-related work. If the method returns FALSE, the driver queues a work item to perform the work in a non-arbitrary thread. The driver also supplies an [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function that calls [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85)) before it performs the work.

 In this example, the driver has specified [sequential](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests) dispatching for the queue. If the driver specified *any other dispatching method* for the queue, the driver should use an additional manual queue to retain requests for processing in the work item. Code comments describe where to add such support.

```cpp

VOID EvtIoRead(
  __in  WDFQUEUE Queue,
  __in  WDFREQUEST Request,
  __in  size_t Length
    )
{
    DEVICE_CONTEXT    devCtx;
    devCtx = GetDeviceContext(WdfIoQueueGetDevice(Queue));

    //
    // Do any pre-acquiring interrupt lock work here.
    //

    //
    // Check if we can acquire the lock.
    //
    if (WdfInterruptTryToAcquireLock(devCtx->InterruptObject) {
        ReadFunctionLocked(Request);
        WdfInterruptReleaseLock(devCtx->InterruptObject);
        //
        // Do any post-releasing interrupt lock work here.
        // For example: complete the request, and so on.
        //
        ReadFunctionFinish(Request);
    }
    else {
        WORK_ITEM_CONTEXT ctx;

        ctx = GetWorkItemContext(ReadWorkItem);
        ctx->Request = Request;

        // If previous queue is non-sequential, call WdfRequestForwardToIoQueue
        // to store request in an additional manual queue.

        WdfWorkItemEnqueue(ReadWorkItem);
    }
}

VOID
EvtReadWorkItemCallback(
    WDFWORKITEM WorkItem
    )
{
    WORK_ITEM_CONTEXT wiCtx;
    DEVICE_CONTEXT    devCtx;

    wiCtx = GetWorkItemContext(ReadWorkItem);
    devCtx = GetDeviceContext(WdfWorkItemGetParentObject(WorkItem));

    // If delivery queue is non-sequential, call WdfIoQueueRetrieveNextRequest
    // to retrieve request that we stored in EvtIoRead.

    //
    // Acquire interrupt lock.
    //
    WdfInterruptAcquireLock(devCtx->InterruptObject);
    ReadFunctionLocked(wiCtx->Request);
    WdfInterruptReleaseLock(devCtx->InterruptObject);

    //
    // Do any post-releasing interrupt lock work here.
    // For example: complete the request, and so on.
    //
    ReadFunctionFinish(wiCtx->Request);
}
```

## See also

[EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem)

[WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)

[WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85))

[WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85))

[WdfIoQueueRetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievenextrequest)

[WdfRequestRequeue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestrequeue)

[WdfWaitLockAcquire](https://learn.microsoft.com/previous-versions/ff551168(v=vs.85))
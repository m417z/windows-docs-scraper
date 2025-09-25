# WdfWorkItemEnqueue function

## Description

[Applies to KMDF and UMDF]

The **WdfWorkItemEnqueue** method adds a specified framework work-item object to the system's work-item queue.

## Parameters

### `WorkItem` [in]

A handle to a framework work-item object that is obtained from a previous call to [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After the driver calls [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate) to create a work item, the driver must call **WdfWorkItemEnqueue** to add the work item to the system's work-item queue. A system worker thread subsequently removes the work item from the queue and calls the work item's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function. The system removes the work items in the order that they were added to the queue.

Before drivers call **WdfWorkItemEnqueue**, they typically use the work-item object's context memory to store information about the work item. The [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function uses this information to determine the operation that it must perform.

For versions 1.7 and later of KMDF, if your driver reuses its work-item objects, the driver can call **WdfWorkItemEnqueue** again for the same work item before a system worker thread has dequeued the work item and subsequently called the driver's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function. However, KMDF will not add the work item to the queue if it is already there. Therefore, your *EvtWorkItem* callback function must process all queued work each time that it is called.

Your driver can also call **WdfWorkItemEnqueue** while an [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function is running, to queue another work item. The second work item's *EvtWorkItem* callback might even run before the first one completes.

In versions of KMDF prior to version 1.7, if your driver reuses its work-item objects, it must not call **WdfWorkItemEnqueue** again for the same work item until a system worker thread has dequeued the work item and called its [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function.

For more information about work items, see [Using Framework Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

#### Examples

This section contains two examples. The first example shows how to add work items to a queue for KMDF versions 1.7 and later. The second example shows how to add work items to a queue for KMDF versions prior to version 1.7

**Example 1: KMDF versions 1.7 and later**

The following code example calls a local routine that returns a pointer to a work-item object's context memory. The example sets information in the object's context memory and then calls **WdfWorkItemEnqueue**. The driver's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function will later retrieve the information from the work-item object.

```cpp
PMY_CONTEXT_TYPE context;

context = GetWorkItemContext(hWorkItem);
context->FdoData = FdoData;
context->Argument1 = Context1;
context->Argument2 = Context2;

WdfWorkItemEnqueue(hWorkItem);
```
The driver's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function contains the following code.

```cpp
MyWorkItemCallback (
    IN WDFWORKITEM hWorkItem
    )
{
    PMY_CONTEXT_TYPE context;

    context = GetWorkItemContext(hWorkItem);

    //
    // Do work here.
    //
    ...
    //
    return;
}
```
**Example 2: KMDF versions prior to 1.7**

The following code example calls a local routine that returns a pointer to a work-item object's context memory. The example sets information in the object's context memory, sets a state variable to "busy", and then calls **WdfWorkItemEnqueue**. The driver's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function will later retrieve the information from the work-item object.

```cpp
typedef enum _WORKITEM_STATE {
    WORKITEM_STATE_FREE =0,
    WORKITEM_STATE_BUSY = 1
} WORKITEM_STATE;
...
PMY_CONTEXT_TYPE context;

context = GetWorkItemContext(hWorkItem);
context->FdoData = FdoData;
context->Argument1 = Context1;
context->Argument2 = Context2;

if (InterlockedCompareExchange(
                               (PLONG)&context->WorkItemState,
                               WORKITEM_STATE_BUSY,
                               WORKITEM_STATE_FREE
                               ) == WORKITEM_STATE_FREE) {
 WdfWorkItemEnqueue(hWorkItem);
}
```
The driver's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function contains the following code. Just before the **return** statement, the code sets the work-item object's state variable to "free" so that the driver can queue the object again.

```cpp
MyWorkItemCallback (
    IN WDFWORKITEM hWorkItem
    )
{
    PMY_CONTEXT_TYPE context;
    LONG result;

    context = GetWorkItemContext(hWorkItem);

    //
    // Do work here.
    //
    ...
    //
    // Reset object state.
    //
    result = InterlockedExchange(
                                 (PLONG)&context->WorkItemState,
                                 WORKITEM_STATE_FREE
                                 );
    ASSERT(result == WORKITEM_STATE_BUSY);
    return;
}
```

## See also

[EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem)

[InterlockedCompareExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedcompareexchange)

[InterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchange)

[WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate)
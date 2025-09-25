# WdfWorkItemFlush function

## Description

[Applies to KMDF and UMDF]

The **WdfWorkItemFlush** method returns after a specified work item has been serviced.

## Parameters

### `WorkItem` [in]

A handle to a framework work-item object that is obtained from a previous call to [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If [**WdfWorkItemEnqueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemenqueue) has been called and your driver calls the **WdfWorkItemFlush** method, the method does not return until a system worker thread has removed the specified work item from the work-item queue and called the driver's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function, and the *EvtWorkItem* callback function has subsequently returned after processing the work item.
Note that **WdfWorkItemFlush** does wait for an already running *EvtWorkItem* callback function to complete.

If **WdfWorkItemEnqueue** has not been called, calling **WdfWorkItemFlush** completes immediately.

It is illegal to call **WdfWorkItemFlush** from within the work item callback or from code it calls that runs on the same system worker thread.
Indeed, if driver verifier is enabled, WDF breaks into the debugger to warn that doing so will lead to deadlock.
On the other hand, calling [**WdfObjectDelete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) on the work item object from within the callback is perfectly fine.

Most drivers that use work items do not need to call **WdfWorkItemFlush**. A driver might call **WdfWorkItemFlush** if it must synchronize completion of work items with the removal of a remote I/O target. In this case, the driver can call **WdfWorkItemFlush** from within its [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function.

For more information about work items, see [Using Framework Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

#### Examples

The following code example is an [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function from the [Toaster](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver.

```cpp
NTSTATUS
ToastMon_EvtIoTargetQueryRemove(
    WDFIOTARGET IoTarget
)
{
    PTARGET_DEVICE_INFO  targetDeviceInfo = NULL;
    //
    // Get the I/O target object's context.
    //
    targetDeviceInfo = GetTargetDeviceInfo(IoTarget);
    //
    // Ensure that the I/O target's work item
    // has been processed before closing the target.
    //
    WdfWorkItemFlush(targetDeviceInfo->WorkItem);
    WdfIoTargetCloseForQueryRemove(IoTarget);

    return STATUS_SUCCESS;
}
```

## See also

[EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem)
# WdfIoTargetCloseForQueryRemove function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetCloseForQueryRemove** method temporarily closes a specified [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets) because the target device might soon be removed.

## Parameters

### `IoTarget` [in]

A handle to a remote I/O target object that was obtained from a previous call to [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Drivers that supply an [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function must call **WdfIoTargetCloseForQueryRemove** from within that callback function, if the driver determines that the target device can be safely removed.

For more information about **WdfIoTargetCloseForQueryRemove**, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example is the [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function from the [Toaster](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. The function stops a timer, ensures that a previously submitted work item has been serviced, and then calls **WdfIoTargetCloseForQueryRemove**.

```cpp
NTSTATUS
ToastMon_EvtIoTargetQueryRemove(
    WDFIOTARGET IoTarget
)
{
    PTARGET_DEVICE_INFO  targetDeviceInfo = NULL;

    //
    // Get I/O target object's context space.
    //
    targetDeviceInfo = GetTargetDeviceInfo(IoTarget);

    //
    // Stop the timer and wait for any outstanding work items
    // to finish before closing the target.
    //
    WdfTimerStop(targetDeviceInfo->TimerForPostingRequests, TRUE);
    WdfWorkItemFlush(targetDeviceInfo->WorkItemForPostingRequests);

    WdfIoTargetCloseForQueryRemove(IoTarget);

    return STATUS_SUCCESS;
}
```

## See also

[EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)
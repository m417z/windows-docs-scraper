# IOCTL_SRIOV_ATTACH IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

The request indicates that the virtualization stack wants to register for Plug and Play events received by the SR-IOV device.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes GUID_DEVINTERFACE_VIRTUALIZABLE_DEVICE.

This request is unsafe if the PF device is currently stopped or stopping for resource re-balance. A device is
considered to be stopped after it received [IRP_MN_QUERY_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-stop-device) and restarted when it receives [IRP_MN_CANCEL_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-cancel-stop-device) or when [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)
is completed by the lower devices in the stack. In this case, the driver must delay the completion of this request until the device is restarted.

It is not necessary to keep this IRP pending because the request always a sent as
a synchronous kernel-mode IRP causing the caller to block the thread in any case.

Upon the completion of this request, the VSP can subsequently send
[IOCTL_SRIOV_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_notification) and [IOCTL_SRIOV_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_event_complete) requests.

To unregister for Plug and Play events, the VSP sends the [IOCTL_SRIOV_DETACH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_detach) request.

These events (defined in [SRIOV_PF_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ne-pcivirt-_sriov_pf_event)) cause the completion of [IOCTL_SRIOV_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_notification) and a wait for [IOCTL_SRIOV_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_event_complete):

* [IRP_MN_QUERY_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-stop-device) generates **SriovEventPfQueryStopDevice**.
* [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) generates **SriovEventPfRestart** *if and only if* the device was stopped for rebalancing (see above).
* [IRP_MN_CANCEL_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-cancel-stop-device) generates **SriovEventPfRestart** *if and only if* the device was stopped for rebalancing.
* [IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device) generates **SriovEventPfQueryRemoveDevice**.
* [IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal) generates **SriovEventPfSurpriseRemoveDevice**.

In this example handling of the IOCTL_SRIOV_ATTACH request, the PF driver maintains PnP states in its device context. The deviceContext->PnpRebalancing is set to TRUE, when the driver receives IRP_MN_QUERY_STOP_DEVICE and set to FALSE when it receives IRP_MN_START_DEVICE.

```cpp
    case IOCTL_SRIOV_ATTACH:
        TraceEvents(TRACE_LEVEL_VERBOSE, DBG_IOCTL, "IOCTL_SRIOV_ATTACH:\n");

        WdfWaitLockAcquire(fdoContext->PnpStateLock, NULL);

        //
        // Block until it is safe for the VSP to attach.  Don't
        // bother with pending this IRP since this is always a sent as
        // a synchronous kernel-mode IRP and the caller would block
        // the thread anyway.  May need to repeat the wait since
        // waiting for the safe-to-attach event must not be done while
        // holding the state lock.
        //
        while (fdoContext->PnpSafeToAttach == FALSE)
        {
            WdfWaitLockRelease(fdoContext->PnpStateLock);

            KeWaitForSingleObject(&fdoContext->PnpSafeEvent,
                                  Executive,
                                  KernelMode,
                                  FALSE,
                                  NULL);

            WdfWaitLockAcquire(fdoContext->PnpStateLock, NULL);
        }

        //
        // Allow only a single attach at any time.
        //
        if (fdoContext->PnpVspAttached == FALSE)
        {
            fdoContext->PnpVspAttached = TRUE;
            status = STATUS_SUCCESS;
        }
        else
        {
            status = STATUS_SHARING_VIOLATION;
        }
        WdfWaitLockRelease(fdoContext->PnpStateLock);

        break;

```

## See also

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[IOCTL_SRIOV_DETACH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_detach)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)
# IOCTL_SRIOV_DETACH IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

The request indicates that the virtualization stack wants to unregister for Plug and Play events (previously registered through the [IOCTL_SRIOV_ATTACH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_attach) request).

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** indicates the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes GUID_DEVINTERFACE_VIRTUALIZABLE_DEVICE.

From here on, the PF should not expect to receive [IOCTL_SRIOV_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_event_complete) and [IOCTL_SRIOV_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_notification) requests.

The driver that must stop waiting for [IOCTL_SRIOV_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_event_complete).
If the driver is currently waiting it should stop waiting and continue
processing Plug and Play IRPs.

In this example handling of the IOCTL_SRIOV_DETACH request, the PF driver maintains PnP states in its device context. The deviceContext->PnpRebalancing is set to TRUE, when the driver receives [IRP_MN_QUERY_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-stop-device) and set to FALSE when it receives IRP_MN_START_DEVICE.

```cpp
    case IOCTL_SRIOV_DETACH:

        WdfWaitLockAcquire(deviceContext->PnpStateLock, NULL);

        deviceContext->PnpVspAttached = FALSE;

        if (deviceContext->PnpRebalancing != FALSE)
        {
            //
            // Any new client (VSP state machine) will not know about
            // the current rebalance is it should block attach until
            // rebalance is over.
            //

    								deviceContext>PnpSafeToAttach = FALSE;
    								KeClearEvent(&deviceContext>PnpSafeEvent);

        }

        //
        // Unblock the PnP thread if it waiting for an IO control from the
        // client as the client just detached.
        //
        deviceContext->PnpEventStatus = STATUS_SUCCESS;
        KeSetEvent(&deviceContext->PnpUnblockEvent, IO_NO_INCREMENT, FALSE);

        WdfWaitLockRelease(deviceContext->PnpStateLock);

        status = STATUS_SUCCESS;
        break;

```

## See also

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[IOCTL_SRIOV_ATTACH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_attach)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)
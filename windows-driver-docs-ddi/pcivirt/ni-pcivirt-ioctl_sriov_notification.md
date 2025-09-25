# IOCTL_SRIOV_NOTIFICATION IOCTL

## Major Code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

The request indicates that the virtualization stack wants to be notified when one of the events listed in
[SRIOV_PF_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ne-pcivirt-_sriov_pf_event) occurs.

## Parameters

### Input buffer

None. This IOCTL does not use an input buffer.

### Input buffer length

Zero.

### Output buffer

A buffer that contains an [SRIOV_PF_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ne-pcivirt-_sriov_pf_event)-type value filled by the physical function (PF) driver when it completes the request.

### Output buffer length

A pointer to a variable to contain the number of bytes written to the output buffer when the request is completed.

### Input/output buffer

Not used with this operation; set to **NULL**.

### Input/output buffer length

Not used with this operation; set to zero.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** is set to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes GUID_DEVINTERFACE_VIRTUALIZABLE_DEVICE.

The **IOCTL_SRIOV_NOTIFICATION** request is held in a queue by the PF driver until the request is either cancelled by sender or the device experiences one of the events listed in
[SRIOV_PF_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ne-pcivirt-_sriov_pf_event). The driver then completes the pending request.

If the PF driver receives this IOCTL request while processing a Plug and Play event for which the driver has not yet completed a notification, it should complete the IOCTL request immediately with the event details in the output buffer. Otherwise, the driver should queue the request until either it is cancelled or a Plug and Play event that requires notification occurs.

The virtualization stack can send the **IOCTL_SRIOV_NOTIFICATION** request immediately after the previous **IOCTL_SRIOV_NOTIFICATION** request completes. The PF driver must keep track of the fact
that an event notification has been delivered and must not complete two IOCTL requests for the same event twice.

It is pended by the PF driver until it is canceled by the sender or until the PF driver experiences one of several PnP events, at which point it is completed.

```cpp
case IOCTL_SRIOV_NOTIFICATION:
        TraceEvents(TRACE_LEVEL_VERBOSE, DBG_IOCTL,
            "IOCTL_SRIOV_NOTIFICATION:\n");

        status = WdfRequestForwardToIoQueue(Request,
                                            fdoContext->NotificationQueue);
        if (!NT_SUCCESS(status))
        {
            // not able to push it into manual queue, too bad.
            TraceEvents(TRACE_LEVEL_ERROR, DBG_PNP,
                        "WdfRequestForwardToIoQueue failed status=%!STATUS!\n",
                        status);
            break;
        }

        // Pnp might arrived before SRIOV_NOTIFICATION. Serve the new
        // outstanding pnp if there is one.
        CheckPendingNotifications(fdoContext);
        status = STATUS_PENDING;
        break;
```

```cpp
VOID
CheckPendingNotifications(
    __in PDEVICE_CONTEXT DeviceContext
    )
/*
Routine Description:
    This routine checks if there is a pending event and a pending request
    for notification and if so completes the request.

Arguments:
    DeviceContext - Pointer to the device context

Return Value:
    None.
*/
{
    PSRIOV_PF_EVENT notification;
    WDFQUEUE        queue;
    WDFREQUEST      request;
    NTSTATUS        status;

    PAGED_CODE();

    WdfWaitLockAcquire(DeviceContext->PnpStateLock, NULL);

    queue = DeviceContext->NotificationQueue;
    if (DeviceContext->PnpEventNew
        && NT_SUCCESS(WdfIoQueueRetrieveNextRequest(queue, &request)))
    {
        NT_ASSERT(DeviceContext->PnpEventPending != FALSE);
        DeviceContext->PnpEventNew = FALSE;

        status = WdfRequestRetrieveOutputBuffer(request,
                                                sizeof(*notification),
                                                &notification,
                                                NULL);
        if (!NT_SUCCESS(status))
        {
            TraceEvents(TRACE_LEVEL_ERROR, DBG_PNP,
                "WdfRequestRetrieveOutputBuffer[SRIOV_NOTIFICATION] fail: %!STATUS!", status);
            WdfRequestComplete(request, status);
        }
        else
        {
            TraceEvents(TRACE_LEVEL_VERBOSE, DBG_IOCTL, "Retrieved IoQueue request buffer (notification)\n");

            *notification = DeviceContext->PnpEventCode;
            WdfRequestCompleteWithInformation(request,
                                              STATUS_SUCCESS,
                                              sizeof(*notification));
        }
    }

    WdfWaitLockRelease(DeviceContext->PnpStateLock);

    return;
}
```
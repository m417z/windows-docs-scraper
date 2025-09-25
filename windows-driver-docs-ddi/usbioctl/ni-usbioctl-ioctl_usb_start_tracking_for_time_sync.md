# IOCTL_USB_START_TRACKING_FOR_TIME_SYNC IOCTL

## Description

This request registers the caller with USB driver stack for time sync services.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

A pointer to a [USB_START_TRACKING_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_start_tracking_for_time_sync_information) structure. On input, the caller must set the **TimeTrackingHandle** member to NULL. On output, the USB driver stack sets the **TimeTrackingHandle** member to a handle that tracks the sync services operation.

### Input/output buffer length

The size of the [USB_START_TRACKING_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_start_tracking_for_time_sync_information) structure.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** indicates an appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

When this IOCTL request completes, the USB driver stack enables certain interrupts from the host controller to keep track of closest frame/microframe boundary in order to predict the system QPC value with accuracy. Enabling the hardware interrupts adds an overhead to the power consumption because the CPU wakes up every 2.048 seconds when working in the D0 power state. Therefore we recommend that the caller should register for time sync services only when needed.

The driver stack disables those interrupts when it receives and completes the [IOCTL_USB_STOP_TRACKING_FOR_TIME_SYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_stop_tracking_for_time_sync) request.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)
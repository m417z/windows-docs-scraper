# IOCTL_USB_UNREGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE IOCTL

## Description

This request unregisters the caller from getting notifications about transport characteristics changes.

## Parameters

### Major code

### Input buffer

A pointer to a [USB_TRANSPORT_CHARACTERISTICS_CHANGE_UNREGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics_change_unregistration) structure that contains the registration handle previously received by the [IOCTL_USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_register_for_transport_characteristics_change) request.

### Input buffer length

The size of the [USB_TRANSPORT_CHARACTERISTICS_CHANGE_UNREGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics_change_unregistration) structure.

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** indicates the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

After this request completes the registration handle is considered to be stale and requests sent on that handle are failed by the USB driver stack.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[USB client drivers for Media-Agnostic (MA-USB)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-drivers-for-ma-usb)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)
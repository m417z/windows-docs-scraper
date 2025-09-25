# IOCTL_USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE IOCTL

## Description

This request registers for notifications about the changes in transport characteristics.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

The **AssociatedIrp.SystemBuffer** member is a pointer to a [USB_TRANSPORT_CHARACTERISTICS_CHANGE_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics_change_registration) structure. On input, the client driver can specify the type of notification changes in which the driver is interested by setting the flags in the **ChangeNotificationInputFlags** member.

On output, the structure is filled with the registration handle and initial values of the transport characteristics.

### Input/output buffer length

The size of the [USB_TRANSPORT_CHARACTERISTICS_CHANGE_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics_change_registration) structure.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** indicates the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

 The transport characteristics of MA-USB mediums can vary significantly over time. If the client diver is interested in knowing the latest information at all times, the driver must register for notification by sending the request.

This request can be sent by a user mode application, UMDF driver, or a KMDF driver. USB driver stack checks for stale and bad registration handle. If the request is received on a handle before registration and after unregistration, the driver stack fails the request.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[USB client drivers for Media-Agnostic (MA-USB)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-drivers-for-ma-usb)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)
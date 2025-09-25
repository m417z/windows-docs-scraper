# IOCTL_USB_GET_TRANSPORT_CHARACTERISTICS IOCTL

## Description

The client driver sends this request to retrieve the transport characteristics.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

The **AssociatedIrp.SystemBuffer** member is a pointer to a caller-allocated [USB_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics) structure. On input, set **Version** to USB_TRANSPORT_CHARACTERISTICS_VERSION_1. On output **Version** is reset to a version less than or equal to USB_TRANSPORT_CHARACTERISTICS_VERSION_1; he remaining members of the structure is filled with transport information.

### Input/output buffer length

The size of the [USB_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics) structure.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This request retrieves the transport characteristics to decide on an algorithm for streaming. For example, a display driver can use the latency and bandwidth information to decide its codec selection.

This information might not be always available. The USB driver stack depends on the underlying transport to expose these values. Therefore, the client driver must have a back up mechanism for such cases where the request.

If the client driver is interested in knowing the latest information at all times, the driver must register for notification when transport characteristics change, keep a request pending with the USB driver stack, and unregister when the notification is no longer required. The driver can accomplish all those tasks by sending these IOCTL requests.

* [IOCTL_USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_register_for_transport_characteristics_change)
* [IOCTL_USB_NOTIFY_ON_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_notify_on_transport_characteristics_change)
* [IOCTL_USB_UNREGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_unregister_for_transport_characteristics_change)

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[USB client drivers for Media-Agnostic (MA-USB)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-drivers-for-ma-usb)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)
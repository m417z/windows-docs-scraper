# IOCTL_USB_NOTIFY_ON_TRANSPORT_CHARACTERISTICS_CHANGE IOCTL

## Description

This request notifies the caller of change in transport characteristics.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

The **AssociatedIrp.SystemBuffer** member is a pointer to a caller-allocated [USB_TRANSPORT_CHARACTERISTICS_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics_change_notification) structure. On input the caller passes the registration handle retrieved in the previous [IOCTL_USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_register_for_transport_characteristics_change) request. On output, the structure is filled with the latest information about the type of information for which the caller.

### Input/output buffer length

The size of the [USB_TRANSPORT_CHARACTERISTICS_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_transport_characteristics_change_notification) structure.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** indicates the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This request is kept pending by the USB driver stack until a there is a change in the transport characteristics for which the caller registered. On completion of this request, the USB driver stack returns the information in the output buffer.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[USB client drivers for Media-Agnostic (MA-USB)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-drivers-for-ma-usb)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)
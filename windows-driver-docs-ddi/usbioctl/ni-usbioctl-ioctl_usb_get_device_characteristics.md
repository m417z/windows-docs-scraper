# IOCTL_USB_GET_DEVICE_CHARACTERISTICS IOCTL

## Description

The client driver sends this request to determine general characteristics about a USB device, such as maximum send and receive delays for any request.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

The **AssociatedIrp.SystemBuffer** member is a pointer to a caller-allocated [USB_DEVICE_CHARACTERISTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_device_characteristics)S structure. On input, set **Version** to USB_DEVICE_CHARACTERISTICS_VERSION_1. On output **Version** is reset to a version less than or equal to USB_DEVICE_CHARACTERISTICS_VERSION_1; **UsbDeviceCharacteristicsFlags** is set to USB_DEVICE_CHARACTERISTICS_MAXIMUM_PATH_DELAYS_AVAILABLE and the remaining members of the structure is filled with delay information.

### Input/output buffer length

The size of the [USB_DEVICE_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_device_characteristics) structure.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** indicates the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[USB client drivers for Media-Agnostic (MA-USB)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-drivers-for-ma-usb)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)
# IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE IOCTL

## Description

The **IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE**
I/O request registers the driver of a USB multi-function device (composite driver) with the underlying USB driver stack.

This request is sent by a driver that replaces the Microsoft-provided composite driver, Usbccgp.sys, and implements the function suspend and remote wake-up feature, per the Universal Serial Bus (USB) 3.0 specification.

**IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE** is a kernel-mode I/O control request. This request targets the USB hub physical device object (PDO). This request must be sent at an interrupt request level (IRQL) of PASSIVE_LEVEL.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.Others.Argument1** is a pointer to a caller-allocated and initialized [REGISTER_COMPOSITE_DEVICE<](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_register_composite_device) structure that contains information about the parent driver. To initialize the structure, call the [USBD_BuildRegisterCompositeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_buildregistercompositedevice) routine.

The **AssociatedIrp.SystemBuffer** member points to a caller-allocated buffer that is large enough to hold an array of function handles (typed USBD_FUNCTION_HANDLE) for functions in the USB composite device. The number of elements in the array is indicated by the **FunctionCount** member of [REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_register_composite_device). To obtain the number of functions, inspect the descriptors returned by a get-configuration request.

### Input buffer length

The size of a [REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_register_composite_device) structure.

### Output buffer

On output, the buffer pointed to by **AssociatedIrp.SystemBuffer** member is filled with function handles for functions in the multi-function device.

### Output buffer length

The size of function handles for functions in the device.

### Input/output buffer

### Input/output buffer length

### Status block

The USB driver stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request completes successfully. STATUS_SUCCESS indicates that the function handles are valid.

In case of an error, **Irp->IoStatus.Status** contains an appropriate error status. For example, if the composite driver sends the request more than once, the **Status** is set to STATUS_INVALID_DEVICE_REQUEST.

## Remarks

The purpose of **IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE** is for the composite driver to send a registration request to the USB driver stack. In the registration request, the composite driver specifies the number of functions supported by the device. Therefore, you must send the **IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE** request after determining the number of functions. Typically, that information is retrieved in the composite driver's start-device routine [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device). Note that number of interfaces in a configuration *can* indicate the number of functions, but not always. Certain multi-function devices expose multiple interfaces related to one function. To obtain the number of functions, you must inspect various descriptors that are related to a particular configuration. Those descriptors can be obtained through a get-descriptor request.

In response to the registration request, the USB driver stack provides a list of handles for the functions in the device. For a code example, see [How to Register a Composite Device](https://learn.microsoft.com/windows-hardware/drivers/usbcon/register-a-composite-driver).

After the composite driver is registered, the driver can configure the remote wake-up feature. By using the function handle, the composite driver can send a request [IOCTL_INTERNAL_USB_REQUEST_REMOTE_WAKE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_request_remote_wake_notification) to get remote wake-up notifications from the USB driver stack, when the associated function sends a resume signal.

In order to remove the composite driver's association with the USB driver stack and release all resources that are allocated for registration, the driver must send the [IOCTL_INTERNAL_USB_UNREGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_unregister_composite_device) request.

## See also

[How to Register a Composite Device](https://learn.microsoft.com/windows-hardware/drivers/usbcon/register-a-composite-driver)

[IOCTL_INTERNAL_USB_UNREGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_unregister_composite_device)
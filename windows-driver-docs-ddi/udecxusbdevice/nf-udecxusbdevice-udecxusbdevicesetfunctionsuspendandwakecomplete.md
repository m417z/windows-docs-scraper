# UdecxUsbDeviceSetFunctionSuspendAndWakeComplete function

## Description

Completes an asynchronous request for changing the power state of a particular function of a virtual USB 3.0 device.

## Parameters

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `CompletionStatus` [in]

An appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code that indicates the success or failure of the asynchronous operation.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_DEVICE_SET_FUNCTION_SUSPEND_AND_WAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_set_function_suspend_and_wake)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)
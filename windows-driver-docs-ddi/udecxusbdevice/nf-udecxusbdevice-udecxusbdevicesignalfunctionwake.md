# UdecxUsbDeviceSignalFunctionWake function

## Description

Initiates wake up of the specified function from a low power state. This applies to virtual USB 3.0 devices.

## Parameters

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `Interface` [in]

This value is the **bInterfaceNumber** of the interface that is waking up.

## Remarks

The client driver for the device must have enabled wake capability in the most recent [EVT_UDECX_USB_DEVICE_SET_FUNCTION_SUSPEND_AND_WAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_set_function_suspend_and_wake) call.

If the device is in a low power state, or going to such a state, this call also wakes up the entire device.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_DEVICE_SET_FUNCTION_SUSPEND_AND_WAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_set_function_suspend_and_wake)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)
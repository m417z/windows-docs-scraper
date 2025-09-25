# UdecxUsbDeviceLinkPowerExitComplete function

## Description

Completes an asynchronous request for sending the device to a low power state.

## Parameters

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `CompletionStatus` [in]

An appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code that indicates the success or failure of the asynchronous operation.

## Remarks

When the USB device emulation class extension (UdeCx) gets a request to send the device to a low power state, it invokes the client driver's implementation of the [EVT_UDECX_USB_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_exit) callback function.

After the client driver has performed the necessary steps for sending the virtual USB device to low power state, the driver calls this method to notify the class extension that it has completed the power request.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_exit)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)
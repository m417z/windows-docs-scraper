# UdecxUsbDeviceLinkPowerEntryComplete function

## Description

Completes an asynchronous request for bringing the device out of a low power state.

## Parameters

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `CompletionStatus` [in]

An appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code that indicates the success or failure of the asynchronous operation.

## Remarks

When the USB device emulation class extension (UdeCx) gets a request to bring the device from low power state and enter working state, it invokes the client driver's implementation of the [EVT_UDECX_USB_DEVICE_D0_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_entry) callback function.

After the client driver has performed the necessary steps for bringing the virtual USB device to working state, the driver calls this method to notify the class extension that it has completed the power request.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_DEVICE_D0_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_entry)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)
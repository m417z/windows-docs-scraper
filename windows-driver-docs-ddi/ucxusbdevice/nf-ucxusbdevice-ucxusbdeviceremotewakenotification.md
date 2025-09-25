# UcxUsbDeviceRemoteWakeNotification function

## Description

Notifies UCX that a remote wake signal from the device is received.

## Parameters

### `UsbDevice` [in]

A handle to the USB device object for which the remote wake is received. The client driver retrieved the handle in a previous call to [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate).

### `Interface` [in]

The interface number that sent the remote wake notification.

## Remarks

 This function completes the pending remote wake request from the request driver such as the hub driver or usbccgp driver. If no such request is found, this notification is ignored.

## See also

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)
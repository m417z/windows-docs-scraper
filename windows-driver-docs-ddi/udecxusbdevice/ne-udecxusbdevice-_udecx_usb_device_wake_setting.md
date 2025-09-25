# _UDECX_USB_DEVICE_WAKE_SETTING enumeration

## Description

Defines values for remote wake capability of a virtual USB device.

## Constants

### `UdecxUsbDeviceWakeDisabled`

The USB device cannot send a wake signal to the host controller.

### `UdecxUsbDeviceWakeEnabled`

The USB device can send a wake signal to the host controller.

### `UdecxUsbDeviceWakeNotApplicable`

This value is used only if the USB device is a SuperSpeed device.

## See also

[EVT_UDECX_USB_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_exit)
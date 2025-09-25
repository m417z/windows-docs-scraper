# _UDECX_USB_DEVICE_FUNCTION_POWER enumeration

## Description

Defines values for function wake capability of a virtual USB 3.0 device.

## Constants

### `UdecxUsbDeviceFunctionNotSuspended`

The USB interface cannot enter function suspend.

### `UdecxUsbDeviceFunctionSuspendedCannotWake`

The USB interface cannot send a wake signal to the host controller.

### `UdecxUsbDeviceFunctionSuspendedCanWake`

The USB interface can send a wake signal to the host controller when the function is in suspend state.

## See also

[EVT_UDECX_USB_DEVICE_SET_FUNCTION_SUSPEND_AND_WAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_set_function_suspend_and_wake)
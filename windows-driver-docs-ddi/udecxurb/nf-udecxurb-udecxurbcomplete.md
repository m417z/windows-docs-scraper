# UdecxUrbComplete function

## Description

Completes the URB request with a USB-specific completion status code.

## Parameters

### `Request` [in]

A handle to a framework request object that contains the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) for the transfer.

### `UsbdStatus` [in]

A [USBD_STATUS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff539136(v=vs.85))-typed value that indicates the success or failure of the completed URB request.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)
# UdecxUrbSetBytesCompleted function

## Description

Sets the number of bytes transferred for the URB contained within a framework request object.

## Parameters

### `Request` [in]

A handle to a framework request object that contains the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) for the transfer.

### `BytesCompleted`

The number of transferred bytes to set in the [**URB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb). This value must not be greater than the transfer buffer length.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)
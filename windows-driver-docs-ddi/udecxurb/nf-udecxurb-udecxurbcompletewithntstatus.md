# UdecxUrbCompleteWithNtStatus function

## Description

Completes the URB request with an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Parameters

### `Request` [in]

A handle to a framework request object that contains the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) for the transfer.

### `NtStatus` [in]

A [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)-typed value that indicates the success or failure of the completed URB request.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)
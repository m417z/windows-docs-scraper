# UdecxUrbRetrieveBuffer function

## Description

Retrieves the transfer buffer of an URB from the specified framework request object sent to the endpoint queue.

## Parameters

### `Request` [in]

A handle to a framework request object that contains the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) for the transfer.

### `TransferBuffer` [out]

A pointer to a buffer that receives the transfer buffer of an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb).

### `Length` [out]

A ULONG variable that receives the length of the buffer pointer to by *TransferBuffer*.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The URB does not contain a transfer buffer. |
| **STATUS_INSUFFICIENT_RESOURCES** | The transfer buffer MDL was not valid. |

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUrbSetBytesCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxurb/nf-udecxurb-udecxurbsetbytescompleted)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)
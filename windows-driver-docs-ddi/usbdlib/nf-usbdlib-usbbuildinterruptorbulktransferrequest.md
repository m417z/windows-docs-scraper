# UsbBuildInterruptOrBulkTransferRequest macro

## Description

The **UsbBuildInterruptOrBulkTransferRequest** macro formats an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) to send or receive data on a bulk pipe, or to receive data from an interrupt pipe.

## Parameters

### `urb` [in, out]

Pointer to an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) to be formatted as an interrupt or bulk transfer request.

### `length` [in]

Specifies the size, in bytes, of the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb).

### `pipeHandle` [in]

Specifies the handle for this pipe returned by the HCD when a configuration was selected.

### `transferBuffer` [in, optional]

Pointer to a resident buffer for the transfer or is **NULL** if an MDL is supplied in *TransferBufferMDL*. The contents of this buffer depend on the value of *TransferFlags*. If USBD_TRANSFER_DIRECTION_IN is specified, this buffer will contain data read from the device on return from the HCD. Otherwise, this buffer contains driver-supplied data to be transferred to the device.

### `transferBufferMDL` [in, optional]

Pointer to an MDL that describes a resident buffer or is **NULL** if a buffer is supplied in *TransferBuffer*. The contents of the buffer depend on the value of *TransferFlags*. If USBD_TRANSFER_DIRECTION_IN is specified, the described buffer will contain data read from the device on return from the HCD. Otherwise, the buffer contains driver-supplied data to be transferred to the device. The MDL must be allocated from nonpaged pool.

### `transferBufferLength` [in]

Specifies the length, in bytes, of the buffer specified in *TransferBuffer* or described in *TransferBufferMDL*.

### `transferFlags` [in]

Specifies zero, one, or a combination of the following flags:

#### USBD_TRANSFER_DIRECTION_IN

Is set to request data from a device. To transfer data to a device, this flag must be clear.

#### USBD_SHORT_TRANSFER_OK

Can be used if USBD_TRANSFER_DIRECTION_IN is set. If set, directs the HCD not to return an error if a packet is received from the device that is shorter than the maximum packet size for the endpoint. Otherwise, a short request returns an error condition.

### `link` [in]

Reserved. Must be set to **NULL**.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)

[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)
# _URB_BULK_OR_INTERRUPT_TRANSFER structure

## Description

The **_URB_BULK_OR_INTERRUPT_TRANSFER** structure is used by USB client drivers to send or receive data on a bulk pipe or on an interrupt pipe.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER, and **Hdr.Length** must be set to `sizeof(_URB_BULK_OR_INTERRUPT_TRANSFER)`.

### `PipeHandle`

Specifies an opaque handle to the bulk or interrupt pipe. The host controller driver returns this handle when the client driver selects the device configuration with a URB of type URB_FUNCTION_SELECT_CONFIGURATION or when the client driver changes the settings for an interface with a URB of type URB_FUNCTION_SELECT_INTERFACE.

### `TransferFlags`

Specifies zero, one, or a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **USBD_TRANSFER_DIRECTION_IN** | Is set to request data from a device. To transfer data to a device, this flag must be clear. |
| **USBD_TRANSFER_DIRECTION_OUT** | Is set to transfer data to a device. Setting this flag is equivalent to clearing the USBD_TRANSFER_DIRECTION_IN flag. |
| **USBD_SHORT_TRANSFER_OK** | Is set to direct the host controller not to return an error when it receives a packet from the device that is shorter than the maximum packet size for the endpoint. The maximum packet size for the endpoint is reported in the **wMaxPacketSize** member of the [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structure (endpoint descriptor). When the host controller receives a packet shorter than **wMaxPacketSize** on a bulk or an interrupt endpoint, the host controller immediately stops requesting data from the endpoint and completes the transfer. If the USBD_SHORT_TRANSFER_OK flag is not set, the host controller completes the transfer with an error. <br><br>This flag should not be set unless USBD_TRANSFER_DIRECTION_IN is also set. **Note** On EHCI host controllers, USBD_SHORT_TRANSFER_OK is ignored for bulk and interrupt endpoints. Transfer of short packets on EHCI controllers does not result in an error condition.<br><br>On UHCI and OHCI host controllers, if USBD_SHORT_TRANSFER_OK is not set for a bulk or interrupt transfer, a short packet transfer halts the endpoint and an error code is returned for the transfer. The client driver must resume the endpoint by submitting a URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL request before submitting a transfer request to the endpoint. |

### `TransferBufferLength`

Specifies the length, in bytes, of the buffer specified in **TransferBuffer** or described in **TransferBufferMDL**. The host controller driver returns the number of bytes sent to or read from the pipe in this member.

### `TransferBuffer`

Pointer to a resident buffer for the transfer or is **NULL** if an MDL is supplied in **TransferBufferMDL**. The contents of this buffer depend on the value of **TransferFlags**. If USBD_TRANSFER_DIRECTION_IN is specified this buffer will contain data read from the device on return from the host controller driver. Otherwise, this buffer contains driver-supplied data for transfer to the device.

### `TransferBufferMDL`

Pointer to an MDL that describes a resident buffer or is **NULL** if a buffer is supplied in **TransferBuffer**. The contents of the buffer depend on the value of **TransferFlags**. If USBD_TRANSFER_DIRECTION_IN is specified, the described buffer will contain data read from the device on return from the host controller driver. Otherwise, the buffer contains driver-supplied data for transfer to the device. This MDL must be allocated from nonpaged pool.

### `UrbLink`

Reserved. Do not use.

### `hca`

Reserved. Do not use.

## Remarks

Drivers can use the **UsbBuildInterruptOrBulkTransferRequest** service routine to format this URB. Buffers specified in **TransferBuffer** or described in **TransferBufferMDL** must be nonpageable.

In an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb), both **TransferBuffer** and **TransferBufferMDL** parameters can be non-NULL values, at the same time. In that case, the transfer buffer and the MDL pointed to **TransferBuffer** and **TransferBufferMDL** must point to the same buffer.

The USB bus driver processes this URB at DISPATCH_LEVEL.

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)
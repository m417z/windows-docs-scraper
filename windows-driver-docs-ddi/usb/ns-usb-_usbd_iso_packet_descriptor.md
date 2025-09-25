# _USBD_ISO_PACKET_DESCRIPTOR structure

## Description

The **USBD_ISO_PACKET_DESCRIPTOR** structure is used by USB client drivers to describe an isochronous transfer packet.

## Members

### `Offset`

Specifies the offset, in bytes, of the buffer for this packet from the beginning of the entire isochronous transfer buffer.

### `Length`

 Set by the host controller to indicate the actual number of bytes received from the device for isochronous IN transfers. **Length** not used for isochronous OUT transfers.

### `Status`

Contains the status, on return from the host controller driver, of this transfer packet.

## Remarks

This structure is used as part of an isochronous transfer request to the host controller driver using the [_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer) structure. The **Offset** member contains the offset from the beginning of the **TransferBuffer** or **TransferBufferMDL** members of **_URB_ISOCH_TRANSFER**.

## See also

[How to Transfer Data to USB Isochronous Endpoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBD_IsochUrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isochurballocate)

[_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer)
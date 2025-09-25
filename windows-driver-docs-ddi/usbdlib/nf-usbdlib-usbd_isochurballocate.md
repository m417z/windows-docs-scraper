# USBD_IsochUrbAllocate function

## Description

The **USBD_IsochUrbAllocate** routine allocates and formats a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure for an isochronous transfer request.

> [!NOTE]
> **For Windows Driver Framework (WDF) Drivers:** If your client driver is WDF-based, you must call the [WdfUsbTargetDeviceCreateIsochUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateisochurb) method instead of **USBD_IsochUrbAllocate** to allocate memory for the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure.

## Parameters

### `USBDHandle` [in]

USBD handle that is retrieved by the client driver in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `NumberOfIsochPackets` [in]

Specifies the maximum number of isochronous packets required to perform the transfer. The transfer buffer is described in a variable-length array of [USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor) structures that stores information about each packet, such as byte offset of the packet within the buffer. The array is specified in the **IsoPacket** member of the [_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer) structure, which is used to define the format of an isochronous request URB.

### `Urb` [out]

Pointer to an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure, which receives the URB allocated by **USBD_IsochUrbAllocate**. All members of the URB structure are set to zero. The allocated URB is large enough to hold the maximum number of isochronous packets indicated by **NumberOfIsochPacket**.

The client driver must free the URB when the driver has finished using it by calling [USBD_UrbFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urbfree).

## Return value

The **USBD_IsochUrbAllocate** routine returns STATUS_SUCCESS if the request is successful. Otherwise, [USBD_UrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urballocate) sets *Urb* to `NULL` and returns an NT status failure code.

Possible values include, but are not limited to, STATUS_INVALID_PARAMETER, which indicates the caller passed in `NULL` to *USBDHandle* or *Urb*.

## See also

- [Allocating and Building URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-add-xrb-support-for-client-drivers)
- [How to Transfer Data to USB Isochronous Endpoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/)
- [USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor)
- [_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer)
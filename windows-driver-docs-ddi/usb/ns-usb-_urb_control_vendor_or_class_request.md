# _URB_CONTROL_VENDOR_OR_CLASS_REQUEST structure

## Description

The **_URB_CONTROL_VENDOR_OR_CLASS_REQUEST** structure is used by USB client drivers to issue a vendor or class-specific command to a device, interface, endpoint, or other device-defined target.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be one of URB_FUNCTION_CLASS_XXX or URB_FUNCTION_VENDOR_XXX GET_STATUS, and **Hdr.Length** must be `sizeof(_URB_CONTROL_VENDOR_OR_CLASS_REQUEST)`.

### `Reserved`

### `TransferFlags`

Specifies zero, one, or a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **USBD_TRANSFER_DIRECTION_IN** | Is set to request data from a device. To transfer data to a device, this flag must be clear. The flag must be set if the pipe is an interrupt transfer pipe. |
| **USBD_SHORT_TRANSFER_OK** | Is set to direct the host controller not to return an error when it receives a packet from the device that is shorter than the maximum packet size for the endpoint. The maximum packet size for the endpoint is reported in the **bMaxPacketSize0** member of the [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) structure (device descriptor) for the default control endpoint. For a non-default control endpoint, maximum packet size is set in the **wMaxPacketSize** member of the [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structure (endpoint descriptor).<br><br>When the host controller receives a packet whose length is shorter than the **wMaxPacketSize** value on a control endpoint, the behavior is as follows depending on the type of host controller:<br><br>* On EHCI host controllers, the host controller proceeds immediately to the status phase of the control transfer. The transfer completes successfully, regardless of whether USBD_SHORT_TRANSFER_OK is set.<br>* On UHCI and OHCI host controllers, if USBD_SHORT_TRANSFER_OK is set, the host controller proceeds to the status phase. If USBD_SHORT_TRANSFER_OK is not set, the host controller abandons the data and status phases of the control transfer and the transfer completes with an error.<br><br>This flag should not be set unless USBD_TRANSFER_DIRECTION_IN is also set. |

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

### `RequestTypeReservedBits`

Reserved. Do not use.

### `Request`

Specifies the USB or vendor-defined request code for the device, interface, endpoint, or other device-defined target.

### `Value`

Specifies a value, specific to **Request**, that becomes part of the USB-defined setup packet for the target. This value is defined by the creator of the code used in **Request**.

### `Index`

Specifies the device-defined index, returned by a successful configuration request, if the request is for an endpoint or interface. Otherwise, **Index** must be zero.

### `Reserved1`

Reserved. Do not use.

## Remarks

Drivers can use the **UsbBuildVendorRequest** service routine format this URB.

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)
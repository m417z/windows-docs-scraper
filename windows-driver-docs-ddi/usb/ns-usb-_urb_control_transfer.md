# _URB_CONTROL_TRANSFER structure

## Description

The **_URB_CONTROL_TRANSFER** structure is used by USB client drivers to transfer data to or from a control pipe.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be URB_FUNCTION_CONTROL_TRANSFER, and **Hdr.Length** must be `sizeof(_URB_CONTROL_TRANSFER)`.

### `PipeHandle`

Handle for the control pipe.

 If target is the default control endpoint, then **PipeHandle** must be **NULL**. In this case, the **TransferFlags** must contain the USBD_DEFAULT_PIPE_TRANSFER flag.

If target is a non-default control endpoint, **PipeHandle** specifies an opaque handle for the control pipe. The host controller driver returns this handle when the client driver selects the device configuration with a URB of type URB_FUNCTION_SELECT_CONFIGURATION or when the client driver changes the settings for an interface with a URB of type URB_FUNCTION_SELECT_INTERFACE.

### `TransferFlags`

Specifies zero, one, or a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **USBD_TRANSFER_DIRECTION_IN** | Is set to request data from a device. To transfer data to a device, this flag must be clear. |
| **USBD_TRANSFER_DIRECTION_OUT** | Is set to transfer data to a device. Setting this flag is equivalent to clearing the USBD_TRANSFER_DIRECTION_IN flag. |
| **USBD_SHORT_TRANSFER_OK** | Is set to direct the host controller not to return an error when it receives a packet from the device that is shorter than the maximum packet size for the endpoint. The maximum packet size for the endpoint is reported in the **bMaxPacketSize0** member of the [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) structure (device descriptor) for the default control endpoint. For a non-default control endpoint, maximum packet size is set in the **wMaxPacketSize** member of the [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structure (endpoint descriptor).<br><br>When the host controller receives a packet whose length is shorter than the **wMaxPacketSize** value on a control endpoint, the behavior is as follows depending on the type of host controller:<br><br>* On EHCI host controllers, the host controller proceeds immediately to the status phase of the control transfer. The transfer completes successfully, regardless of whether USBD_SHORT_TRANSFER_OK is set.<br>* On UHCI and OHCI host controllers, if USBD_SHORT_TRANSFER_OK is set, the host controller proceeds to the status phase. If USBD_SHORT_TRANSFER_OK is not set, the host controller abandons the data and status phases of the control transfer and the transfer completes with an error. |
| **USBD_DEFAULT_PIPE_TRANSFER** | Is set to direct the host controller to do a control transfer on the default control pipe. This allows the caller to send commands to the default control pipe without explicitly specifying the pipe handle. |

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

### `SetupPacket`

Specifies a USB-defined request setup packet. The format of a USB request setup packet is found in the USB core specification.

## Remarks

The [URB_CONTROL_TRANSFER_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_transfer_ex) structure is identical to **URB_CONTROL_TRANSFER**, except that it provides a timeout value in the **Timeout** field.

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[URB_CONTROL_TRANSFER_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_transfer_ex)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)
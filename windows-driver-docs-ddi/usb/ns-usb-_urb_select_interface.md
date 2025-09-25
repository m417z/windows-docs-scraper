# _URB_SELECT_INTERFACE structure

## Description

The **_URB_SELECT_INTERFACE** structure is used by USB client drivers to select an alternate setting for an interface or to change the maximum packet size of a pipe in the current configuration on a USB device.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be URB_FUNCTION_SELECT_INTERFACE, and **Hdr.Length** must be the size of the entire URB.

### `ConfigurationHandle`

Specifies the handle to the configuration that this interface belongs to. The host controller driver returns this handle when the client selects the configuration with an URB_FUNCTION_SELECT_CONFIGURATION request.

### `Interface`

A variable-length [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure that specifies the interface and the new alternate setting for that interface, and if required, the new maximum packet sizes for the corresponding pipes. For more information, see Remarks.

## Remarks

You can use the [GET_SELECT_INTERFACE_REQUEST_SIZE](https://learn.microsoft.com/previous-versions/ff537164(v=vs.85)) macro to determine the size of the URB_FUNCTION_SELECT_INTERFACE URB, and the **UsbBuildSelectInterfaceRequest** routine to format the URB.

The [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure contains information about the interface and its alternate setting. The **Pipes** member of **USBD_INTERFACE_INFORMATION** points to an array of [USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information) structures. The array stores information about the pipes associated with the endpoints of the interface. You can override certain default settings for a pipe, such as its maximum packet size. To alter the maximum packet size, set the USBD_PF_CHANGE_MAX_PACKET flag in `Pipes[i].PipeFlags`, and then specify the new value in `Pipes[i].MaximumPacketSize`.

 After the bus driver successfully completes processing the URB_FUNCTION_SELECT_INTERFACE URB, it returns an array of handles for each pipe in the `Pipes[i].PipeHandle` member. The client driver can store pipe handles to send I/O requests to specific pipes.

## See also

[Configuring USB Devices](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)
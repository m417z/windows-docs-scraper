# _USB_NODE_CONNECTION_INFORMATION structure

## Description

The **USB_NODE_CONNECTION_INFORMATION** structure is used with the [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information) request to retrieve information about a USB port and connected device.

## Members

### `ConnectionIndex`

A value that is greater than or equal to 1 that specifies the number of the port.

### `DeviceDescriptor`

A [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) structure that reports the USB device descriptor that is returned by the attached device during enumeration.

### `CurrentConfigurationValue`

Contains the ID used with the SetConfiguration request to specify that current configuration of the device connected to the indicated port. For an explanation of this value, see section 9.4.7 in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents).

### `LowSpeed`

A Boolean value that indicates whether the port and its connected device are operating at low speed. **TRUE** indicates that the port and its connected device are currently operating at a low speed. **FALSE** indicates otherwise.

### `DeviceIsHub`

A Boolean value that indicates if the device that is attached to the port is a hub. If **TRUE**, the device that is attached to the port is a hub. If **FALSE**, the device is not a hub.

### `DeviceAddress`

The USB-assigned, bus-relative address of the device that is attached to the port.

### `NumberOfOpenPipes`

The number of open USB pipes that are associated with the port.

### `ConnectionStatus`

A [USB_CONNECTION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_connection_status)-typed enumerator that indicates the connection status.

### `PipeList`

An array of [USB_PIPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_pipe_info) structures that describes the open pipes that are associated with the port. Pipe descriptions include the schedule offset of the pipe and the associated endpoint descriptor. This information can be used to calculate bandwidth usage.

## Remarks

If there is no device connected to the USB port, [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information) returns only information about the port. If a device is connected to the port, **IOCTL_USB_GET_NODE_CONNECTION_INFORMATION** returns information about both the port and the connected device.

The [USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex) structure is an extended version of **USB_NODE_CONNECTION_INFORMATION**. The two structures are identical, except for one member. In **USB_NODE_CONNECTION_INFORMATION_EX**, the **LowSpeed** member is replaced by the **Speed** member. **LowSpeed** is a Boolean value, so when it is **TRUE**, the device is low speed. When it is **FALSE**, the device is high speed or full speed. Thus the **USB_NODE_CONNECTION_INFORMATION** structure cannot differentiate between high and full speeds.

The **Speed** member of the [USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex) structure is a UCHAR and it can specify any of the values of the [USB_DEVICE_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ne-usbspec-_usb_device_speed) enumerator.

## See also

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information)

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_CONNECTION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_connection_status)

[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)

[USB_DEVICE_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ne-usbspec-_usb_device_speed)

[USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex)

[USB_PIPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_pipe_info)
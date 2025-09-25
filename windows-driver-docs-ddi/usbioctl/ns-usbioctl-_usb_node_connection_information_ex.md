# _USB_NODE_CONNECTION_INFORMATION_EX structure

## Description

The **USB_NODE_CONNECTION_INFORMATION_EX** structure is used in conjunction with the **[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex)** request to obtain information about the connection associated with the indicated USB port.

## Members

### `ConnectionIndex`

Contains a value greater than or equal to 1 that specifies the number of the port.

### `DeviceDescriptor`

Contains a structure of type **[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)** that reports the USB device descriptor returned by the attached device during enumeration.

### `CurrentConfigurationValue`

Contains the ID used with the SetConfiguration request to specify that current configuration of the device connected to the indicated port. For an explanation of this value, see section 9.4.7 in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents).

### `Speed`

Contains a value of type **[USB_DEVICE_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ne-usbspec-_usb_device_speed)** that indicates the speed of the device.

### `DeviceIsHub`

Indicates, when **TRUE**, that the device attached to the port is a hub.

### `DeviceAddress`

Contains the USB-assigned, bus-relative address of the device that is attached to the port.

### `NumberOfOpenPipes`

Indicates the number of open USB pipes associated with the port.

### `ConnectionStatus`

Contains an enumerator of type **[USB_CONNECTION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_connection_status)** that indicates the connection status.

### `PipeList`

Contains an array of structures of type **[USB_PIPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_pipe_info)** that describes the open pipes associated with the port. Pipe descriptions include the schedule offset of the pipe and the associated endpoint descriptor. This information can be used to calculate bandwidth usage.

## Remarks

If there is no device connected, **[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex)**` just returns information about the port. If a device is connected to the port **IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX** returns information about both the port and the connected device.

The **USB_NODE_CONNECTION_INFORMATION_EX** structure is an extended version of **[USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information)**. The two structures are identical, except for one member. In the extended structure, the **Speed** member indicates the device speed.

The **Speed** member of the **USB_NODE_CONNECTION_INFORMATION_EX** structure is a UCHAR and it can specify any of the values of the **[USB_DEVICE_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ne-usbspec-_usb_device_speed)** enumerator. The **Speed** member supports up to *UsbHighSpeed* (USB 2.0). To determine if a device supports *UsbSuperSpeed* (USB 3.0), use the **[USB_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2)** structure.

The following C++ code snippet from the [USBView sample](https://github.com/microsoft/Windows-driver-samples/tree/main/usb/usbview) demonstrates how to determine if a device supports UsbSuperSpeed (USB 3.0):

```cpp
// Since the USB_NODE_CONNECTION_INFORMATION_EX is used to display
// the device speed, but the hub driver doesn't support indication
// of superspeed, we overwrite the value if the super speed
// data structures are available and indicate the device is operating
// at SuperSpeed.

if (connectionInfoEx->Speed == UsbHighSpeed
    && connectionInfoExV2 != NULL
    && (connectionInfoExV2->Flags.DeviceIsOperatingAtSuperSpeedOrHigher ||
        connectionInfoExV2->Flags.DeviceIsOperatingAtSuperSpeedPlusOrHigher))
{
    connectionInfoEx->Speed = UsbSuperSpeed;
}
```

## See also

- [USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)
- **[USB_CONNECTION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ne-usbioctl-_usb_connection_status)**
- **[USB_PIPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_pipe_info)**
- **[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex)**
- **[USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information)**
- **[USB_DEVICE_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ne-usbspec-_usb_device_speed)**
- **[USB_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2)**
- [USB samples](https://github.com/microsoft/Windows-driver-samples/tree/main/usb)
- [USBView sample](https://github.com/microsoft/Windows-driver-samples/tree/main/usb/usbview)
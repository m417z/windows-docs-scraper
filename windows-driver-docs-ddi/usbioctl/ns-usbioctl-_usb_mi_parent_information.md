# _USB_MI_PARENT_INFORMATION structure

## Description

The **USB_MI_PARENT_INFORMATION** structure contains information about a composite device.

## Members

### `NumberOfInterfaces`

The number of interfaces on the composite device.

## Remarks

A composite device is a device with multiple interfaces (MI). The USB stack treats the interfaces of a composite device as child devices of the composite device and creates a separate PDO for each interface.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_information)
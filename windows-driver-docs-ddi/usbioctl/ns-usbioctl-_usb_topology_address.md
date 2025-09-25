# _USB_TOPOLOGY_ADDRESS structure

## Description

The **USB_TOPOLOGY_ADDRESS** structure is used with the [IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_get_topology_address) I/O request to retrieve information about a USB device's location in the USB device tree.

## Members

### `PciBusNumber`

Specifies the PCI bus number of the USB host controller to which the USB device is attached.

### `PciDeviceNumber`

Specifies the PCI device number of the USB host controller to which the USB device is attached.

### `PciFunctionNumber`

Specifies the PCI function number of the USB host controller to which the USB device is attached.

### `Reserved`

### `RootHubPortNumber`

Specifies the root hub port number through which the USB device is connected. The USB device can be connected to the root port directly, or it can be connected through 1 or more external USB hubs to the port.

### `HubPortNumber`

An array containing the port number on each external hub (between the root hub and the device) through which the USB device is connected. The first element of the array indicates the port on the hub that is connected directly to the root hub. An array containing all zeros indicates that the device is connected directly to the root hub.

### `Reserved2`

## Remarks

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_get_topology_address)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)
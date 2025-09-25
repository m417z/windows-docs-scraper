# _USB_30_HUB_DESCRIPTOR structure

## Description

The **USB_30_HUB_DESCRIPTOR** structure contains a SuperSpeed hub descriptor. For information about the structure members, see [Universal Serial Bus Revision 3.0 Specification](https://www.usb.org/documents), 10.13.2.1 Hub Descriptor, Table 10-3. SuperSpeed Hub Descriptor.

## Members

### `bLength`

The length, in bytes, of the descriptor.

### `bDescriptorType`

 The descriptor type. For SuperSpeed hub descriptors, the value must be USB_30_HUB_DESCRIPTOR_TYPE (0x2A).

### `bNumberOfPorts`

 The number of ports on the hub.

### `wHubCharacteristics`

 The hub characteristics.

### `bPowerOnToPowerGood`

 The time, in 2-millisecond intervals, that it takes the device to turn on completely.

### `bHubControlCurrent`

The maximum current requirements, in milliamperes, of the controller component of the hub.

### `bHubHdrDecLat`

The hub packet header decode latency.

### `wHubDelay`

 The average delay, in nanoseconds, that is introduced by the hub.

### `DeviceRemovable`

 Indicates whether a removable device is attached to each port.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex)
# _USB_HUB_DESCRIPTOR structure

## Description

The **USB_HUB_DESCRIPTOR** structure contains a hub descriptor.
The members of this structure are described in the Universal Serial Bus 3.1 Specification available at [USB Document Library](https://www.usb.org/documents). See section 10.15.2.1.

## Members

### `bDescriptorLength`

The length, in bytes, of the descriptor.

### `bDescriptorType`

The descriptor type. For hub descriptors, this value should be 0x29.

### `bNumberOfPorts`

The number of ports on the hub.

### `wHubCharacteristics`

The hub characteristics. For more information about this member, see Universal Serial Bus Specification.

### `bPowerOnToPowerGood`

The time, in 2-millisecond intervals, that it takes the device to turn on completely. For more information about this member, see Universal Serial Bus Specification.

### `bHubControlCurrent`

The maximum current requirements, in milliamperes, of the controller component of the hub.

### `bRemoveAndPowerMask`

Not currently implemented. Do not use this member.

This member implements DeviceRemovable and PortPwrCtrlMask fields of the hub descriptor. For more information about these fields, see Universal Serial Bus Specification.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_HUB_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information)
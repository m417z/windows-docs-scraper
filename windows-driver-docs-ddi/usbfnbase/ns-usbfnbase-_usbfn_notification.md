# _USBFN_NOTIFICATION structure

## Description

Describes information about a Universal Serial Bus (USB) event notification that was
received by using [IOCTL_INTERNAL_USBFN_BUS_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_bus_event_notification).

## Members

### `Event`

Bus notification indicated by a [USBFN_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_event)-typed flag.

### `u`

### `u.BusSpeed`

The operating bus speed indicated by [USBFN_BUS_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_bus_speed)-typed flags.

### `u.SetupPacket`

Describes a setup packet in a **USB_DEFAULT_PIPE_SETUP_PACKET** structure for a control transfer to or from the default endpoint as indicated by a **USB_DEFAULT_PIPE_SETUP_PACKET**-typed flag.

### `u.ConfigurationValue`

The **bConfigurationValue** field of a USB configuration descriptor.

### `u.PortType`

Possible port types supported by a function controller indicated by a [USBFN_PORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_port_type)-typed flag.

### `u.AlternateInterface`

Alternate setting of the interface indicated by [ALTERNATE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_alternate_interface).
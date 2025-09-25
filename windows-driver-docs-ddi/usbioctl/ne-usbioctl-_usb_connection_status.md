# _USB_CONNECTION_STATUS enumeration

## Description

The **USB_CONNECTION_STATUS** enumerator indicates the status of the connection to a device on a USB hub port.

## Constants

### `NoDeviceConnected`

Indicates that there is no device connected to the port.

### `DeviceConnected`

Indicates that a device was successfully connected to the port.

### `DeviceFailedEnumeration`

Indicates that an attempt was made to connect a device to the port, but the enumeration of the device failed.

### `DeviceGeneralFailure`

Indicates that an attempt was made to connect a device to the port, but the connection failed for unspecified reasons.

### `DeviceCausedOvercurrent`

Indicates that an attempt was made to connect a device to the port, but the attempt failed because of an overcurrent condition.

### `DeviceNotEnoughPower`

Indicates that an attempt was made to connect a device to the port, but there was not enough power to drive the device, and the connection failed.

### `DeviceNotEnoughBandwidth`

Indicates that an attempt was made to connect a device to the port, but there was not enough bandwidth available for the device to function properly, and the connection failed.

### `DeviceHubNestedTooDeeply`

Indicates that an attempt was made to connect a device to the port, but the nesting of USB hubs was too deep, so the connection failed.

### `DeviceInLegacyHub`

Indicates that an attempt was made to connect a device to the port of an unsupported legacy hub, and the connection failed.

### `DeviceEnumerating`

Indicates that a device connected to the port is currently being enumerated.

**Note** This constant is supported in Windows Vista and later operating systems.

### `DeviceReset`

Indicates that device connected to the port is currently being reset.

**Note** This constant is supported in Windows Vista and later operating systems.

## Remarks

The USB bus driver reports connection status in a [USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex) structure in response to an [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex) request.

## See also

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex)

[USB Constants and Enumerations](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#enumerations)

[USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex)
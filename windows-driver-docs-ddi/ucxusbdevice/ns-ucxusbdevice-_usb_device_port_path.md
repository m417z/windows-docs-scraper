# _USB_DEVICE_PORT_PATH structure

## Description

Contains the port path of a USB device.

## Members

### `Size`

The size in bytes of this structure.

### `PortPathDepth`

The depth of path in the USB topology tree, consisting of host controller, hubs, and devices.

### `TTHubDepth`

The depth of path in the USB topology tree from a TT hub.

### `PortPath`

The index of connected USB port on the hub.

## See also

[UCXUSBDEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucxusbdevice_info)
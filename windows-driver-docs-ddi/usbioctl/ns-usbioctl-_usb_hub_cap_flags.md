# _USB_HUB_CAP_FLAGS structure

## Description

The **USB_HUB_CAP_FLAGS** structure is used to report the capabilities of a hub.

## Members

### `ul`

A bitmask that represents the hub capabilities.

### `HubIsHighSpeedCapable`

If **TRUE**, the hub is high speed-capable. This capability does not necessarily mean that the hub is operating at high speed

### `HubIsHighSpeed`

If **TRUE**, the hub is high speed.

### `HubIsMultiTtCapable`

If **TRUE**, the hub is capable of doing multiple transaction translations simultaneously.

### `HubIsMultiTt`

If **TRUE**, the hub is configured to perform multiple transaction translations simultaneously.

### `HubIsRoot`

If **TRUE**, the hub is the root hub.

### `HubIsArmedWakeOnConnect`

If **TRUE**, the hub is armed to wake when a device is connected to the hub.

### `HubIsBusPowered`

A boolean value that indicates whether the hub is bus-powered. **TRUE**, the hub is bus-powered; **FALSE**, the hub is self-powered.

### `ReservedMBZ`

Reserved. Do not use.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_HUB_CAPABILITIES_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_capabilities_ex)
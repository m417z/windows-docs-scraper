# _CONTROLLER_USB_20_HARDWARE_LPM_FLAGS structure

## Description

Describes supported protocol capabilities for Link Power Management (LPM) in as defined the USB 2.0 specification.

## Members

### `AsUchar`

The size of structure represented as a char (8-bit) value.

### `Flags`

### `Flags.L1CapabilitySupported`

### `Flags.BeslLpmCapabilitySupported`

### `L1CapabilitySupported`

Indicates support for L1 transitions.

### `BeslLpmCapabilitySupported`

Indicates Best Effort Service latency (BESL) latency support.

## See also

[ROOTHUB_20PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_20port_info)
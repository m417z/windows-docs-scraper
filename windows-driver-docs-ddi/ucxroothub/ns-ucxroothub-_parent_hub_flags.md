# _PARENT_HUB_FLAGS structure

## Description

This structure is used by the [HUB_INFO_FROM_PARENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_hub_info_from_parent) structure to get hub information from the parent.

## Members

### `AsUlong32`

The size of structure represented as a LONG (32-bit) value.

### `Flags`

### `Flags.DisableLpmForAllDownstreamDevices`

Indicates that LPM should be disabled for all devices/hubs behind this hub.

### `Flags.HubIsHighSpeedCapable`

Indicates that the hub is high-speed capable.

### `Flags.DisableUpdateMaxExitLatency`

Indicates that UpdateMaxExitLatency should be disabled.

### `Flags.DisableU1`

Indicates that U1 transitions should be disabled.

### `DisableLpmForAllDownstreamDevices`

Indicates that LPM should be disabled for all devices/hubs behind this hub.

### `HubIsHighSpeedCapable`

Indicates that the hub is high-speed capable.

### `DisableUpdateMaxExitLatency`

Indicates that UpdateMaxExitLatency should be disabled.

### `DisableU1`

Indicates that U1 transitions should be disabled.

## See also

- [HUB_INFO_FROM_PARENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_hub_info_from_parent)
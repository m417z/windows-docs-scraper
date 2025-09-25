# _BTHX_SCO_SUPPORT enumeration

## Description

The BTHX_SCO_SUPPORT enumeration lists the different types of SCO supported by the transport driver.

## Constants

### `ScoSupportNone`

SCO is not supported.

### `ScoSupportHCI`

SCO data passes through the HCI layer (stack).

### `ScoSupportHCIBypass`

SCO data does not pass through the HCI layer but through a sideband mechanism like an I2S channel.

## Remarks

Upon starting, the Bluetooth stack will query the transport driver for its capabilities by sending the [IOCTL_BTHX_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_query_capabilities) IOCTL.

The output buffer of this IOCTL is defined by the [BTHX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ns-bthxddi-_bthx_capabilities) structure which contains the
BTHX_SCO_SUPPORT structure.

The transport driver must specify **ScoSupportHCIBypass**.
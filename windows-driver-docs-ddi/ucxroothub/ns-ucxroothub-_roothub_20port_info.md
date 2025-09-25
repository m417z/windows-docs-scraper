# _ROOTHUB_20PORT_INFO structure

## Description

Provides information about a USB 2.0 root hub port. This structure is passed by UCX in the [EVT_UCX_ROOTHUB_GET_20PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_20port_info) callback function.

## Members

### `PortNumber`

The USB 2.0 root hub port number.

### `MinorRevision`

Minor revision number.

### `HubDepth`

The hub depth limit.

### `Removable`

A [TRISTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ne-ucxroothub-_tristate) value that indicates if the port is removable.

### `IntegratedHubImplemented`

A [TRISTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ne-ucxroothub-_tristate) value that indicates if the port is implemented.

### `DebugCapable`

A [TRISTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ne-ucxroothub-_tristate) value that indicates if the port is debug capable.

### `ControllerUsb20HardwareLpmFlags`

A value that indicates Link Power Management (LPM) flags for the controller.
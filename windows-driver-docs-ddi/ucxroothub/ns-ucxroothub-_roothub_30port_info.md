# _ROOTHUB_30PORT_INFO structure

## Description

Provides information about a USB 3.0 root hub port. This structure is passed by UCX in the [EVT_UCX_ROOTHUB_GET_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_30port_info) callback function.

## Members

### `PortNumber`

The USB 3.0 port number connected to the root hub.

### `MinorRevision`

Revision number.

### `HubDepth`

The hub depth limit.

### `Removable`

A [TRISTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ne-ucxroothub-_tristate) value that indicates if the port is removable.

### `DebugCapable`

A [TRISTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ne-ucxroothub-_tristate) value that indicates if the port is debug capable.
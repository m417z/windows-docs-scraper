# _ROOTHUB_30PORTS_INFO structure

## Description

Provides information about USB 3.0 root hub ports. This structure is passed by UCX in the [EVT_UCX_ROOTHUB_GET_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_30port_info) callback function.

## Members

### `Size`

The size in bytes of this structure.

### `NumberOfPorts`

Number of USB 3.0 root hub ports.

### `PortInfoSize`

The size of the [ROOTHUB_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_30port_info) array.

### `PortInfoArray`

A pointer to an array of [ROOTHUB_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_30port_info) structures.

## See also

[EVT_UCX_ROOTHUB_GET_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_30port_info)
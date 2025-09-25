# _ROOTHUB_20PORTS_INFO structure

## Description

This structure that has an array of 2.0 ports supported by the root hub. This structure is provided by UCX in a framework request in the [EVT_UCX_ROOTHUB_GET_20PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_20port_info) callback function.

## Members

### `Size`

The size in bytes of this structure.

### `NumberOfPorts`

The number of USB 2.0 ports connected to the root hub.

### `PortInfoSize`

The size of the **ROOTHUB_20PORTS_INFO** structure.

### `PortInfoArray`

A pointer to an array of [PROOTHUB_20PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_20port_info) structures.

## See also

[EVT_UCX_ROOTHUB_GET_20PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_20port_info)
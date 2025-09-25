# _ROOTHUB_INFO structure

## Description

Provides information about a USB root hub. This structure is passed by UCX in the [EVT_UCX_ROOTHUB_GET_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_info) callback function.

## Members

### `Size`

The size in bytes of this structure.

### `ControllerType`

A [CONTROLLER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ne-ucxroothub-_controller_type) value that identifies the type of eXtensible Host Controller Interface (xHCI) which has the root hub.

### `NumberOf20Ports`

The number of USB 2.0 ports connected to the root hub.

### `NumberOf30Ports`

The number of USB 3.0 ports connected to the root hub.

### `MaxU1ExitLatency`

The exit latency for the slowest link for U1 transition.

### `MaxU2ExitLatency`

The exit latency for the slowest link for U2 transition.

## See also

[EVT_UCX_ROOTHUB_GET_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_info)
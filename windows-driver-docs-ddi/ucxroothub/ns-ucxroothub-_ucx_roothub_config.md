# _UCX_ROOTHUB_CONFIG structure

## Description

Contains pointers to event callback functions for creating the root hub by calling [UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85)). Initialize this structure by calling **UCX_ROOTHUB_CONFIG_INIT** initialization function (see Ucxclass.h).

## Members

### `Size`

The size in bytes of this structure.

### `NumberOfPresentedControlUrbCallbacks`

The number of control requests sent to the default endpoint.

### `EvtRootHubClearHubFeature`

A pointer to the [EVT_UCX_ROOTHUB_CONTROL_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) callback function.

### `EvtRootHubClearPortFeature`

A pointer to the [EVT_UCX_ROOTHUB_CONTROL_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) callback function.

### `EvtRootHubGetHubStatus`

A pointer to the [EVT_UCX_ROOTHUB_CONTROL_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) callback function.

### `EvtRootHubGetPortStatus`

A pointer to the [EVT_UCX_ROOTHUB_CONTROL_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) callback function.

### `EvtRootHubSetHubFeature`

A pointer to the [EVT_UCX_ROOTHUB_CONTROL_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) callback function.

### `EvtRootHubSetPortFeature`

A pointer to the [EVT_UCX_ROOTHUB_CONTROL_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) callback function.

### `EvtRootHubGetPortErrorCount`

A pointer to the [EVT_UCX_ROOTHUB_CONTROL_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) callback function.

### `EvtRootHubControlUrb`

A pointer to the [EVT_UCX_ROOTHUB_CONTROL_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) callback function.

### `EvtRootHubInterruptTx`

A pointer to the [EVT_UCX_ROOTHUB_INTERRUPT_TX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_interrupt_tx) callback function.

### `EvtRootHubGetInfo`

A pointer to the [EVT_UCX_ROOTHUB_GET_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_info) callback function.

### `EvtRootHubGet20PortInfo`

A pointer to the [EVT_UCX_ROOTHUB_GET_20PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_20port_info) callback function.

### `EvtRootHubGet30PortInfo`

A pointer to the [EVT_UCX_ROOTHUB_GET_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_30port_info) callback function.

### `WdfRequestAttributes`

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies initialization parameters.
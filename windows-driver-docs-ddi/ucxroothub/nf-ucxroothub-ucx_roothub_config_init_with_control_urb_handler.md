## Description

Initializes a [**UCX\_ROOTHUB\_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_ucx_roothub_config) with pointers to event callback functions implemented by the client driver.

## Parameters

### `Config` [out]

A pointer to a [**UCX\_ROOTHUB\_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_ucx_roothub_config) structure to initialize.

### `EvtRootHubControlUrb` [in]

A pointer to client driver's implementation of the [*EVT\_UCX\_ROOTHUB\_CONTROL\_URB*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_control_urb) event callback.

### `EvtRootHubInterruptTx` [in]

A pointer to client driver's implementation of the [*EVT\_UCX\_ROOTHUB\_INTERRUPT\_TX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_interrupt_tx) event callback.

### `EvtRootHubGetInfo` [in]

A pointer to client driver's implementation of the [*EVT\_UCX\_ROOTHUB\_GET\_INFO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_info) event callback.

### `EvtRootHubGet20PortInfo` [in]

A pointer to client driver's implementation of the [*EVT\_UCX\_ROOTHUB\_GET\_20PORT\_INFO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_20port_info) event callback.

### `EvtRootHubGet30PortInfo` [in]

A pointer to client driver's implementation of the [*EVT\_UCX\_ROOTHUB\_GET\_30PORT\_INFO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nc-ucxroothub-evt_ucx_roothub_get_30port_info) event callback.

## Remarks

This function does not return a value.

## See also

[**UcxRootHubCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/nf-ucxroothub-ucxroothubcreate)
# UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS_INIT function

## Description

Initializes a [UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_ucx_default_endpoint_event_callbacks) structure with client driver's callback functions. The client driver calls this function before calling [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method to create an endpoint and register its callback functions with UCX.

## Parameters

### `Callbacks` [out]

A pointer to a [UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_ucx_default_endpoint_event_callbacks) structure that contains pointers to the client driver's event callback functions.

### `EvtEndpointPurge` [in]

A pointer to client driver's implementation of the [EVT_UCX_ENDPOINT_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_purge) event callback function.

### `EvtEndpointStart` [in]

A pointer to client driver's implementation of the [EVT_UCX_ENDPOINT_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_start) event callback function.

### `EvtEndpointAbort` [in]

A pointer to client driver's implementation of the [EVT_UCX_ENDPOINT_ABORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_abort) event callback function.

### `EvtEndpointOkToCancelTransfers` [in]

A pointer to client driver's implementation of the [EVT_UCX_ENDPOINT_OK_TO_CANCEL_TRANSFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_ok_to_cancel_transfers) event callback function.

### `EvtDefaultEndpointUpdate` [in]

A pointer to client driver's implementation of the [EVT_UCX_DEFAULT_ENDPOINT_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_default_endpoint_update) event callback function.

## See also

[UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
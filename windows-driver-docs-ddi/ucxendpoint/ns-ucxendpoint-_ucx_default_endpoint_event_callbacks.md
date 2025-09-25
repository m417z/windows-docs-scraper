# _UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS structure

## Description

This structure provides a list of UCX default endpoint event callback functions.

## Members

### `Size`

The size in bytes of this structure.

### `EvtEndpointPurge`

A pointer to a EVT_UCX_ENDPOINT_PURGE callback function.

### `EvtEndpointStart`

A pointer to a EVT_UCX_ENDPOINT_START callback function.

### `EvtEndpointAbort`

A pointer to a EVT_UCX_ENDPOINT_ABORT callback function.

### `EvtEndpointOkToCancelTransfers`

A pointer to a EVT_UCX_ENDPOINT_OK_TO_CANCEL_TRANSFERS callback function.

### `EvtDefaultEndpointUpdate`

A pointer to a EVT_UCX_DEFAULT_ENDPOINT_UPDATE callback function.

### `Reserved1`

Do not use.

## See also

[UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucx_default_endpoint_event_callbacks_init)

[UcxDefaultEndpointInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxdefaultendpointinitseteventcallbacks)
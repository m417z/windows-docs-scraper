# _UCX_ENDPOINT_EVENT_CALLBACKS structure

## Description

This structure provides a list of pointers to UCX endpoint event callback functions.

## Members

### `Size`

The size in bytes of the structure.

### `EvtEndpointPurge`

A pointer to an [EVT_UCX_ENDPOINT_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_purge) callback function.

### `EvtEndpointStart`

A pointer to an [EVT_UCX_ENDPOINT_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_start) callback function.

### `EvtEndpointAbort`

A pointer to an [EVT_UCX_ENDPOINT_ABORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_abort) callback function.

### `EvtEndpointReset`

A pointer to an [EVT_UCX_ENDPOINT_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_reset) callback function.

### `EvtEndpointOkToCancelTransfers`

A pointer to an [EVT_UCX_ENDPOINT_OK_TO_CANCEL_TRANSFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_ok_to_cancel_transfers) callback function.

### `EvtEndpointStaticStreamsAdd`

A pointer to an [EVT_UCX_ENDPOINT_STATIC_STREAMS_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_static_streams_add) callback function.

### `EvtEndpointStaticStreamsEnable`

A pointer to an [EVT_UCX_ENDPOINT_STATIC_STREAMS_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_static_streams_enable) callback function.

### `EvtEndpointStaticStreamsDisable`

A pointer to an [EVT_UCX_ENDPOINT_STATIC_STREAMS_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_static_streams_disable) callback function.

### `Reserved1`

Do not use.

### `EvtEndpointGetIsochTransferPathDelays`

A pointer to an [EVT_UCX_ENDPOINT_GET_ISOCH_TRANSFER_PATH_DELAYS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_get_isoch_transfer_path_delays) callback function.

### `EvtEndpointSetCharacteristic`

A pointer to an [EVT_UCX_ENDPOINT_SET_CHARACTERISTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_set_characteristic) callback function.

## See also

[UCX_ENDPOINT_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucx_endpoint_event_callbacks_init)

[UcxEndpointInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointinitseteventcallbacks)
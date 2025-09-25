# UfxEndpointInitSetEventCallbacks function

## Description

Initialize a **UFXENDPOINT_INIT** structure.

## Parameters

### `EndpointInit` [in, out]

Opaque structure passed by UFX in the call to [EVT_UFX_DEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_endpoint_add) or [EVT_UFX_DEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_default_endpoint_add).

### `Callbacks` [in]

Pointer to a [UFX_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_endpoint_callbacks) structure.

## Remarks

The client driver calls [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate) from its [EVT_UFX_DEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_endpoint_add) or [EVT_UFX_DEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_default_endpoint_add) event callback function in order to create a new endpoint.

 The client driver first calls [UFX_ENDPOINT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufx_endpoint_callbacks_init) to initialize a [UFX_ENDPOINT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_endpoint_callbacks) structure. Then it calls [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate) with the initialized **UFX_ENDPOINT_CALLBACKS** structure.

For an code example that shows how to create a UFXENDPOINT object and initialize its context, see the Remarks section of [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).
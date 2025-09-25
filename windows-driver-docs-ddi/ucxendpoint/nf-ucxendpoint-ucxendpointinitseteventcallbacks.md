# UcxEndpointInitSetEventCallbacks function

## Description

Initializes a **UCXENDPOINT_INIT** structure with client driver's event callback functions related to endpoints on the device.

## Parameters

### `EndpointInit`

A pointer to a **UCXENDPOINT_INIT** structure that UCX passes when it invokes the client driver's [EVT_UCX_USBDEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoint_add) event callback function.

### `EventCallbacks`

A pointer to a [UCX_ENDPOINT_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_ucx_endpoint_event_callbacks) structure that contains function pointer to event callback functions related to the endpoint. The client driver initializes the structure by calling [UCX_ENDPOINT_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucx_endpoint_event_callbacks_init).

## Remarks

The client driver calls this method to set function pointers to its event callback functions just before calling [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) to create an endpoint.

## See also

[UCX_ENDPOINT_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_ucx_endpoint_event_callbacks)

[UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
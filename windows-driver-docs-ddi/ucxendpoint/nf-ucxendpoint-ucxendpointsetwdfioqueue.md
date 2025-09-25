# UcxEndpointSetWdfIoQueue function

## Description

Sets a framework queue on the specified endpoint object.

## Parameters

### `Endpoint` [in]

A handle to the endpoint object. The client driver retrieved the handle in a previous call to [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate).

### `WdfQueue` [in]

A handle to the framework queue object to set on the endpoint.

## Remarks

This routine can only get called from [EVT_UCX_USBDEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoint_add) and [EVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_default_endpoint_add)
callback functions.
The client driver must call this routine only once for each endpoint.

For a code example, see [EVT_UCX_USBDEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoint_add).

## See also

[UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
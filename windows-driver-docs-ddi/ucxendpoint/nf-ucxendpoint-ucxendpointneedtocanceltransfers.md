# UcxEndpointNeedToCancelTransfers function

## Description

The client driver calls this method before it cancels transfers on the wire.

## Parameters

### `Endpoint` [in]

A handle to the endpoint object. The client driver retrieved the handle in a previous call to [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate).

## Remarks

If needed, UCX coordinates with the hub driver to send a Clear TT buffer command to the TT Hub.

After that operation completes, UCX invokes the client driver's EVT_UCX_ENDPOINT_OK_TO_CANCEL_TRANSFERS callback function.

## See also

[UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
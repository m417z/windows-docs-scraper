# UfxEndpointGetCommandQueue function

## Description

Returns the command queue previously created by [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).

## Parameters

### `UfxEndpoint` [in]

A handle to an endpoint object returned from a previous call to [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).

## Return value

A handle to a framework queue object.

## Remarks

For a code example that shows how to create an endpoint object and initialize its context, see the Remarks section of [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).

## See also

[UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate)
# UcxEndpointGetStaticStreamsReferenced function

## Description

Returns a referenced static streams object for the specified endpoint.

## Parameters

### `Endpoint` [in]

A handle to the endpoint object for which the static streams object is requested. The client driver retrieved the handle in a previous call to [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate).

### `Tag` [in]

A driver-defined value that the framework stores as an identification tag for the object reference.

## Return value

A handle to the stream object if it is opened with the endpoint. Otherwise, NULL.

## Remarks

The client driver can use this function to determine whether it has created a streams object for this endpoint. If it create the object the method returns the UCXSSTREAMS handle. The method returns NULL if the object was not created, or if the client driver failed the framework request object passed in the [EVT_UCX_ENDPOINT_STATIC_STREAMS_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_static_streams_enable) callback. Any call to this method must be matched by a call to [WdfObjectDereferenceWithTag](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereferencewithtag) by using the same Tag.

## See also

[UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
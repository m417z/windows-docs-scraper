# UcxStaticStreamsSetStreamInfo function

## Description

Sets stream information for each stream enabled by the client driver.

## Parameters

### `StaticStreams` [in]

 The handle to the Static Streams object just been created.

### `StreamInfo` [in]

 A pointer to a [STREAM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxsstreams/ns-ucxsstreams-_stream_info) structure that contains static stream-related information.

## Remarks

The client driver must call this method from its implementation of the [EVT_UCX_ENDPOINT_STATIC_STREAMS_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_static_streams_add) event callback .
This method must be called for the number of streams on the endpoint.

For a code example, see [EVT_UCX_ENDPOINT_STATIC_STREAMS_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_static_streams_add).

## See also

[UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
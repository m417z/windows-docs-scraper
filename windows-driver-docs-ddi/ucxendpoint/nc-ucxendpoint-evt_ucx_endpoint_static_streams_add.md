# EVT_UCX_ENDPOINT_STATIC_STREAMS_ADD callback function

## Description

The client driver's implementation that UCX calls to create static streams.

## Parameters

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object that represents the endpoint.

### `NumberOfStreams` [in]

The number of non-default streams to create.

### `UcxStaticStreamsInit` [in]

A pointer to an opaque structure containing initialization information. This structure is managed by UCX.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method.

This callback function creates a UCX static streams object by calling the [UcxStaticStreamsCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxsstreams/nf-ucxsstreams-ucxstaticstreamscreate) method. Only one UCX static streams object can be associated with a single endpoint. The driver then calls [UcxStaticStreamsSetStreamInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxsstreams/nf-ucxsstreams-ucxstaticstreamssetstreaminfo) once per stream to create a queue for each stream.

A static streams object is not enabled until UCX calls the client driver's [EVT_UCX_ENDPOINT_STATIC_STREAMS_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_static_streams_enable) callback function.

### Examples

```cpp
NTSTATUS
Endpoint_EvtEndpointStaticStreamsAdd(
    UCXENDPOINT         UcxEndpoint,
    ULONG               NumberOfStreams,
    PUCXSSTREAMS_INIT   UcxStaticStreamsInit
    )
{
    NTSTATUS                    status;
    WDF_OBJECT_ATTRIBUTES       wdfAttributes;
    UCXSSTREAMS                 ucxStaticStreams;
    STREAM_INFO                 streamInfo;
    ULONG                       streamId;

    TRY {

        WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&wdfAttributes, STATIC_STREAMS_CONTEXT);

        status = UcxStaticStreamsCreate(UcxEndpoint,
                                        &UcxStaticStreamsInit,
                                        &wdfAttributes,
                                        &ucxStaticStreams);
        // … error handling …

        for (i = 0, streamId = 1; i < NumberOfStreams; i += 1, streamId += 1) {

            // … create WDF queue …

            STREAM_INFO_INIT(&streamInfo,
                             wdfQueue,
                             streamId);

            UcxStaticStreamsSetStreamInfo(ucxStaticStreams, &streamInfo);
        }

```
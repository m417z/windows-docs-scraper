# EVT_UCX_ENDPOINT_STATIC_STREAMS_ENABLE callback function

## Description

The client driver's implementation that UCX calls to enable the static streams.

## Parameters

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object that represents the endpoint.

### `UcxStaticStreams` [in]

A handle to a UCX object that represents the static streams.

### `Request` [in]

Contains the URB for the **URB_FUNCTION_OPEN_STATIC_STREAMS**.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method.

The client driver returns completion status in *Request* and in the USBD_STATUS in the URB header. The driver can complete the WDFREQUEST asynchronously.

### Examples

```cpp
VOID
Endpoint_EvtUcxEndpointStaticStreamsEnable(
    UCXENDPOINT     UcxEndpoint,
    UCXSSTREAMS     UcxStaticStreams,
    WDFREQUEST      Request
)

{
    UNREFERENCED_PARAMETER(UcxEndpoint);
    UNREFERENCED_PARAMETER(UcxStaticStreams);

    DbgTrace(TL_INFO, Endpoint, "Endpoint_EvtUcxEndpointStaticStreamsEnable");

    WdfRequestComplete(Request, STATUS_SUCCESS);
}
```
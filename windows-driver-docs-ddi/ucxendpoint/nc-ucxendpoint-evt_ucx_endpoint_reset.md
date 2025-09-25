# EVT_UCX_ENDPOINT_RESET callback function

## Description

The client driver's implementation that UCX calls to reset the controller's programming for an endpoint.

## Parameters

### `UcxController` [in]

A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate) method.

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object that represents the endpoint.

### `Request` [in]

A handle to a framework request object that the client driver completes when the reset operation is finished.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method.

The client driver returns completion status in the WDFREQUEST, which it might complete asynchronously.

### Examples

```cpp
VOID
Endpoint_EvtUcxEndpointReset(
    UCXCONTROLLER   UcxController,
    UCXENDPOINT     UcxEndpoint,
    WDFREQUEST      Request
)

{
    UNREFERENCED_PARAMETER(UcxController);
    UNREFERENCED_PARAMETER(UcxEndpoint);

    DbgTrace(TL_INFO, Endpoint, "Endpoint_EvtUcxEndpointReset");

    WdfRequestComplete(Request, STATUS_SUCCESS);
}
```
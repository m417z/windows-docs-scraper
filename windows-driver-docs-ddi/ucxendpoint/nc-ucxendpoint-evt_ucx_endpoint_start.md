# EVT_UCX_ENDPOINT_START callback function

## Description

The client driver's implementation that UCX calls to start the queue associated with the endpoint.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate) method.

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object that represents the endpoint.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method.

### Examples

```cpp
VOID
Endpoint_EvtUcxEndpointStart(
    UCXCONTROLLER   UcxController,
    UCXENDPOINT     UcxEndpoint
)

{
    UNREFERENCED_PARAMETER(UcxController);
    UNREFERENCED_PARAMETER(UcxEndpoint);

    DbgTrace(TL_INFO, Endpoint, "Endpoint_EvtUcxEndpointStart");
}
```
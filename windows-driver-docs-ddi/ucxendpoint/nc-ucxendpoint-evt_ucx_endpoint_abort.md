# EVT_UCX_ENDPOINT_ABORT callback function

## Description

The client driver's implementation that UCX calls to abort the queue associated with the endpoint.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate) method.

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object.

## Remarks

The client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
method.

This function completes all requests associated with the endpoint, typically by calling [WdfIoQueueStopAndPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestopandpurge).

### Examples

```cpp
VOID
Endpoint_UcxEvtEndpointAbort(
    UCXCONTROLLER   UcxController,
     UCXENDPOINT     UcxEndpoint
    )
  {
              WdfIoQueueStopAndPurge(endpointContext->WdfQueue,
                                     Endpoint_WdfEvtAbortComplete,
                                     UcxEndpoint);
  }

```
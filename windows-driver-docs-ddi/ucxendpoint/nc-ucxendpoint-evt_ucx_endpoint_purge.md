# EVT_UCX_ENDPOINT_PURGE callback function

## Description

The client driver's implementation that completes all outstanding I/O requests on the endpoint.

## Parameters

### `UcxController` [in]

A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate) method.

### `UcxEndpoint` [in]

A handle to a UCXENDPOINT object that represents the endpoint.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) method.

Typically, this function calls [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge).

After UCX calls this function, the client driver fails subsequent I/O requests until UCX calls the client driver's [EVT_UCX_ENDPOINT_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nc-ucxendpoint-evt_ucx_endpoint_start) callback function.

### Examples

```cpp
VOID
Endpoint_UcxEvtEndpointPurge(
    UCXCONTROLLER   UcxController,
    UCXENDPOINT     UcxEndpoint
    )
{
            WdfIoQueuePurge(endpointContext->WdfQueue,
                            Endpoint_WdfEvtPurgeComplete,
                            UcxEndpoint);
}
```

## See also

- [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge)
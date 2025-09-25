# EVT_UCX_DEFAULT_ENDPOINT_UPDATE callback function

## Description

The client driver's implementation that UCX calls with information about the default endpoint.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `Request` [in]

A [DEFAULT_ENDPOINT_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_default_endpoint_update) structure that contains the handle to the default endpoint to be updated.

## Remarks

The UCX client driver registers its *EVT_UCX_DEFAULT_ENDPOINT_UPDATE* implementation with the USB host controller extension (UCX) by calling the [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
method.

UCX typically calls this routine to update the default endpoint's maximum packet size. The client driver returns completion status in the WDFREQUEST, which it can complete
asynchronously.

#### Examples

```
VOID
Endpoint_EvtUcxDefaultEndpointUpdate(
    UCXCONTROLLER   UcxController,
    WDFREQUEST      Request
)

{
    UNREFERENCED_PARAMETER(UcxController);

    DbgTrace(TL_INFO, Endpoint, "Endpoint_EvtUcxDefaultEndpointUpdate");

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(WdfRequest, &wdfRequestParams);

    defaultEndpointUpdate = (PDEFAULT_ENDPOINT_UPDATE)wdfRequestParams.Parameters.Others.Arg1;
    ...

    WdfRequestComplete(Request, STATUS_SUCCESS);
}
```

## See also

[UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucx_default_endpoint_event_callbacks_init)

[UcxDefaultEndpointInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxdefaultendpointinitseteventcallbacks)
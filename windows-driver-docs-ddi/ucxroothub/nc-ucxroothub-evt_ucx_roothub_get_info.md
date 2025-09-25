# EVT_UCX_ROOTHUB_GET_INFO callback function

## Description

The client driver's implementation that UCX calls when it receives a request for information about the root hub.

## Parameters

### `UcxRootHub` [in]

A handle to a UCX object that represents the root hub.

### `Request` [in]

A structure of type [ROOTHUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_info).

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85))
method.

The [_ROOTHUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_info) structure contains the number of USB 2.0 and USB 3.0 ports supported by the root hub.

After UCX calls the *EVT_UCX_ROOTHUB_GET_INFO* function, the number of ports exposed by the root hub is guaranteed to remain the same. Note that these are virtual ports, not physical ports. Each physical USB connector is represented by one or more
ports of different speed on the root hub.

The client driver returns completion status in *Request*. The driver can complete the WDFREQUEST asynchronously.

#### Examples

```
VOID
RootHub_EvtRootHubGetInfo(
    UCXROOTHUB         UcxRootHub,
    WDFREQUEST         Request
)
/*++

    For sample demonstration purposes, this function returns statically
    defined information for the root hub.

--*/
{
    PUCX_ROOTHUB_CONTEXT    ucxRootHubContext;
    WDF_REQUEST_PARAMETERS  wdfRequestParams;
    PROOTHUB_INFO           rootHubInfo;
    NTSTATUS                status;

    ucxRootHubContext = GetUcxRootHubContext(UcxRootHub);

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(Request, &wdfRequestParams);

    rootHubInfo = (PROOTHUB_INFO)wdfRequestParams.Parameters.Others.Arg1;

    if (rootHubInfo->Size < sizeof(ROOTHUB_INFO)) {
        DbgTrace(TL_ERROR, RootHub, "Invalid ROOTHUB_INFO Size %d", rootHubInfo->Size);
        status = STATUS_INVALID_PARAMETER;
        goto RootHub_EvtRootHubGetInfo;
    }

    rootHubInfo->ControllerType = ControllerTypeSoftXhci;
    rootHubInfo->NumberOf20Ports = ucxRootHubContext->NumberOf20Ports;
    rootHubInfo->NumberOf30Ports = ucxRootHubContext->NumberOf30Ports;
    rootHubInfo->MaxU1ExitLatency = ucxRootHubContext->U1DeviceExitLatency;
    rootHubInfo->MaxU2ExitLatency = ucxRootHubContext->U2DeviceExitLatency;

    DbgTrace(TL_INFO, RootHub, "RootHub_UcxEvtGetInfo NumberOf20Ports %d NumberOf30Ports %d", rootHubInfo->NumberOf20Ports, rootHubInfo->NumberOf30Ports);

    status = STATUS_SUCCESS;

RootHub_EvtRootHubGetInfo:

    WdfRequestComplete(Request, status);
}
```

## See also

[_ROOTHUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_info)
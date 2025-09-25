# EVT_UCX_ROOTHUB_GET_20PORT_INFO callback function

## Description

The client driver's implementation that UCX calls when it receives a request for information about USB 2.0 ports on the root hub.

## Parameters

### `UcxRootHub` [in]

A handle to a UCX object that represents the root hub.

### `Request` [in]

A structure of type [_ROOTHUB_20PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_20port_info).

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85))
method.

 The **PortInfoArray** array of the [_ROOTHUB_20PORTS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_20ports_info) structure
contains a list of USB 2.0 ports that the root hub supports.

The client driver returns completion status in *Request* and in the USBD_STATUS
in the URB header. The driver can complete the WDFREQUEST asynchronously.

#### Examples

```
VOID
RootHub_EvtRootHubGet20PortInfo(
    UCXROOTHUB         UcxRootHub,
    WDFREQUEST         Request
)
/*++

    For sample demonstration purposes, this function returns statically
    defined information for the single 2.0 port.

--*/
{
    PUCX_ROOTHUB_CONTEXT    ucxRootHubContext;
    WDF_REQUEST_PARAMETERS  wdfRequestParams;
    PROOTHUB_20PORTS_INFO   rootHub20PortsInfo;
    NTSTATUS                status;

    ucxRootHubContext = GetUcxRootHubContext(UcxRootHub);

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(Request, &wdfRequestParams);

    rootHub20PortsInfo = (PROOTHUB_20PORTS_INFO)wdfRequestParams.Parameters.Others.Arg1;

    if (rootHub20PortsInfo->Size < sizeof(ROOTHUB_20PORTS_INFO)) {
        DbgTrace(TL_ERROR, RootHub, "Invalid ROOTHUB_20PORTS_INFO Size %d", rootHub20PortsInfo->Size);
        status = STATUS_INVALID_PARAMETER;
        goto RootHub_EvtRootHubGet20PortInfoEnd;
    }

    if (rootHub20PortsInfo->NumberOfPorts != ucxRootHubContext->NumberOf20Ports) {
        DbgTrace(TL_ERROR, RootHub, "Invalid ROOTHUB_20PORTS_INFO NumberOfPorts %d", rootHub20PortsInfo->NumberOfPorts);
        status = STATUS_INVALID_PARAMETER;
        goto RootHub_EvtRootHubGet20PortInfoEnd;
    }

    if (rootHub20PortsInfo->PortInfoSize < sizeof(ROOTHUB_20PORT_INFO)) {
        DbgTrace(TL_ERROR, RootHub, "Invalid ROOTHUB_20PORT_INFO Size %d", rootHub20PortsInfo->PortInfoSize);
        status = STATUS_INVALID_PARAMETER;
        goto RootHub_EvtRootHubGet20PortInfoEnd;
    }

    //
    // Return static root hub 2.0 port information.
    //
    rootHub20PortsInfo->PortInfoArray[0]->PortNumber = ROOTHUB_20_PORT_PORT_NUMBER;
    rootHub20PortsInfo->PortInfoArray[0]->Removable = TriStateTrue;

    status = STATUS_SUCCESS;

    DbgTrace(TL_INFO, RootHub, "RootHub_EvtRootHubGet20PortInfo");

RootHub_EvtRootHubGet20PortInfoEnd:

    WdfRequestComplete(Request, status);
}
```

## See also

[_ROOTHUB_20PORTS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_20ports_info)
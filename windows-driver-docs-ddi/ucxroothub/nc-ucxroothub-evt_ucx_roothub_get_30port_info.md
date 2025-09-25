# EVT_UCX_ROOTHUB_GET_30PORT_INFO callback function

## Description

The client driver's implementation that UCX calls when it receives a request for information about USB 3.0 ports on the root hub.

## Parameters

### `UcxRootHub` [in]

A handle to a UCX object that represents the root hub.

### `Request` [in]

A structure of type [_ROOTHUB_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_30port_info).

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85))
method.

 The **PortInfoArray** array of the [_ROOTHUB_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_30port_info) structure
contains a list of USB 3.0 ports that the root hub supports.

The client driver returns completion status in *Request* and in the USBD_STATUS
in the URB header. The driver can complete the WDFREQUEST asynchronously.

#### Examples

```
VOID
RootHub_EvtRootHubGet30PortInfo(
    UCXROOTHUB         UcxRootHub,
    WDFREQUEST         Request
)
/*++

    For sample demonstration purposes, this function returns statically
    defined information for the single 3.0 port.

--*/
{
    PUCX_ROOTHUB_CONTEXT    ucxRootHubContext;
    WDF_REQUEST_PARAMETERS  wdfRequestParams;
    PROOTHUB_30PORTS_INFO   rootHub30PortsInfo;
    NTSTATUS                status;

    ucxRootHubContext = GetUcxRootHubContext(UcxRootHub);

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(Request, &wdfRequestParams);

    rootHub30PortsInfo = (PROOTHUB_30PORTS_INFO)wdfRequestParams.Parameters.Others.Arg1;

    if (rootHub30PortsInfo->Size < sizeof(ROOTHUB_30PORTS_INFO)) {
        DbgTrace(TL_ERROR, RootHub, "Invalid ROOTHUB_30PORTS_INFO Size %d", rootHub30PortsInfo->Size);
        status = STATUS_INVALID_PARAMETER;
        goto RootHub_EvtRootHubGet30PortInfoEnd;
    }

    if (rootHub30PortsInfo->NumberOfPorts != ucxRootHubContext->NumberOf30Ports) {
        DbgTrace(TL_ERROR, RootHub, "Invalid ROOTHUB_30PORTS_INFO NumberOfPorts %d", rootHub30PortsInfo->NumberOfPorts);
        status = STATUS_INVALID_PARAMETER;
        goto RootHub_EvtRootHubGet30PortInfoEnd;
    }

    if (rootHub30PortsInfo->PortInfoSize < sizeof(ROOTHUB_30PORT_INFO)) {
        DbgTrace(TL_ERROR, RootHub, "Invalid ROOTHUB_30PORT_INFO Size %d", rootHub30PortsInfo->PortInfoSize);
        status = STATUS_INVALID_PARAMETER;
        goto RootHub_EvtRootHubGet30PortInfoEnd;
    }

    //
    // Return static root hub 3.0 port information.
    //
    rootHub30PortsInfo->PortInfoArray[0]->PortNumber = ROOTHUB_30_PORT_PORT_NUMBER;
    rootHub30PortsInfo->PortInfoArray[0]->Removable = TriStateTrue;

    status = STATUS_SUCCESS;

    DbgTrace(TL_INFO, RootHub, "RootHub_EvtRootHubGet30PortInfo");

RootHub_EvtRootHubGet30PortInfoEnd:

    WdfRequestComplete(Request, status);
}
```

## See also

[_ROOTHUB_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_30port_info)
# EVT_UCX_ROOTHUB_CONTROL_URB callback function

## Description

The client driver uses this callback type to implement handlers that UCX calls when it receives feature control requests on the USB hub.

## Parameters

### `UcxRootHub` [in]

A handle to a UCX object that represents the root hub.

### `Request` [in]

Contains the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) for the feature request.

## Remarks

The client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85))
method.

The driver either provides callbacks for all of the individual feature request types, as shown in the first example, or it can provide a single handler of type *EVT_UCX_ROOTHUB_CONTROL_URB* that UCX calls for all hub and port control transfers.

The client driver returns completion status in *Request* and in the USBD_STATUS
in the URB header. The driver can complete the WDFREQUEST asynchronously.

#### Examples

This example shows how to register callbacks for individual feature request types.

```
EVT_UCX_ROOTHUB_CONTROL_URB RootHub_EvtRootHubClearHubFeature;
EVT_UCX_ROOTHUB_CONTROL_URB RootHub_EvtRootHubClearPortFeature;
EVT_UCX_ROOTHUB_CONTROL_URB RootHub_EvtRootHubGetHubStatus;
EVT_UCX_ROOTHUB_CONTROL_URB RootHub_EvtRootHubGetPortStatus;
EVT_UCX_ROOTHUB_CONTROL_URB RootHub_EvtRootHubSetHubFeature;
EVT_UCX_ROOTHUB_CONTROL_URB RootHub_EvtRootHubSetPortFeature;
EVT_UCX_ROOTHUB_CONTROL_URB RootHub_EvtRootHubGetPortErrorCount;

...

    //
    // Create the root hub
    //
    UCX_ROOTHUB_CONFIG_INIT(&ucxRootHubConfig,
                            RootHub_EvtRootHubClearHubFeature,
                            RootHub_EvtRootHubClearPortFeature,
                            RootHub_EvtRootHubGetHubStatus,
                            RootHub_EvtRootHubGetPortStatus,
                            RootHub_EvtRootHubSetHubFeature,
                            RootHub_EvtRootHubSetPortFeature,
                            RootHub_EvtRootHubGetPortErrorCount,
                            RootHub_EvtRootHubInterruptTx,
                            RootHub_EvtRootHubGetInfo,
                            RootHub_EvtRootHubGet20PortInfo,
                            RootHub_EvtRootHubGet30PortInfo);

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&objectAttributes, UCX_ROOTHUB_CONTEXT);

    status = UcxRootHubCreate(ucxController,
                              &ucxRootHubConfig,
                              &objectAttributes,
                              &ucxRootHub);

```

Here is a sample implementation of one of the URB-specific request handlers.

```
VOID
RootHub_EvtRootHubClearHubFeature(
    UCXROOTHUB         UcxRootHub,
    WDFREQUEST         ControlUrb
)
/*++

Routine Description:

    UCX calls this routine when it receives a new Clear Hub Feature request.

--*/
{
    UNREFERENCED_PARAMETER(UcxRootHub);

    DbgTrace(TL_INFO, RootHub, "RootHub_EvtRootHubClearHubFeature");

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(WdfRequest, &wdfRequestParams);
    urb = (PURB)wdfRequestParams.Parameters.Others.Arg1;
    setupPacket = (PWDF_USB_CONTROL_SETUP_PACKET)&urb->UrbControlTransferEx.SetupPacket[0];
    ...

    WdfRequestComplete(ControlUrb, STATUS_SUCCESS);
}
```

## See also

[UcxRootHubCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188048(v=vs.85))
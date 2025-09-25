# EVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD callback function

## Description

The client driver's implementation that UCX calls to add a new default endpoint for a USB device.

## Parameters

### `UcxController` [in]

A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollercreate) method.

### `UcxUsbDevice` [in]

A handle to a UCX object that represents the USB device.

### `MaxPacketSize` [in]

Maximum packet size for transfers on this endpoint.

### `UcxEndpointInit` [in]

A pointer to an opaque structure containing initialization information. Callbacks for the endpoint object are associated with this structure. This structure is managed by UCX.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

The callback function calls [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) to create a new default endpoint object and register its default endpoint object callback functions.

Then, the callback function typically creates a WDF queue associated with the endpoint object. The queue does not receive any requests until the class extension starts it.

### Examples

```cpp
NTSTATUS
Endpoint_EvtUcxUsbDeviceDefaultEndpointAdd(
    UCXCONTROLLER           UcxController,
    UCXUSBDEVICE            UcxUsbDevice,
    ULONG                   MaxPacketSize,
    PUCXENDPOINT_INIT       EndpointInit
)

{
    NTSTATUS                                status = STATUS_SUCCESS;

    UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS    ucxDefaultEndpointEventCallbacks;
    WDF_OBJECT_ATTRIBUTES                   objectAttributes;

    PUCX_CONTROLLER_CONTEXT                 ucxControllerContext;

    UCXENDPOINT                             ucxEndpoint;
    PUCX_ENDPOINT_CONTEXT                   ucxEndpointContext;

    WDF_IO_QUEUE_CONFIG                     queueConfig;
    WDFQUEUE                                wdfQueue;

    UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS_INIT(&ucxDefaultEndpointEventCallbacks,
                                              Endpoint_EvtUcxEndpointPurge,
                                              Endpoint_EvtUcxEndpointStart,
                                              Endpoint_EvtUcxEndpointAbort,
                                              Endpoint_EvtUcxEndpointOkToCancelTransfers,
                                              Endpoint_EvtUcxDefaultEndpointUpdate);

    UcxDefaultEndpointInitSetEventCallbacks(EndpointInit, &ucxDefaultEndpointEventCallbacks);

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&objectAttributes, UCX_ENDPOINT_CONTEXT);

    ucxControllerContext = GetUcxControllerContext(UcxController);

    status = UcxEndpointCreate(UcxUsbDevice,
        &EndpointInit,
        &objectAttributes,
        &ucxEndpoint);

    if (!NT_SUCCESS(status)) {
        DbgTrace(TL_ERROR, Endpoint, "UcxEndpoint Failed %!STATUS!", status);
        goto EvtUsbDeviceDefaultEndpointAddEnd;
    }

    DbgTrace(TL_INFO, Endpoint, "UcxEndpoint created");

    ucxEndpointContext = GetUcxEndpointContext(ucxEndpoint);

    ucxEndpointContext->IsDefault = TRUE;
    ucxEndpointContext->MaxPacketSize = MaxPacketSize;

    WDF_IO_QUEUE_CONFIG_INIT(&queueConfig, WdfIoQueueDispatchManual);

    status = WdfIoQueueCreate(ucxControllerContext->WdfDevice,
        &queueConfig,
        WDF_NO_OBJECT_ATTRIBUTES,
        &wdfQueue);

    if (!NT_SUCCESS(status)) {
        DbgTrace(TL_ERROR, Endpoint, "WdfIoQueueCreate Failed %!STATUS!", status);
        goto EvtUsbDeviceDefaultEndpointAddEnd;
    }

    UcxEndpointSetWdfIoQueue(ucxEndpoint, wdfQueue);

EvtUsbDeviceDefaultEndpointAddEnd:

    return status;
}
```

## See also

- [UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucx_default_endpoint_event_callbacks_init)
- [UcxDefaultEndpointInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxdefaultendpointinitseteventcallbacks)
- [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)
- [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)
- [WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init)
- [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)
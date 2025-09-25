# EVT_UCX_USBDEVICE_ENDPOINT_ADD callback function

## Description

The client driver's implementation that UCX calls to add a new endpoint for a USB device.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `UcxUsbDevice` [in]

A handle to a UCX object that represents the USB device.

### `UsbEndpointDescriptor` [in]

A pointer to a location containing a USB descriptor for the endpoint being created.

### `UsbEndpointDescriptorBufferLength` [in]

Length in bytes of the descriptor.

### `SuperSpeedEndpointCompanionDescriptor` [in, optional]

An additional descriptor for a super speed port. This parameter is optional and may be **NULL**.

### `UcxEndpointInit` [in]

A pointer to an opaque structure containing initialization
information. Callbacks for the endpoint object are associated with this
structure. This structure is managed by UCX.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

The callback function calls [UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate) to create a new endpoint object and register endpoint object callback functions.

Then, the callback function typically creates a WDF queue associated with the endpoint
object. The queue does not receive any requests until the class extension
starts it.

#### Examples

```
NTSTATUS
Endpoint_EvtUcxUsbDeviceEndpointAdd(
    UCXCONTROLLER                                   UcxController,
    UCXUSBDEVICE                                    UcxUsbDevice,
    PUSB_ENDPOINT_DESCRIPTOR                        UsbEndpointDescriptor,
    ULONG                                           UsbEndpointDescriptorBufferLength,
    PUSB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR   SuperSpeedEndpointCompanionDescriptor,
    PUCXENDPOINT_INIT                               UcxEndpointInit
)

{
    NTSTATUS                        status = STATUS_SUCCESS;

    UCX_ENDPOINT_EVENT_CALLBACKS    ucxEndpointEventCallbacks;
    WDF_OBJECT_ATTRIBUTES           objectAttributes;

    PUCX_CONTROLLER_CONTEXT         ucxControllerContext;

    UCXENDPOINT                     ucxEndpoint;
    PUCX_ENDPOINT_CONTEXT           ucxEndpointContext;

    WDF_IO_QUEUE_CONFIG             queueConfig;

    UNREFERENCED_PARAMETER(UsbEndpointDescriptor);
    UNREFERENCED_PARAMETER(UsbEndpointDescriptorBufferLength);
    UNREFERENCED_PARAMETER(SuperSpeedEndpointCompanionDescriptor);

    UCX_ENDPOINT_EVENT_CALLBACKS_INIT(&ucxEndpointEventCallbacks,
                                      Endpoint_EvtUcxEndpointPurge,
                                      Endpoint_EvtUcxEndpointStart,
                                      Endpoint_EvtUcxEndpointAbort,
                                      Endpoint_EvtUcxEndpointReset,
                                      Endpoint_EvtUcxEndpointOkToCancelTransfers,
                                      Endpoint_EvtUcxEndpointStaticStreamsAdd,
                                      Endpoint_EvtUcxEndpointStaticStreamsEnable,
                                      Endpoint_EvtUcxEndpointStaticStreamsDisable,
                                      Endpoint_EvtUcxEndpointEnableForwardProgress);

    UcxEndpointInitSetEventCallbacks(UcxEndpointInit, &ucxEndpointEventCallbacks);

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&objectAttributes, UCX_ENDPOINT_CONTEXT);

    ucxControllerContext = GetUcxControllerContext(UcxController);

    status = UcxEndpointCreate(UcxUsbDevice,
        &UcxEndpointInit,
        &objectAttributes,
        &ucxEndpoint);

    if (!NT_SUCCESS(status)) {
        DbgTrace(TL_ERROR, Endpoint, "UcxEndpoint Failed %!STATUS!", status);
        goto EvtUsbDeviceEndpointAddEnd;
    }

    DbgTrace(TL_INFO, Endpoint, "UcxEndpoint created");

    ucxEndpointContext = GetUcxEndpointContext(ucxEndpoint);

    ucxEndpointContext->IsDefault = FALSE;
    ucxEndpointContext->MaxPacketSize = MAX_PACKET_SIZE;

    WDF_IO_QUEUE_CONFIG_INIT(&queueConfig, WdfIoQueueDispatchManual);

    status = WdfIoQueueCreate(ucxControllerContext->WdfDevice,
        &queueConfig,
        WDF_NO_OBJECT_ATTRIBUTES,
        &ucxEndpointContext->IoQueue);

    if (!NT_SUCCESS(status)) {
        DbgTrace(TL_ERROR, Endpoint, "WdfIoQueueCreate Failed %!STATUS!", status);
        goto EvtUsbDeviceEndpointAddEnd;
    }

    UcxEndpointSetWdfIoQueue(ucxEndpoint, ucxEndpointContext->IoQueue);

EvtUsbDeviceEndpointAddEnd:

    return status;
}
```

## See also

[UcxDefaultEndpointInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxdefaultendpointinitseteventcallbacks)

[UcxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/nf-ucxendpoint-ucxendpointcreate)

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)

[WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)
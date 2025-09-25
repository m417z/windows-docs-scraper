# EVT_UFX_DEVICE_ENDPOINT_ADD callback function

## Description

The client driver's implementation to create a default endpoint object.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `unnamedParam2` [in]

A pointer to a [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structure that contains descriptor data.

### `unnamedParam3` [in, out]

A pointer to an UFXENDPOINT_INIT opaque structure that contains the endpoint descriptor required to create an endpoint object.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_ENDPOINT_ADD* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

To create the endpoint the client driver is expected to initialize the attributes of the endpoint’s transfer and command queues, and then call [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate) to create the endpoint.

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

#### Examples

```
EVT_UFX_DEVICE_ENDPOINT_ADD UfxDevice_EvtDeviceEndpointAdd;

NTSTATUS
UfxDevice_EvtDeviceEndpointAdd (
    _In_ UFXDEVICE UfxDevice,
    _In_ const PUSB_ENDPOINT_DESCRIPTOR EndpointDescriptor,
    _Inout_ PUFXENDPOINT_INIT EndpointInit
    )
/*++

Routine Description:

    EvtDeviceEndpointAdd handler for the UFXDEVICE object.
    Creates UFXENDPOINT object corresponding to the newly reported endpoint.

Arguments:

    UfxDevice - UFXDEVICE object representing the device.

    EndpointDescriptor - Constant Pointer to Endpoint descriptor for the
        newly reported endpoint.

    EndpointInit - Pointer to the Opaque UFXENDPOINT_INIT object

Return Value:

    STATUS_SUCCESS on success, or an appropriate NTSTATUS message on failure.

--*/
{
    NTSTATUS Status;
    WDF_OBJECT_ATTRIBUTES Attributes;
    WDF_IO_QUEUE_CONFIG TransferQueueConfig;
    WDF_OBJECT_ATTRIBUTES TransferQueueAttributes;
    WDF_IO_QUEUE_CONFIG CommandQueueConfig;
    WDF_OBJECT_ATTRIBUTES CommandQueueAttributes;
    UFXENDPOINT Endpoint;
    PUFXENDPOINT_CONTEXT EpContext;
    PUFXDEVICE_CONTEXT DeviceContext;
    UFX_ENDPOINT_CALLBACKS Callbacks;
    PENDPOINT_QUEUE_CONTEXT QueueContext;
    WDFQUEUE Queue;

    TraceEntry();

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&Attributes, UFXENDPOINT_CONTEXT);
    Attributes.ExecutionLevel = WdfExecutionLevelPassive;
    Attributes.EvtCleanupCallback = UfxEndpoint_Cleanup;

    //
    // Note: Execution level needs to be passive to avoid deadlocks with WdfRequestComplete.
    //
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&TransferQueueAttributes, ENDPOINT_QUEUE_CONTEXT);
    TransferQueueAttributes.ExecutionLevel = WdfExecutionLevelPassive;

    WDF_IO_QUEUE_CONFIG_INIT(&TransferQueueConfig, WdfIoQueueDispatchManual);
    TransferQueueConfig.AllowZeroLengthRequests = TRUE;
    TransferQueueConfig.EvtIoStop = EndpointQueue_EvtIoStop;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&CommandQueueAttributes, ENDPOINT_QUEUE_CONTEXT);
    CommandQueueAttributes.ExecutionLevel = WdfExecutionLevelPassive;

    WDF_IO_QUEUE_CONFIG_INIT(&CommandQueueConfig, WdfIoQueueDispatchSequential);
    CommandQueueConfig.EvtIoInternalDeviceControl = EvtEndpointCommandQueue;

    UFX_ENDPOINT_CALLBACKS_INIT(&Callbacks);
    UfxEndpointInitSetEventCallbacks(EndpointInit, &Callbacks);

    Status = UfxEndpointCreate(
                 Device,
                 EndpointInit,
                 &Attributes,
                 &TransferQueueConfig,
                 &TransferQueueAttributes,
                 &CommandQueueConfig,
                 &CommandQueueAttributes,
                 &Endpoint);

    Status = WdfCollectionAdd(DeviceContext->Endpoints, Endpoint);

    EpContext = UfxEndpointGetContext(Endpoint);
    EpContext->UfxDevice = Device;
    EpContext->WdfDevice = DeviceContext->FdoWdfDevice;
    RtlCopyMemory(&EpContext->Descriptor, Descriptor, sizeof(*Descriptor));

    Queue = UfxEndpointGetTransferQueue(Endpoint);
    QueueContext = EndpointQueueGetContext(Queue);
    QueueContext->Endpoint = Endpoint;

    Queue = UfxEndpointGetCommandQueue(Endpoint);
    QueueContext = EndpointQueueGetContext(Queue);
    QueueContext->Endpoint = Endpoint;

    //
    // This can happen if we're handling a SetInterface command.
    //
    if (DeviceContext->UsbState == UsbfnDeviceStateConfigured) {
        UfxEndpointConfigure(Endpoint);
    }

    Status = WdfIoQueueReadyNotify(
                 UfxEndpointGetTransferQueue(Endpoint),
                 TransferReadyNotify,
                 Endpoint);

End:
    TraceExit();
    return Status;
}
```

## See also

[UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)

[UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)
# UfxEndpointCreate function

## Description

Creates an endpoint object.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `EndpointInit` [in, out]

Opaque structure passed by UFX in the call to [EVT_UFX_DEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_endpoint_add) or [EVT_UFX_DEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_default_endpoint_add).

### `Attributes` [in, optional]

A pointer to caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. This structure must be initialized with [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) or [WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type). This parameter is optional and can be **WDF_NO_OBJECT_ATTRIBUTES**.

### `TransferQueueConfig` [in]

A pointer to a caller allocated [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure. This structure must be initialized with [WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init).

### `TransferQueueAttributes` [in, optional]

A pointer to caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. This structure must be initialized with [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) or [WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type). This parameter is optional and can be **WDF_NO_OBJECT_ATTRIBUTES**.

### `CommandQueueConfig` [in]

A pointer to a caller allocated [WDF_IO_QUEUE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config) structure. This structure must be initialized with [WDF_IO_QUEUE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_config_init).

### `CommandQueueAttributes` [in, optional]

A pointer to caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. This structure must be initialized with [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) or [WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type). This parameter is optional and can be **WDF_NO_OBJECT_ATTRIBUTES**.

### `UfxEndpoint` [out]

A pointer to a location that receives a handle to a UFXENDPOINT object.

## Return value

If the operation is successful, the method returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

 The transfer queue handles the following IOCTLs related to endpoint transfers:

* [IOCTL_INTERNAL_USBFN_CONTROL_STATUS_HANDSHAKE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_control_status_handshake_in)
* [IOCTL_INTERNAL_USBFN_CONTROL_STATUS_HANDSHAKE_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_control_status_handshake_out)
* [IOCTL_INTERNAL_USBFN_TRANSFER_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_transfer_in)
* [IOCTL_INTERNAL_USBFN_TRANSFER_IN_APPEND_ZERO_PKT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_transfer_in_append_zero_pkt)
* [IOCTL_INTERNAL_USBFN_TRANSFER_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_transfer_out)

The command queue will handle the following IOCTLs:

* [IOCTL_INTERNAL_USBFN_GET_PIPE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_get_pipe_state)
* [IOCTL_INTERNAL_USBFN_SET_PIPE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_set_pipe_state)
* [IOCTL_INTERNAL_USBFN_DESCRIPTOR_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxbase/ni-ufxbase-ioctl_internal_usbfn_descriptor_update)

The following example shows how to create a UFXENDPOINT object and initialize its context.

```
NTSTATUS
UfxEndpointAdd (
    _In_ UFXDEVICE Device,
    _In_ PUSB_ENDPOINT_DESCRIPTOR Descriptor,
    _Inout_ PUFXENDPOINT_INIT EndpointInit
    )
/*++
Routine Description:

    Creates a UFXENDPOINT object, and initializes its contexts.

Parameters Description:

    Device - UFXDEVICE associated with the endpoint.

    Descriptor - Endpoint descriptor for this endpoint.

    EndpointInit - Opaque structure from UFX.

Return Value:

    STATUS_SUCCESS if successful, appropriate NTSTATUS message otherwise.
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

    DeviceContext = UfxDeviceGetContext(Device);

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
    CHK_NT_MSG(Status, "Failed to create ufxendpoint!");

    Status = WdfCollectionAdd(DeviceContext->Endpoints, Endpoint);
    CHK_NT_MSG(Status, "Failed to add endpoint to collection!");

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

    Status = TransferInitialize(Endpoint);
    CHK_NT_MSG(Status, "Failed to initialize endpoint transfers");

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
    CHK_NT_MSG(Status, "Failed to register ready notify");

End:
    TraceExit();
    return Status;
}

```
# EVT_UCX_CONTROLLER_USBDEVICE_ADD callback function

## Description

The client driver's implementation that UCX calls when a new USB device is detected.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `UcxUsbDeviceInfo` [in]

Pointer to a [UCXUSBDEVICE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucxusbdevice_info) structure.

### `UsbDeviceInit` [in]

Pointer to an opaque structure containing initialization
information. Callbacks for the device object are associated with this structure.
This structure is managed by UCX.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The UCX client driver registers its *EVT_UCX_CONTROLLER_USBDEVICE_ADD* implementation with the USB host controller extension (UCX) by calling the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

This callback function creates a new USB device object and registers the
USB device object callback functions by calling
[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate). The function may need to allocate the common buffer that will be
used as the device context.

#### Examples

```
NTSTATUS
UsbDevice_EvtControllerUsbDeviceAdd(
    UCXCONTROLLER       UcxController,
    PUCXUSBDEVICE_INFO  UsbDeviceInfo,
    PUCXUSBDEVICE_INIT  UsbDeviceInit
)

{
    NTSTATUS                        status = STATUS_SUCCESS;

    WDF_OBJECT_ATTRIBUTES           objectAttributes;
    UCX_USBDEVICE_EVENT_CALLBACKS   callbacks;

    UCXUSBDEVICE                    ucxUsbDevice;
    PUCX_USB_DEVICE_CONTEXT         ucxUsbDeviceContext;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&objectAttributes, UCX_USB_DEVICE_CONTEXT);

    //
    // Set the event callbacks for the USB device.
    //
    UCX_USBDEVICE_EVENT_CALLBACKS_INIT(&callbacks,
                                       UsbDevice_EvtUcxUsbDeviceEndpointsConfigure,
                                       UsbDevice_EvtUcxUsbDeviceEnable,
                                       UsbDevice_EvtUcxUsbDeviceDisable,
                                       UsbDevice_EvtUcxUsbDeviceReset,
                                       UsbDevice_EvtUcxUsbDeviceAddress,
                                       UsbDevice_EvtUcxUsbDeviceUpdate,
                                       UsbDevice_EvtUcxUsbDeviceHubInfo,
                                       Endpoint_EvtUcxUsbDeviceDefaultEndpointAdd,
                                       Endpoint_EvtUcxUsbDeviceEndpointAdd);

    UcxUsbDeviceInitSetEventCallbacks(UsbDeviceInit, &callbacks);

    //
    // Create the device
    //
    status = UcxUsbDeviceCreate(UcxController,
                                &UsbDeviceInit,
                                &objectAttributes,
                                &ucxUsbDevice);

    if (!NT_SUCCESS(status)) {
        DbgTrace(TL_ERROR, UsbDevice, "UcxUsbDeviceCreate Failed %!STATUS!", status);
        goto EvtControllerUsbDeviceAddEnd;
    }

    ucxUsbDeviceContext = GetUcxUsbDeviceContext(ucxUsbDevice);
    ucxUsbDeviceContext->DeviceSpeed = UsbDeviceInfo->DeviceSpeed;
    ucxUsbDeviceContext->TtHub = UsbDeviceInfo->TtHub;
    RtlCopyMemory(&ucxUsbDeviceContext->PortPath,
                  &UsbDeviceInfo->PortPath,
                  sizeof(USB_DEVICE_PORT_PATH));

    DbgTrace(TL_INFO, UsbDevice, "UsbDevice_EvtControllerUsbDeviceAdd");

EvtControllerUsbDeviceAddEnd:

    return status;
}
```

## See also

[UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85))
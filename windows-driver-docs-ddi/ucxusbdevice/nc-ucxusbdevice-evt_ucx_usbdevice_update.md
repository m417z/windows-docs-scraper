# EVT_UCX_USBDEVICE_UPDATE callback function

## Description

The client driver's implementation that UCX calls to
update device properties.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `Request` [in]

Contains the [USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update) structure.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

The host controller driver communicates with the hardware to update descriptors, LPM parameters, whether device is a hub, and
maximum exit latency, as needed.

The client driver returns completion status in *Request*. The driver can complete the WDFREQUEST asynchronously.

#### Examples

```
VOID
UsbDevice_EvtUcxUsbDeviceUpdate(
    UCXCONTROLLER      UcxController,
    WDFREQUEST         Request
)

{
    UNREFERENCED_PARAMETER(UcxController);

    DbgTrace(TL_INFO, UsbDevice, "UsbDevice_EvtUcxUsbDeviceUpdate");

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(WdfRequest, &wdfRequestParams);
    usbDeviceUpdate = (PUSBDEVICE_UPDATE)wdfRequestParams.Parameters.Others.Arg1;
    ...

    WdfRequestComplete(Request, STATUS_SUCCESS);
}
```

## See also

[UCX_USBDEVICE_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucx_usbdevice_event_callbacks_init)

[USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update)

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)

[UcxUsbDeviceInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdeviceinitseteventcallbacks)
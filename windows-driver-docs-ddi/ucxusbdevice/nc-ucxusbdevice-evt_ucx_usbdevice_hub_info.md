# EVT_UCX_USBDEVICE_HUB_INFO callback function

## Description

The client driver's implementation that UCX calls to
retrieve hub properties.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `Request` [in]

Contains the [USBDEVICE_HUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_hub_info) structure.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

If the USB device is not a hub, do not provide this callback.

The client driver returns completion status in *Request*. The driver can complete the WDFREQUEST asynchronously.

#### Examples

```
VOID
UsbDevice_EvtUcxUsbDeviceHubInfo(
    UCXCONTROLLER      UcxController,
    WDFREQUEST         Request
)

{
    UNREFERENCED_PARAMETER(UcxController);

    DbgTrace(TL_INFO, UsbDevice, "UsbDevice_EvtUcxUsbDeviceHubInfo");

    //
    // Retrieve the USBDEVICE_HUB_INFO pointer from the
    // IOCTL_INTERNAL_USB_USBDEVICE_HUB_INFO WdfRequest.
    //
    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(WdfRequest, &wdfRequestParams);

    hubInfo = (PUSBDEVICE_HUB_INFO)wdfRequestParams.Parameters.Others.Arg1;

    ....

    WdfRequestComplete(Request, STATUS_SUCCESS);
}
```

## See also

[UCX_USBDEVICE_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_event_callbacks)

[UCX_USBDEVICE_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucx_usbdevice_event_callbacks_init)

[USBDEVICE_HUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_hub_info)

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)
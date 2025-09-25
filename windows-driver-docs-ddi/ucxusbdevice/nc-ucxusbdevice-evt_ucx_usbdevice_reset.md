# EVT_UCX_USBDEVICE_RESET callback function

## Description

The client driver's implementation that UCX calls when the port to which the device is
attached is reset.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `Request` [in]

Contains the [USBDEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_reset) structure.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

To
transition the device to the desired state, the host controller driver communicates with the hardware to complete the request.

The client driver returns completion status in *Request*. The driver can complete the WDFREQUEST asynchronously.

#### Examples

```
VOID
UsbDevice_EvtUcxUsbDeviceReset(
    UCXCONTROLLER      UcxController,
    WDFREQUEST         Request
)

{
    UNREFERENCED_PARAMETER(UcxController);

    DbgTrace(TL_INFO, UsbDevice, "UsbDevice_EvtUcxUsbDeviceReset");

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(WdfRequest, &wdfRequestParams);
    usbDeviceReset = (PUSBDEVICE_RESET)wdfRequestParams.Parameters.Others.Arg1;
    ...

    WdfRequestComplete(Request, STATUS_SUCCESS);
}
```

## See also

[USBDEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_reset)

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)
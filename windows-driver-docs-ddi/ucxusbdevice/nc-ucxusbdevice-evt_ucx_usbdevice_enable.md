# EVT_UCX_USBDEVICE_ENABLE callback function

## Description

The client driver's implementation that UCX calls to program information about the device and its default control endpoint
into the controller.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `Request` [in]

A structure of type [USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_enable).

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

To
transition the device to the desired state, the host controller driver communicates with the hardware to complete the request.

In this callback function, the client driver prepares the controller to accept and schedule transfers on the default control
endpoint for the USB device.

When the driver has finished, it completes the WDFREQUEST.

The client driver returns completion status in *Request*. The driver can complete the WDFREQUEST asynchronously.

#### Examples

```
VOID
UsbDevice_EvtUcxUsbDeviceEnable(
    UCXCONTROLLER      UcxController,
    WDFREQUEST         Request
)

{
    UNREFERENCED_PARAMETER(UcxController);

    DbgTrace(TL_INFO, UsbDevice, "UsbDevice_EvtUcxUsbDeviceEnable");

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(WdfRequest, &wdfRequestParams);
    usbDeviceEnable = (PUSBDEVICE_ENABLE)wdfRequestParams.Parameters.Others.Arg1;
    ...

    WdfRequestComplete(Request, STATUS_SUCCESS);
}
```

## See also

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)
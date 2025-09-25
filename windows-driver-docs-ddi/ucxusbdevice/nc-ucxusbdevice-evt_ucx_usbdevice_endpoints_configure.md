# EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE callback function

## Description

The client driver's implementation that UCX calls to configure endpoints in the controller.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `Request` [in]

Contains a structure of type [ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_endpoints_configure) structure.

## Remarks

The UCX client driver registers this callback function with the USB host controller extension (UCX) by calling the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method.

In the callback, the driver programs or deprograms the endpoints, as described in the [ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_endpoints_configure) structure.

This callback does not enable or disable the default endpoint. The default endpoint’s state is tied to the state of the device. The driver implements enable and disable operations in the [EVT_UCX_USBDEVICE_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_disable) and [EVT_UCX_USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_enable) callback functions.

The client driver returns completion status in *Request*. The driver can complete the WDFREQUEST asynchronously.

#### Examples

```
VOID
UsbDevice_EvtUcxUsbDeviceEndpointsConfigure(
    UCXCONTROLLER      UcxController,
    WDFREQUEST         Request
)

{
    UNREFERENCED_PARAMETER(UcxController);

    DbgTrace(TL_INFO, UsbDevice, "UsbDevice_EvtUcxUsbDeviceEndpointsConfigure");

    WDF_REQUEST_PARAMETERS_INIT(&wdfRequestParams);
    WdfRequestGetParameters(WdfRequest, &wdfRequestParams);

    ...

    endpointsConfigure = (PENDPOINTS_CONFIGURE)wdfRequestParams.Parameters.Others.Arg1;

    ...

    WdfRequestComplete(Request, STATUS_SUCCESS);
}
```

## See also

[ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_endpoints_configure)

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)
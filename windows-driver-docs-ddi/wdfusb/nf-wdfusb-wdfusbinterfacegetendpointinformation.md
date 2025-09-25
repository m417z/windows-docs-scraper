# WdfUsbInterfaceGetEndpointInformation function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceGetEndpointInformation** method retrieves information about a specified USB device endpoint and its associated pipe.

## Parameters

### `UsbInterface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

### `SettingIndex` [in]

An index value that identifies an alternate setting for the interface. For more information about alternate settings, see the USB specification.

### `EndpointIndex` [in]

An index value that identifies an endpoint that is associated with the specified alternate setting of the specified interface. (This index value is not the endpoint address.)

### `EndpointInfo` [in, out]

A pointer to a caller-allocated [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure that the framework fills in.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

For more information about the **WdfUsbInterfaceGetEndpointInformation** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the number of endpoints that a USB interface supports and then calls **WdfUsbInterfaceGetEndpointInformation** for each endpoint.

```cpp
WDF_USB_PIPE_INFORMATION endPointInfo;
BYTE settingIndex, i;

settingIndex = 0;
numEndpoints = WdfUsbInterfaceGetNumEndpoints(
                                          UsbInterface,
                                          settingIndex
                                          );

for (i = 0; i < numEndpoints; i++){
    WDF_USB_PIPE_INFORMATION_INIT(&endPointInfo);
    WdfUsbInterfaceGetEndpointInformation(
                                          UsbInterface,
                                          settingIndex,
                                          i,
                                          &endPointInfo
                                          );

    //
    // Examine endpoint information here.
    //
...
}
```

## See also

[WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information)

[WdfUsbInterfaceGetNumEndpoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetnumendpoints)

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)
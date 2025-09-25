# UfxDevicePortDetectComplete function

## Description

Notifies UFX about the port type that was detected.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `PortType` [in]

Contains an enumeration value of type [USBFN_PORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ne-usbfnbase-_usbfn_port_type).

## Remarks

The client driver calls **UfxDevicePortDetectComplete** when port detection is complete. On some platforms, UFX may use the reported port type to notify the battery manager of the maximum current it can draw from the USB port.

The client driver typically calls **UfxDevicePortDetectComplete** from its [EVT_UFX_DEVICE_PORT_DETECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_port_detect) callback function, as shown in this example.

```
    // In this example we will return an unknown port type.  This will allow UFX to connect to a host if
    // one is present.  UFX will timeout after 5 seconds if no host is present and transition to
    // an invalid charger type, which will allow the controller to exit D0.
    //
    UfxDevicePortDetectComplete(ControllerContext->UfxDevice, UsbfnUnknownPort);

```
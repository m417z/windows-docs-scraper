# EVT_UFX_DEVICE_PORT_DETECT callback function

## Description

The client driver's implementation to initiate port detection

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_PORT_DETECT* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

The client driver must indicate completion of port detection by calling the [UfxDevicePortDetectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceportdetectcomplete) or [UfxDevicePortDetectCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceportdetectcompleteex) methods.

### Examples

```cpp
EVT_UFX_DEVICE_PORT_DETECT UfxDevice_EvtDevicePortDetect;

VOID
UfxDevice_EvtDevicePortDetect (
    _In_ UFXDEVICE UfxDevice
    )
/*++
Routine Description:

    Starts the port detection state machine

Arguments:

    UfxDevice - UFXDEVICE object representing the device.

--*/
{
    PUFXDEVICE_CONTEXT DeviceContext;
    PCONTROLLER_CONTEXT ControllerContext;

    DeviceContext = UfxDeviceGetContext(UfxDevice);
    ControllerContext = DeviceGetControllerContext(DeviceContext->FdoWdfDevice);

    //
    // #### TODO: Insert code to determine port/charger type ####
    //
    // In this example we will return an unknown port type.
    // This will allow UFX to connect to a host if one is present.
    // UFX will timeout after 5 seconds if no host is present and transition to
    // an invalid charger type, which will allow the controller to exit D0.
    //

    UfxDevicePortDetectComplete(ControllerContext->UfxDevice, UsbfnUnknownPort);
}

```

## See also

- [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)
- [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)
- [UfxDevicePortDetectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceportdetectcomplete)
- [UfxDevicePortDetectCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceportdetectcompleteex)
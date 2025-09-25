# EVT_UFX_DEVICE_ADDRESSED callback function

## Description

The client driver's implementation to assign an address on the function controller.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `unnamedParam2` [in]

New USB device address to assign.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_ADDRESSED* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

#### Examples

```

EVT_UFX_DEVICE_ADDRESSED UfxDevice_EvtDeviceAddressed;

VOID
UfxDevice_EvtDeviceAddressed (
    _In_ UFXDEVICE UfxDevice,
    _In_ USHORT DeviceAddress
    )
/*++

Routine Description:

    EvtDeviceAddressed handler for the UFXDEVICE object.
    Sets the Address indicated by 'DeviceAddress' on the controller.

Arguments:

    UfxDevice - UFXDEVICE object representing the device.

    DeviceAddress - USB Device Address, as determined by the UFX.

--*/
{
    UNREFERENCED_PARAMETER(DeviceAddress);

    TraceEntry();

    //
    // Set the device address on the controller
    //

    //
    // #### Insert code to set the device address on controller ####
    //

    UfxDeviceEventComplete(UfxDevice, STATUS_SUCCESS);

    TraceExit();
}

```

## See also

[UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)

[UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)
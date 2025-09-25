# EVT_UFX_DEVICE_PORT_CHANGE callback function

## Description

The client driver's implementation to update the type of the new port to which the USB device is connected.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `unnamedParam2` [in]

A USBFN_PORT_STATE-typed flag that indicates the type of the new port.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_PORT_CHANGE* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

UFX invokes this event callback to inform the client driver about the new state of the device.

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

#### Examples

```

EVT_UFX_DEVICE_PORT_CHANGE UfxDevice_EvtDevicePortChange;

VOID
UfxDevice_EvtDevicePortChange (
    _In_        UFXDEVICE UfxDevice,
    _In_        USBFN_PORT_TYPE NewPort
    )
/*++

Routine Description:

    EvtDevicePortChange handler for the UFXDEVICE object.
    Caches the new port type, and stops or resumes idle as needed.

Arguments:

    UfxDevice - UFXDEVICE object representing the device.

    NewPort - New port type

--*/
{
    NTSTATUS Status;
    PUFXDEVICE_CONTEXT Context;

    PAGED_CODE();

    TraceEntry();

    Context = UfxDeviceGetContext(UfxDevice);

    TraceInformation("New PORT: %d", NewPort);

    //
    //  #### TODO: Insert code to examine the device USB state and port type
    //      and determine if it needs to stop or resume idle.

    UfxDeviceEventComplete(UfxDevice, STATUS_SUCCESS);
    TraceExit();
}
```

## See also

[UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)

[UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)
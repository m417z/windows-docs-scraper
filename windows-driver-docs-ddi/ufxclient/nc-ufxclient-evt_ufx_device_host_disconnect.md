# EVT_UFX_DEVICE_HOST_DISCONNECT callback function

## Description

The client driver's implementation to disable the function controller's communication with the host.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_HOST_DISCONNECT* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

UFX invokes this event callback to perform a soft-disconnect on the USB cable. After this call, the client driver must not initiate a connection with the host until UFX invokes [EVT_UFX_DEVICE_HOST_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_host_connect).

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

### Examples

```cpp
EVT_UFX_DEVICE_HOST_DISCONNECT UfxDevice_EvtDeviceHostDisconnect;

VOID
UfxDevice_EvtDeviceHostDisconnect (
    _In_ UFXDEVICE UfxDevice
    )
/*++

Routine Description:

    EvtDeviceHostDisconnect callback handler for UFXDEVICE object.

Arguments:

    UfxDevice - UFXDEVICE object representing the device.

--*/
{
    PCONTROLLER_CONTEXT ControllerContext;
    PUFXDEVICE_CONTEXT DeviceContext;
    BOOLEAN EventComplete;

    TraceEntry();

    DeviceContext = UfxDeviceGetContext(UfxDevice);
    ControllerContext = DeviceGetControllerContext(DeviceContext->FdoWdfDevice);

    EventComplete = TRUE;

    //
    // #### TODO: Cancel all transfers. ####
    //

    WdfSpinLockAcquire(ControllerContext->DpcLock);

    //
    // #### TODO: Insert code to clear the run state on the controller ####
    //

    WdfSpinLockRelease(ControllerContext->DpcLock);

    if (EventComplete) {
        UfxDeviceEventComplete(UfxDevice, STATUS_SUCCESS);
    }

    TraceExit();
}

```

## See also

- [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)
- [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)
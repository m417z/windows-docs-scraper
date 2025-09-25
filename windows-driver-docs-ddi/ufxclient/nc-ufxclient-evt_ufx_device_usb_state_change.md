# EVT_UFX_DEVICE_USB_STATE_CHANGE callback function

## Description

The client driver's implementation to update the state of the USB device.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `unnamedParam2` [in]

A USBFN_DEVICE_STATE-typed flag that indicates state of the USB device.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_USB_STATE_CHANGE* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

UFX invokes this event callback to inform the client driver about the new state of the device.

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

#### Examples

```

EVT_UFX_DEVICE_USB_STATE_CHANGE UfxDevice_EvtDeviceUsbStateChange;

VOID
UfxDevice_EvtDeviceUsbStateChange (
    _In_ UFXDEVICE UfxDevice,
    _In_ USBFN_DEVICE_STATE NewState
)
/*++

Routine Description:

    EvtDeviceUsbStateChange handler for the UFXDEVICE object.

Arguments:

    UfxDevice - UFXDEVICE object representing the device.

    NewState - The new device state.

--*/
{
    NTSTATUS Status;
    PUFXDEVICE_CONTEXT Context;
    PCONTROLLER_CONTEXT ControllerContext;
    ULONG EpIndex;
    USBFN_DEVICE_STATE OldState;

    PAGED_CODE();

    TraceEntry();

    Context = UfxDeviceGetContext(UfxDevice);
    ControllerContext = DeviceGetControllerContext(Context->FdoWdfDevice);
    OldState = Context->UsbState;

    TraceInformation("New STATE: %d", NewState);

    Status = UfxDeviceStopOrResumeIdle(UfxDevice, NewState, Context->UsbPort);
    LOG_NT_MSG(Status, "Failed to stop or resume idle");

    WdfWaitLockAcquire(ControllerContext->InitializeDefaultEndpointLock, NULL);
    if (ControllerContext->InitializeDefaultEndpoint == TRUE) {
        //
        // Reset endpoint 0. This is the last part of soft reset, which was postponed
        // until now, since we need to make sure EP0 is created by UFX.
        //
        DeviceInitializeDefaultEndpoint(Context->FdoWdfDevice);
        ControllerContext->InitializeDefaultEndpoint = FALSE;
    }
    WdfWaitLockRelease(ControllerContext->InitializeDefaultEndpointLock);

    if (NewState == UsbfnDeviceStateConfigured && OldState != UsbfnDeviceStateSuspended) {

        for (EpIndex = 1; EpIndex < WdfCollectionGetCount(Context->Endpoints); EpIndex++) {
            UfxEndpointConfigure(WdfCollectionGetItem(Context->Endpoints, EpIndex));
        }

        //
        // #### TODO: Insert code to allow the controller to accept U1/U2, if supported ####
        //

    }

    if (NewState == UsbfnDeviceStateDetached) {
        KeSetEvent(&ControllerContext->DetachEvent,
                   IO_NO_INCREMENT,
                   FALSE);
    }

    UfxDeviceEventComplete(UfxDevice, STATUS_SUCCESS);
    TraceExit();
}

```

## See also

[UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)

[UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)
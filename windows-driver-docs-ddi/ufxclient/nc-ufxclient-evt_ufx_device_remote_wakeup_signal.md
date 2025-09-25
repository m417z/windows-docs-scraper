# EVT_UFX_DEVICE_REMOTE_WAKEUP_SIGNAL callback function

## Description

The client driver's implementation to initiate remote wake-up on the function controller.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_REMOTE_WAKEUP_SIGNAL* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

### Examples

```cpp
EVT_UFX_DEVICE_REMOTE_WAKEUP_SIGNAL UfxDevice_EvtDeviceRemoteWakeupSignal;

VOID
UfxDevice_EvtDeviceRemoteWakeupSignal (
 _In_ UFXDEVICE UfxDevice
 )
/*++
Routine Description:

 Signals Remote Wakeup to the Host by issuing a link state change command.
 It acquires and releases the power reference to ensure a valid power state
 before accessing the device.

Arguments:

 UfxDevice - UFXDEVICE object representing the device.

--*/
{
 NTSTATUS Status;
 PUFXDEVICE_CONTEXT DeviceContext;

 PAGED_CODE();

 TraceEntry();

 DeviceContext = UfxDeviceGetContext(UfxDevice);

 //
 // Stop Idle to ensure the device is in working state
 //

 Status = WdfDeviceStopIdle(DeviceContext->FdoWdfDevice, TRUE);
 if (!NT_SUCCESS(Status)) {
  TraceError("Failed to stop idle %!STATUS!", Status);
  goto End;
 }

 //
 // Issue a Link State Change Request.
 //

 //
 // #### TODO: Insert code to issue a link state change on the controller ####
 //

 WdfDeviceResumeIdle(DeviceContext->FdoWdfDevice);

End:
 UfxDeviceEventComplete(UfxDevice, Status);
 TraceExit();
}
```

## See also

- [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)
- [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)
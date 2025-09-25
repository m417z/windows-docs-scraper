# UfxDeviceNotifyHardwareReady function

## Description

Notifies UFX that the hardware is ready.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

## Remarks

The client driver typically calls **UfxDeviceNotifyHardwareReady** from its [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function, as shown in the following example.

```
NTSTATUS
OnEvtDeviceD0Entry (
  _In_ WDFDEVICE Device,
  _In_ WDF_POWER_DEVICE_STATE PreviousState
)
/*++

Routine Description:

    Called by the framework after entering D0 state.

Arguments:

    Device - WDFDEVICE framework handle to the bus FDO.

    PreviousState - The WDF_POWER_DEVICE_STATE from which the stack is
        making this transition.

Return Value:

    Returns STATUS_SUCCESS or an appropriate NTSTATUS code otherwise.

--*/
{
    PCONTROLLER_CONTEXT ControllerContext;

    TraceEntry();

    ControllerContext = DeviceGetControllerContext(Device);

    if (PreviousState > WdfPowerDeviceD1) {
        DevicePerformSoftReset(Device);

        WdfWaitLockAcquire(ControllerContext->InitializeDefaultEndpointLock, NULL);
        ControllerContext->InitializeDefaultEndpoint = TRUE;
        WdfWaitLockRelease(ControllerContext->InitializeDefaultEndpointLock);
    }

    if (PreviousState == WdfPowerDeviceD3Final) {
        //
        // Notify UFX that HW is now ready
        //
        UfxDeviceNotifyHardwareReady(ControllerContext->UfxDevice);
    }

    TraceExit();
    return STATUS_SUCCESS;
}
```
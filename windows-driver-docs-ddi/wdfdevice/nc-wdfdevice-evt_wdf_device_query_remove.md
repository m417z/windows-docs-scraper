# EVT_WDF_DEVICE_QUERY_REMOVE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceQueryRemove* event callback function determines whether a specified device can be stopped and removed.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the driver determines that the device can be stopped and removed, the *EvtDeviceQueryRemove* callback function must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**. Do not return STATUS_NOT_SUPPORTED.

## Remarks

To register an *EvtDeviceQueryRemove* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the device and driver support idle power-down, the device might not be in its working state when the framework calls the driver's *EvtDeviceQueryRemove* callback function. The callback function can call [WdfDeviceStopIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidle) to force the device into its working (D0) state, and then the callback function can call [WdfDeviceResumeIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceresumeidle) before it returns.

For more information about the *EvtDeviceQueryRemove* callback function, see [Handling Requests to Stop a Device](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-requests-to-stop-a-device).

The framework does not synchronize the *EvtDeviceQueryRemove* callback function with other PnP and power management callback functions. For information about how the framework synchronizes the execution of a driver's event callback functions, see [Using Automatic Synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization).

## See also

[EvtDeviceQueryStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_query_stop)
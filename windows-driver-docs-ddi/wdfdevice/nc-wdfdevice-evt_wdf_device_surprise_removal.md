# EVT_WDF_DEVICE_SURPRISE_REMOVAL callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceSurpriseRemoval* event callback function performs any operations that are needed after a device has been unexpectedly removed from the system or after a driver reports that [the device has failed](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

To register an *EvtDeviceSurpriseRemoval* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

The framework does not synchronize the *EvtDeviceSurpriseRemoval* callback function with other PnP and power management callback functions. For information about how the framework synchronizes the execution of a driver's event callback functions, see [Using Automatic Synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization).

For more information about when the framework calls this callback function, and for more information about synchronization issues, see [A User Unplugs a Device](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-user-unplugs-a-device).
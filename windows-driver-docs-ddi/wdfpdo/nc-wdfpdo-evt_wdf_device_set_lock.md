# EVT_WDF_DEVICE_SET_LOCK callback function

## Description

[Applies to KMDF only]

A driver's *EvtDeviceSetLock* event callback function locks the specified device so that it cannot be ejected, or unlocks the device so that it can be ejected.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `IsLocked` [in]

A Boolean value that indicates whether the driver must lock or unlock the device. If **TRUE**, the driver must lock the device so that it cannot be ejected. If **FALSE**, the driver must unlock the device so that it can be ejected.

## Return value

If the driver successfully locks or unlocks the device, it must return STATUS_SUCCESS. Otherwise it must return an NTSTATUS value that [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) evaluates as **FALSE**.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

Framework-based bus drivers can provide an *EvtDeviceSetLock* callback function. To register this callback function, bus drivers call [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

The framework calls the driver's *EvtDeviceSetLock* callback function when the PnP manager requests the bus driver to lock or unlock one of its enumerated child devices.

Not implementing an *EvtDeviceSetLock* callback function for a device is equivalent to returning an NTSTATUS value that evaluates as **FALSE**.

For more information about return values, see [Supporting Ejectable Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-ejectable-devices).

## See also

[EvtDeviceEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_eject)
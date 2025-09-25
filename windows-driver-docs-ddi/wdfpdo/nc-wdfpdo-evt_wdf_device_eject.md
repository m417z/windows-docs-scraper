# EVT_WDF_DEVICE_EJECT callback function

## Description

[Applies to KMDF only]

A driver's *EvtDeviceEject* event callback function handles operations that are necessary to eject a device from its docking station.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the operation succeeds, the driver must return STATUS_SUCCESS. Otherwise it must return an NTSTATUS value that [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) evaluates as **FALSE**. Do not return STATUS_NOT_SUPPORTED.

For more information about return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

Framework-based bus drivers can provide an *EvtDeviceEject* callback function. A bus driver must provide an *EvtDeviceEject* callback function if the driver must perform operations that physically eject one of its enumerated child devices from the device's docking station. To register this callback function, the bus driver must call [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

Before calling the *EvtDeviceEject* callback function, the framework calls the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) and [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback functions.

If a driver's *EvtDeviceEject* callback function returns STATUS_SUCCESS, the framework updates the driver's child list to indicate that the ejected device is no longer available. Therefore the driver does not have to call [WdfPdoMarkMissing](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdomarkmissing) or [WdfChildListUpdateChildDescriptionAsMissing](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistupdatechilddescriptionasmissing).

For more information about device ejection, see [Supporting Ejectable Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-ejectable-devices).

## See also

[EvtDeviceSetLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_set_lock)
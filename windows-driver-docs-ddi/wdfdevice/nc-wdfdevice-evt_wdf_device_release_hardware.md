# EVT_WDF_DEVICE_RELEASE_HARDWARE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceReleaseHardware* event callback function performs operations that are needed when a device is no longer accessible.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `ResourcesTranslated` [in]

A handle to a resource list object that identifies the translated hardware resources that the Plug and Play manager has assigned to the device.

## Return value

If the *EvtDeviceReleaseHardware* callback function encounters no errors, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise, it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**. Do not return STATUS_NOT_SUPPORTED.

## Remarks

To register an *EvtDeviceReleaseHardware* callback function, your driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If a driver has registered an *EvtDeviceReleaseHardware* callback function, the framework calls it during the following transitions:

* Resource rebalancing
* Orderly removal
* Surprise removal

The framework calls the *EvtDeviceReleaseHardware* callback function after the framework has stopped sending I/O requests to the device, any interrupts assigned to the device have been disabled and disconnected, and the device has been turned off.

 When the framework calls the *EvtDeviceReleaseHardware*, the PDO for the device still exists and can be queried for device information that is available in the powered off state, for example PCI configuration state.

In addition, the translated hardware resources that the framework supplies to *EvtDeviceReleaseHardware* are still assigned to the device. The primary purpose of this callback function is to release those resources, and in particular to unmap any memory resources that the driver's [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function mapped. The driver can also use this callback to perform any other driver or device management activity that might be required in the powered down state. Usually, all other hardware shutdown operations should take place in the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function.

The framework always calls the driver's *EvtDeviceReleaseHardware* callback function if the driver's [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function has been called, even if *EvtDevicePrepareHardware* returned a failure code.

A driver for a device that has child devices can control the order in which the framework calls the *EvtDeviceReleaseHardware* callback functions for the parent device and its children by calling [WdfDeviceInitSetReleaseHardwareOrderOnFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetreleasehardwareorderonfailure) from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about hardware resources, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

For more information about drivers that provide this callback function, see [Supporting PnP and Power Management in Function Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-pnp-and-power-management-in-function-drivers).

## See also

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)
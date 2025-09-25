# EVT_WDF_DEVICE_PREPARE_HARDWARE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDevicePrepareHardware* event callback function performs any operations that are needed to make a device accessible to the driver.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `ResourcesRaw` [in]

A handle to a framework resource-list object that identifies the raw hardware resources that the Plug and Play manager has assigned to the device.

### `ResourcesTranslated` [in]

A handle to a framework resource-list object that identifies the translated hardware resources that the Plug and Play manager has assigned to the device.

## Return value

If the *EvtDevicePrepareHardware* callback function encounters no errors, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise, it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**. Do not return STATUS_NOT_SUPPORTED.

If NT_SUCCESS(status) equals **FALSE**, the framework calls the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

To register an *EvtDevicePrepareHardware* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

If the driver has registered an *EvtDevicePrepareHardware* callback function for a device, the framework calls the function after the Plug and Play manager has assigned hardware resources to the device and after the device has entered its uninitialized D0 state. (The Plug and Play manager always starts a parent device before it starts that device's child devices.)

The framework calls the driver's *EvtDevicePrepareHardware* callback function before calling the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function.

The *EvtDevicePrepareHardware* callback function accesses the device's raw and translated hardware resources by using the *ResourcesRaw* and *ResourcesTranslated* handles that it receives. The callback function can call [WdfCmResourceListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistgetcount) and [WdfCmResourceListGetDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistgetdescriptor) to traverse the resource lists. This callback function cannot modify the resource lists.

For more information about resource lists and the order in which the resources appear, see [raw and translated hardware resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources).

Typically, your driver's *EvtDevicePrepareHardware* callback function does the following, if necessary:

* Maps physical memory addresses to virtual addresses so the driver can access memory that is assigned to the device
* Determines the device's revision number
* Configures USB devices
* Obtains [driver-defined interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces) from other drivers

Optionally, your driver's *EvtDevicePrepareHardware* callback function might queue a work item to complete any other time-intensive configuration tasks. Using a work item for such operations can help ensure that your device's start up time does not increase the system boot time. For more information, see [Using Framework Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

Typically, all other hardware initialization operations, including loading firmware, should take place each time that the device enters its working (D0) state and should therefore take place in the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function.

The *ResourcesRaw* and *ResourcesTranslated* handles that the *EvtDevicePrepareHardware* callback function receives remain valid until the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function returns.

For more information about hardware resources, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about drivers that provide this callback function, see [Supporting PnP and Power Management in Function Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-pnp-and-power-management-in-function-drivers).

## See also

[EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware)
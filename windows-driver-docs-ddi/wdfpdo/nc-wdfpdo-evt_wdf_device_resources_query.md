# EVT_WDF_DEVICE_RESOURCES_QUERY callback function

## Description

[Applies to KMDF only]

A bus driver's *EvtDeviceResourcesQuery* event callback function creates a resource list that represents a specified device's [boot configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Resources` [in]

A handle to a framework resource-list object that represents an empty resource list.

## Return value

If the driver did not encounter any errors, it must return STATUS_SUCCESS (whether or not it specifies boot configuration resources). If the driver encounters errors, it must return an NTSTATUS value that [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) evaluates as **FALSE**.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

Framework-based bus drivers can provide an *EvtDeviceResourcesQuery* callback function. To register this callback function, bus drivers call [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

The framework calls the bus driver's *EvtDeviceResourcesQuery* callback function to obtain a [resource list](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) that specifies the boot configuration for the device.

The driver must populate the supplied resource list object with hardware resources that represent the boot requirements for the device. Drivers for PnP devices obtain this requirements information from the system BIOS.

To create a resource list, the driver calls [framework resource-list object methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/) that add resources to the resource-list object that is represented by the *Resources* parameter.For more information about hardware resources and creating resource lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

## See also

[EvtDeviceResourceRequirementsQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resource_requirements_query)
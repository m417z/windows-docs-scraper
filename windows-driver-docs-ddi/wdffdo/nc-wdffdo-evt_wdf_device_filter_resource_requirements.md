# EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS callback function

## Description

[Applies to KMDF only]

A driver's *EvtDeviceFilterAddResourceRequirements* event callback function can add resources to a set of hardware resource requirements before the system assigns resources to a device.

A driver's [EvtDeviceFilterRemoveResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements) event callback function can remove resources from a set of hardware resource requirements before the system assigns resources to a device.

## Parameters

### `Device` [in]

A handle to the framework device object to which resources will be assigned.

### `IoResourceRequirementsList` [in]

A handle to a resource-requirements-list object, which represents the device's [resource requirements list](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Return value

If the driver encountered no errors it must return STATUS_SUCCESS. Otherwise it must return an NTSTATUS value that [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) evaluates as **FALSE**.

For more information about return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

Framework-based function drivers can provide an *EvtDeviceFilterAddResourceRequirements* and an [EvtDeviceFilterRemoveResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements)callback function. To register these callback functions, drivers call [WdfFdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitseteventcallbacks).

When the framework calls a driver's *EvtDeviceFilterAddResourceRequirements* callback function, the driver can add resource descriptors to a logical configuration, and it can provide additional logical configurations. These added items represent resources that the function driver requires to make the device operational.

If a driver's *EvtDeviceFilterAddResourceRequirements* callback function adds items to a device's resource requirements list, and if the PnP manager assigns the resources to the device's requirements list, the driver's [EvtDeviceRemoveAddedResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_remove_added_resources) callback function must remove the added resources from the device's resource list.

To add items to or remove items from a resource requirements list, the driver calls [framework resource-requirements-list object methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/) and framework resource-range-list object methods, which manipulates the resource-requirements-list object that is represented by the *IoResourceRequirementsList* parameter.

For more information about these callback functions, see [Modifying a Resource Requirements List](https://learn.microsoft.com/windows-hardware/drivers/wdf/modifying-a-resource-requirements-list).

For more information about hardware resources and resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

For information about modifying interrupt resources (for example processor affinity), see the Remarks section of [**WdfInterruptSetPolicy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy).

## See also

[EvtDeviceRemoveAddedResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_remove_added_resources)
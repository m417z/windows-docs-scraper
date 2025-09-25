# EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES callback function

## Description

[Applies to KMDF only]

A driver's *EvtDeviceRemoveAddedResources* event callback function removes hardware resources that the driver's [EvtDeviceFilterAddResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements) callback function added.

## Parameters

### `Device` [in]

A handle to the framework device object to which resources will be assigned.

### `ResourcesRaw` [in]

A handle to a resource list object that identifies the raw hardware resources that the PnP manager has assigned to the device.

### `ResourcesTranslated` [in]

A handle to a resource list object that identifies the translated hardware resources that the PnP manager has assigned to the device.

## Return value

If the driver encountered no errors it must return STATUS_SUCCESS. Otherwise it must return an NTSTATUS value that [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) evaluates as **FALSE**.

For more information about return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

Framework-based function drivers can provide an *EvtDeviceRemoveAddedResources* callback function. To register this callback function, drivers call [WdfFdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitseteventcallbacks).

If a driver provides an [EvtDeviceFilterAddResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements) callback function that adds resources to a device's hardware requirements list, the driver must also provide an *EvtDeviceRemoveAddedResources* callback function. The *EvtDeviceRemoveAddedResources* callback function examines the resource list that the PnP manager has assigned to the device, and removes the resources from the list that the *EvtDeviceFilterAddResourceRequirements* callback function added. If the driver removes a resource, it must remove it from both the raw and translated resource lists.

For more information about resource lists and the order in which the resources appear, see [raw and translated hardware resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources).

The framework calls the driver's *EvtDeviceRemoveAddedResources* callback function immediately before it passes the device's resource list to the bus driver. This callback function removes added resources so that the bus driver will not attempt to use them.

For more information about the *EvtDeviceRemoveAddedResources* callback function, see [Modifying a Resource List](https://learn.microsoft.com/windows-hardware/drivers/wdf/modifying-a-resource-list).

For more information about hardware resources, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

## See also

[EvtDeviceFilterAddResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements)

[EvtDeviceFilterRemoveResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements)
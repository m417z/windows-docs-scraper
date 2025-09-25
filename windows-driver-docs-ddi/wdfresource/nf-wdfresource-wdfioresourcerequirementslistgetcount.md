# WdfIoResourceRequirementsListGetCount function

## Description

[Applies to KMDF only]

The **WdfIoResourceRequirementsListGetCount** method returns the number of [logical configurations](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) that are contained in a resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

## Return value

**WdfIoResourceRequirementsListGetCount** returns the number of logical configurations that are contained in the resource requirements list.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example shows how an [EvtDeviceFilterRemoveResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements) callback function can obtain the number of logical configurations that are contained in a resource requirements list.

```cpp
NTSTATUS
Example_EvtDeviceFilterRemoveResourceRequirements(
    IN WDFDEVICE Device,
    IN WDFIORESREQLIST RequirementsList
    )
{
    ULONG count;

    count = WdfIoResourceRequirementsListGetCount(RequirementsList);
}
```
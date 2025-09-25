# WdfIoResourceRequirementsListAppendIoResList function

## Description

[Applies to KMDF only]

The **WdfIoResourceRequirementsListAppendIoResList** method adds a [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) to the end of a resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `IoResList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

## Return value

**WdfIoResourceRequirementsListAppendIoResList** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INVALID_DEVICE_REQUEST** | The specified resource-requirements-list object does not own the specified resource-range-list object. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate space to store the resource-range-list object. |

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example shows how an [EvtDeviceResourceRequirementsQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resource_requirements_query) callback function creates an empty logical configuration and appends it to a resource requirements list.

```cpp
NTSTATUS
Example_EvtDeviceResourceRequirementsQuery(
    IN WDFDEVICE Device,
    IN WDFIORESREQLIST RequirementsList
    )
{
    NTSTATUS  status;
    WDFIORESLIST  logConfig;

    status = WdfIoResourceListCreate(
                                     RequirementsList,
                                     WDF_NO_OBJECT_ATTRIBUTES,
                                     &logConfig
                                     );
    if (!NT_SUCCESS(status)) {
        return status;
    }

    status = WdfIoResourceRequirementsListAppendIoResList(
                                             RequirementsList,
                                             logConfig
                                             );
    if (!NT_SUCCESS(status)) {
        return status;
    }
...
}
```

## See also

[WdfIoResourceListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistcreate)

[WdfIoResourceRequirementsListInsertIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistinsertioreslist)
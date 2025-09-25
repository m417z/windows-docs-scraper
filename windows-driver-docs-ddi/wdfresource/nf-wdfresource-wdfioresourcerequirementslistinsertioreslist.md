# WdfIoResourceRequirementsListInsertIoResList function

## Description

[Applies to KMDF only]

The **WdfIoResourceRequirementsListInsertIoResList** method inserts a [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) into a resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `IoResList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

### `Index` [in]

A zero-based value that is used as an index into the set of logical configurations that are already in the resource requirements list that *RequirementsList* specifies. To add a configuration to the end of the list, specify WDF_INSERT_AT_END or the return value from [WdfIoResourceRequirementsListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistgetcount).

## Return value

**WdfIoResourceRequirementsListInsertIoResList** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter as specified. |
| **STATUS_INVALID_DEVICE_REQUEST** | The specified resource-requirements-list object does not own the specified resource-range-list object. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate space to store the resource-range-list object. |
| **STATUS_ARRAY_BOUNDS_EXCEEDED** | The specified value for the *Index* parameter was too large. |

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfIoResourceRequirementsListInsertIoResList** method inserts the logical configuration that the *IoResList* parameter specifies into the resource requirements list that the *RequirementsList* parameter specifies, in front of the logical configuration that the *Index* value identifies.

To add a logical configuration to the end of a resource requirements list, use WDF_INSERT_AT_END or the return value from [WdfIoResourceRequirementsListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistgetcount) as the *Index* value. Alternatively, use the [WdfIoResourceRequirementsListAppendIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistappendioreslist) method.

For more information about resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example shows how an [EvtDeviceResourceRequirementsQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resource_requirements_query) callback function can create two empty logical configurations and add them to a resource requirements list.

```cpp
NTSTATUS
Example_EvtDeviceResourceRequirementsQuery(
    IN WDFDEVICE Device,
    IN WDFIORESREQLIST RequirementsList
    )
{
    NTSTATUS  status;
    WDFIORESLIST  logConfig1;
    WDFIORESLIST  logConfig2;

    status = WdfIoResourceListCreate(
                                     RequirementsList,
                                     WDF_NO_OBJECT_ATTRIBUTES,
                                     &logConfig1
                                     );
    if (!NT_SUCCESS(status)) {
        return status;
    }

    status = WdfIoResourceRequirementsListAppendIoResList(
                                             RequirementsList,
                                             logConfig1
                                             );
    if (!NT_SUCCESS(status)) {
        return status;
    }

    status = WdfIoResourceListCreate(
                                     RequirementsList,
                                     WDF_NO_OBJECT_ATTRIBUTES,
                                     &logConfig2
                                     );
    if (!NT_SUCCESS(status)) {
        return status;
    }
    status = WdfIoResourceRequirementsListInsertIoResList(
                                             RequirementsList,
                                             logConfig2,
                                             WDF_INSERT_AT_END
                                             );
    if (!NT_SUCCESS(status)) {
        return status;
    }
...
}
```

## See also

[WdfIoResourceListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistcreate)

[WdfIoResourceRequirementsListAppendIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistappendioreslist)
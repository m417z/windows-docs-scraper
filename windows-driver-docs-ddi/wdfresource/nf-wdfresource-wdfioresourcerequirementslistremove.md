# WdfIoResourceRequirementsListRemove function

## Description

[Applies to KMDF only]

The **WdfIoResourceRequirementsListRemove** method removes a [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) from a resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `Index` [in]

A zero-based value that is used as an index into the resource requirements list that *RequirementsList* specifies.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfIoResourceRequirementsListRemove** method removes the logical configuration that is associated with the index value that the *Index* parameter specifies.

When **WdfIoResourceRequirementsListRemove** removes the logical configuration that has the index value *n*, the index value of the next logical configuration changes from *n*+1 to *n*.

For more information about resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example removes the second logical configuration from a resource requirements list.

```cpp
NTSTATUS
Example_EvtDeviceFilterRemoveResourceRequirements(
    IN WDFDEVICE Device,
    IN WDFIORESREQLIST RequirementsList
    )
{
...
    WdfIoResourceRequirementsListRemove(
                                        RequirementsList,
                                        1
                                        );
...
}
```

## See also

[WdfIoResourceRequirementsListRemoveByIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistremovebyioreslist)
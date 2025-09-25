# WdfIoResourceListCreate function

## Description

[Applies to KMDF only]

The **WdfIoResourceListCreate** method creates an empty [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources), which can be populated and added to a resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `Attributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new object. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `ResourceList` [out]

A handle to a framework resource-range-list object that represents the new logical configuration.

## Return value

**WdfIoResourceListCreate** returns STATUS_SUCCESS if the operation succeeds.

 For additional return values, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about resource requirements lists and logical configurations, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

The caller-specified resource-requirements-list object becomes the parent of the new resource-range-list object. The driver cannot change this parent, and the **ParentObject** member or the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**.

#### Examples

For a code example that uses **WdfIoResourceListCreate**, see [WdfIoResourceRequirementsListAppendIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistappendioreslist).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)
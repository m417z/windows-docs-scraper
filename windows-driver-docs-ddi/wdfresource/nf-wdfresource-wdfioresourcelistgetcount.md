# WdfIoResourceListGetCount function

## Description

[Applies to KMDF only]

The **WdfIoResourceListGetCount** method returns the number of resource descriptors that are contained in a resource requirements list's [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `ResourceList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

## Return value

**WdfIoResourceListGetCount** returns the number of resource descriptors that are contained in the logical configuration that *ResourceList* specifies.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about resource requirements lists and logical configurations, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

For a code example that uses **WdfIoResourceListGetCount**, see [WdfIoResourceRequirementsListGetIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistgetioreslist).

## See also

[WdfIoResourceRequirementsListGetIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistgetioreslist)
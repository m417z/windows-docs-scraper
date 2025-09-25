# WdfIoResourceListGetDescriptor function

## Description

[Applies to KMDF only]

The **WdfIoResourceListGetDescriptor** method returns a pointer to a resource descriptor that is contained in a resource requirements list's [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `ResourceList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

### `Index` [in]

A zero-based value that is used as an index into the logical configuration that *ResourceList* specifies.

## Return value

**WdfIoResourceListGetDescriptor** returns a pointer to the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure that describes the hardware resource that the *Index* parameter identifies, if the index value is valid. Otherwise, the method returns **NULL**.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver cannot modify the contents of the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure that **WdfIoResourceListGetDescriptor** retrieves. To modify a resource descriptor, the driver can call [WdfIoResourceListUpdateDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistupdatedescriptor).

For more information about resource requirements lists and logical configurations, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

For a code example that uses **WdfIoResourceListGetDescriptor**, see [WdfIoResourceRequirementsListGetIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistgetioreslist).

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[WdfIoResourceListUpdateDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistupdatedescriptor)
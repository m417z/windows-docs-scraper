# WdfCmResourceListGetDescriptor function

## Description

[Applies to KMDF and UMDF]

The **WdfCmResourceListGetDescriptor** method returns a pointer to a resource descriptor that is contained in a specified resource list.

## Parameters

### `List` [in]

A handle to a framework resource-list object that represents a list of hardware resources for a device.

### `Index` [in]

A zero-based value that is used as an index into the logical configuration that *List* specifies.

## Return value

**WdfCmResourceListGetDescriptor** returns a pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes the hardware resource that the *Index* parameter identifies, if the index value is valid. Otherwise, the method returns **NULL**.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver cannot modify the resource descriptor that **WdfCmResourceListGetDescriptor** retrieves.

For more information about resource lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

For a code example that uses **WdfCmResourceListGetDescriptor**, see [WdfCmResourceListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistgetcount).

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)
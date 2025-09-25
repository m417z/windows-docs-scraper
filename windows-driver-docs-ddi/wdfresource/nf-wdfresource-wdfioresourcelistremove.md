# WdfIoResourceListRemove function

## Description

[Applies to KMDF only]

The **WdfIoResourceListRemove** method removes a resource descriptor from a resource requirements list's [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `ResourceList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

### `Index` [in]

A zero-based value that is used as an index into the logical configuration that *ResourceList* specifies.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfIoResourceListRemove** method removes the resource descriptor that is associated with the index value that the *Index* parameter specifies.

When **WdfIoResourceListRemove** removes the resource descriptor that has the index value *n*, the index value of the next resource descriptor changes from *n*+1 to *n*.

For more information about resource requirements lists and logical configurations, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example removes the first resource descriptor from a logical configuration.

```cpp
WdfIoResourceListRemove(
                        Reslist,
                        0
                        );
```

## See also

[WdfIoResourceListRemoveByDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistremovebydescriptor)
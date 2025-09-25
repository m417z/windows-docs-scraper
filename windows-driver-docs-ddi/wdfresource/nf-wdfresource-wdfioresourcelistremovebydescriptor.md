# WdfIoResourceListRemoveByDescriptor function

## Description

[Applies to KMDF only]

The **WdfIoResourceListRemoveByDescriptor** method removes a resource descriptor from a resource requirement list's [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `ResourceList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

### `Descriptor` [in]

A pointer to an [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure that describes a hardware resource.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfIoResourceListRemoveByDescriptor** method removes the resource descriptor that matches the *Descriptor* parameter. To find a match, the method compares the specified resource descriptor with the resource descriptors in the logical configuration, byte for byte.

When **WdfIoResourceListRemoveByDescriptor** removes the resource descriptor that has the index value *n*, the index value of the next resource descriptor changes from *n*+1 to *n*.

For more information about resource requirements lists and logical configurations, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example searches a logical configuration for a resource descriptor that contains a specified port address, and it removes that resource descriptor.

```cpp
IO_RESOURCE_DESCRIPTOR descriptor;
ULONG resCount, j;

//
// Get the number of resource descriptors that
// are in this logical configuration.
//
resCount = WdfIoResourceListGetCount(reslist);

for (j = 0; j < resCount; j++) {
    PIO_RESOURCE_DESCRIPTOR descriptor;

    //
    // Get the next resource descriptor.
    //
    descriptor = WdfIoResourceListGetDescriptor(
                                                reslist,
                                                j
                                                );

    //
    // Stop if this descriptor is the port descriptor that
    // we're looking for, and remove the descriptor.
    //
    if (descriptor->Type == CmResourceTypePort) {
        if ((descriptor->u.port.MinimumAddress) == PORT_RANGE_A) {
               WdfIoResourceListRemoveByDescriptor(
                                                   Reslist,
                                                   descriptor
                                                   );
               break;
        }
    }
}
```

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[WdfIoResourceListRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistremove)
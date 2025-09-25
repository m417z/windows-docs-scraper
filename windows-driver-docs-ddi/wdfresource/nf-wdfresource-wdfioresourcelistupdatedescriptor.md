# WdfIoResourceListUpdateDescriptor function

## Description

[Applies to KMDF only]

The **WdfIoResourceListUpdateDescriptor** method updates a resource descriptor in a resource requirements list's [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `ResourceList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

### `Descriptor` [in]

A pointer to an [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure that describes a hardware resource.

### `Index` [in]

A zero-based value that is used as an index into the set of resource descriptors that are already in the logical configuration that *ResourceList* specifies.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfIoResourceListUpdateDescriptor** method locates the resource descriptor that the *Index* parameter identifies. Then the method copies the resource descriptor that the *Descriptor* parameter specifies into the descriptor that *Index* specifies.

For more information about resource requirements lists and logical configurations, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example initializes a new resource descriptor and then calls **WdfIoResourceListUpdateDescriptor** to replace the second descriptor in a logical configuration with the new descriptor.

```cpp
IO_RESOURCE_DESCRIPTOR newDescriptor;

RtlZeroMemory(
              &newDescriptor,
              sizeof(newDescriptor)
              );

newDescriptor.Option = 0;
newDescriptor.Type = CmResourceTypePort;
newDescriptor.ShareDisposition = CmResourceShareDeviceExclusive;
newDescriptor.Flags = CM_RESOURCE_PORT_IO|CM_RESOURCE_PORT_16_BIT_DECODE;
newDescriptor.u.Port.Length = 1;
newDescriptor.u.Port.Alignment = 0x01;
newDescriptor.u.Port.MinimumAddress.QuadPart = 0;
newDescriptor.u.Port.MaximumAddress.QuadPart = 0xFFFF;

WdfIoResourceListUpdateDescriptor(
                                  Reslist,
                                  &newDescriptor,
                                  1
                                  );
```

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)
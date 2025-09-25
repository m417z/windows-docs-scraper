# WdfIoResourceListInsertDescriptor function

## Description

[Applies to KMDF only]

The **WdfIoResourceListInsertDescriptor** method inserts a resource descriptor into a resource requirements list's [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `ResourceList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

### `Descriptor` [in]

A pointer to an [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure that describes a hardware resource.

### `Index` [in]

A zero-based value that is used as an index into the set of resource descriptors that are already in the logical configuration that *ResourceList* specifies. To add a resource descriptor to the end of the logical configuration, specify WDF_INSERT_AT_END or the return value from [WdfIoResourceListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistgetcount).

## Return value

**WdfIoResourceListInsertDescriptor** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_ACCESS_DENIED** | The driver was not allowed to add descriptors to the logical configuration. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate space to store the descriptor. |
| **STATUS_ARRAY_BOUNDS_EXCEEDED** | The value that the *Index* parameter specifies was too large. |

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfIoResourceListInsertDescriptor** method inserts the resource descriptor that the *Descriptor* parameter points to into the logical configuration that the *ResourceList* parameter specifies, in front of the resource descriptor that the *Index* value identifies.

To add a resource descriptor to the end of a logical configuration, specify WDF_INSERT_AT_END or the return value from [WdfIoResourceListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistgetcount) for the *Index* value. Alternatively, use the [WdfIoResourceListAppendDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistappenddescriptor) method.

The framework copies the contents of the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure into internal storage, so the driver routine that calls **WdfIoResourceListInsertDescriptor** can allocate the structure locally. After the driver calls **WdfIoResourceListInsertDescriptor**, the driver can reuse the **IO_RESOURCE_DESCRIPTOR** structure.

For more information about resource requirements lists and logical configurations, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example initializes a resource descriptor and adds the descriptor to the end of a logical configuration.

```cpp
IO_RESOURCE_DESCRIPTOR descriptor;

RtlZeroMemory(&descriptor, sizeof(descriptor));

descriptor.Option = 0;
descriptor.Type = CmResourceTypePort;
descriptor.ShareDisposition = CmResourceShareDeviceExclusive;
descriptor.Flags = CM_RESOURCE_PORT_IO|CM_RESOURCE_PORT_16_BIT_DECODE;
descriptor.u.Port.Length = 1;
descriptor.u.Port.Alignment = 0x01;
descriptor.u.Port.MinimumAddress.QuadPart = 0;
descriptor.u.Port.MaximumAddress.QuadPart = 0xFFFF;

status = WdfIoResourceListInsertDescriptor(
                                           logConfig,
                                           &descriptor,
                                           WDF_INSERT_AT_END
                                           );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[WdfIoResourceListAppendDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistappenddescriptor)
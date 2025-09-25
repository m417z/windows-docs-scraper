# WdfIoResourceListAppendDescriptor function

## Description

[Applies to KMDF only]

The **WdfIoResourceListAppendDescriptor** method adds a resource descriptor to the end of a resource requirements list's [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Parameters

### `ResourceList` [in]

A handle to a framework resource-range-list object that represents a logical configuration of hardware resources for a device.

### `Descriptor` [in]

A pointer to an [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure that describes a hardware resource.

## Return value

**WdfIoResourceListAppendDescriptor** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_ACCESS_DENIED** | The driver was not allowed to add descriptors to the logical configuration that the *ResourceList* parameter specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate space to store the descriptor. |

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

The framework copies the contents of the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure that the *Descriptor* parameter points to into internal storage, so the driver routine that calls **WdfIoResourceListAppendDescriptor** can allocate the structure locally. After the driver calls **WdfIoResourceListAppendDescriptor**, the driver can reuse the **IO_RESOURCE_DESCRIPTOR** structure.

For more information about resource requirements lists and logical configurations, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example creates an empty logical configuration and adds it to a resource requirements list. Then, the example initializes a resource descriptor and adds the descriptor to the logical configuration.

```cpp
IO_RESOURCE_DESCRIPTOR  descriptor;
NTSTATUS  status;
WDFIORESLIST  logConfig;

status = WdfIoResourceListCreate(
                                 RequirementsList,
                                 WDF_NO_OBJECT_ATTRIBUTES,
                                 &logConfig
                                 );
if (!NT_SUCCESS(status)) {
    return status;
}

status = WdfIoResourceRequirementsListAppendIoResList(
                                                      RequirementsList,
                                                      logConfig
                                                      );
if (!NT_SUCCESS(status)) {
    return status;
}

RtlZeroMemory(
              &descriptor,
              sizeof(descriptor)
              );

descriptor.Option = 0;
descriptor.Type = CmResourceTypePort;
descriptor.ShareDisposition = CmResourceShareDeviceExclusive;
descriptor.Flags = CM_RESOURCE_PORT_IO|CM_RESOURCE_PORT_16_BIT_DECODE;
descriptor.u.Port.Length = 1;
descriptor.u.Port.Alignment = 0x01;
descriptor.u.Port.MinimumAddress.QuadPart = 0;
descriptor.u.Port.MaximumAddress.QuadPart = 0xFFFF;

status = WdfIoResourceListAppendDescriptor(
                                           logConfig,
                                           &descriptor
                                           );
```

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[WdfIoResourceListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistcreate)

[WdfIoResourceListInsertDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistinsertdescriptor)
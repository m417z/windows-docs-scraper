# _WDF_MEMORY_DESCRIPTOR_TYPE enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_MEMORY_DESCRIPTOR_TYPE** enumeration identifies the types of memory descriptions that a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure can specify.

## Constants

### `WdfMemoryDescriptorTypeInvalid:0`

Reserved for internal use only.

### `WdfMemoryDescriptorTypeBuffer`

The [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure contains a buffer description.

### `WdfMemoryDescriptorTypeMdl`

The [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure contains a memory descriptor list (MDL).

### `WdfMemoryDescriptorTypeHandle`

The [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure contains a handle to a memory object.

## See also

[WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor)
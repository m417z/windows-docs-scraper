# _WDF_MEMORY_DESCRIPTOR structure

## Description

[Applies to KMDF and UMDF]

The **WDF_MEMORY_DESCRIPTOR** structure describes a memory buffer.

## Members

### `Type`

A [WDF_MEMORY_DESCRIPTOR_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ne-wdfmemory-_wdf_memory_descriptor_type)-typed value that identifies the type of buffer description that this **WDF_MEMORY_DESCRIPTOR** structure contains.

### `u`

A union of three structures, one of which describes a buffer.

### `u.BufferType`

If the **Type** member is **WdfMemoryDescriptorTypeBuffer**, the members of the **BufferType** structure describe a buffer. This structure contains the following two members:

### `u.BufferType.Buffer`

A pointer to a buffer.

### `u.BufferType.Length`

The length, in bytes, of the buffer.

### `u.MdlType`

If the **Type** member is **WdfMemoryDescriptorTypeMdl**, the members of the **MdlType** structure describe a buffer. This structure contains the following two members:

### `u.MdlType.Mdl`

A pointer to a memory descriptor list (MDL).

### `u.MdlType.BufferLength`

The length, in bytes, of the buffer.

### `u.HandleType`

If the **Type** member is **WdfMemoryDescriptorTypeHandle**, the members of the **HandleType** structure describe a buffer. This structure contains the following two members:

### `u.HandleType.Memory`

A handle to a framework memory object.

### `u.HandleType.Offsets`

A pointer to a [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that describes a subsection of the buffer that is represented by the memory object.

## Remarks

The **WDF_MEMORY_DESCRIPTOR** structure is used as input to several of the framework's [I/O target object methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/) and [USB device object methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/).

To initialize a **WDF_MEMORY_DESCRIPTOR** structure, your driver should call [WDF_MEMORY_DESCRIPTOR_INIT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_buffer), or [WDF_MEMORY_DESCRIPTOR_INIT_MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_mdl), or [WDF_MEMORY_DESCRIPTOR_INIT_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_handle).

## See also

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WDF_MEMORY_DESCRIPTOR_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ne-wdfmemory-_wdf_memory_descriptor_type)
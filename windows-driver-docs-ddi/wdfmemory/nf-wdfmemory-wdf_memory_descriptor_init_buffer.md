# WDF_MEMORY_DESCRIPTOR_INIT_BUFFER function

## Description

[Applies to KMDF and UMDF]

The **WDF_MEMORY_DESCRIPTOR_INIT_BUFFER** function initializes a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure so that it describes a specified buffer.

## Parameters

### `Descriptor` [out]

A pointer to a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure.

### `Buffer` [in]

A pointer to a memory buffer.

### `BufferLength` [in]

The size, in bytes, of the memory buffer that *Buffer* points to.

## Remarks

The **WDF_MEMORY_DESCRIPTOR_INIT_BUFFER** function zeros the specified [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure and sets the structure's **Type** member to **WdfMemoryDescriptorTypeBuffer**. Then it sets the structure's **u.BufferType.Buffer** and **u.BufferType.Length** members to the values that the *Buffer* and *BufferLength* parameters specify, respectively.

#### Examples

For a code example that uses **WDF_MEMORY_DESCRIPTOR_INIT_BUFFER**, see [WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously).

## See also

[WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor)

[WDF_MEMORY_DESCRIPTOR_INIT_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_handle)

[WDF_MEMORY_DESCRIPTOR_INIT_MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_mdl)
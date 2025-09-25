# WDF_MEMORY_DESCRIPTOR_INIT_MDL function

## Description

[Applies to KMDF and UMDF]

The **WDF_MEMORY_DESCRIPTOR_INIT_MDL** function initializes a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure so that it describes a specified memory descriptor list (MDL).

## Parameters

### `Descriptor` [out]

A pointer to a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure.

### `Mdl` [in]

A pointer to an MDL that describes a buffer.

### `BufferLength` [in]

The size, in bytes, of the buffer that *Mdl* specifies.

## Remarks

The **WDF_MEMORY_DESCRIPTOR_INIT_MDL** function zeros the specified [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure and sets the structure's **Type** member to **WdfMemoryDescriptorTypeMdl**. Then it sets the structure's **u.MdlType.Mdl** and **u.MdlType.BufferLength** members to the values that the *Mdl* and *BufferLength* parameters specify, respectively.

#### Examples

The following code example allocates a buffer, creates an MDL for the buffer, and uses the MDL to initialize a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure.

```cpp
PVOID  pBuffer = NULL;
PMDL  pMdl = NULL;

pBuffer = ExAllocatePoolWithTag(
                                NonPagedPool,
                                BUFFER_LENGTH,
                                IOTARGET_DRIVER_TAG
                                );
if (pBuffer == NULL){
    Status = STATUS_UNSUCCESSFUL;
    goto Cleanup;
}
pMdl = IoAllocateMdl(
                     pBuffer,
                     BUFFER_LENGTH,
                     FALSE,
                     TRUE,
                     NULL
                     );
if (pMdl == NULL){
    Status = STATUS_UNSUCCESSFUL;
    goto Cleanup;
}
MmBuildMdlForNonPagedPool(pMdl);
WDF_MEMORY_DESCRIPTOR_INIT_MDL(
                               pInputBuffer,
                               pMdl,
                               BUFFER_LENGTH
                               );
```

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl)

[MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool)

[WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor)

[WDF_MEMORY_DESCRIPTOR_INIT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_buffer)

[WDF_MEMORY_DESCRIPTOR_INIT_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_handle)
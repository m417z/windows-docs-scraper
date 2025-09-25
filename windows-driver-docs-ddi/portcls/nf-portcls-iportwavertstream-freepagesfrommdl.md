# IPortWaveRTStream::FreePagesFromMdl

## Description

The `FreePagesFromMdl` method frees a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)).

## Parameters

### `MemoryDescriptorList` [in]

Pointer to the MDL.

## Remarks

The miniport driver must call this method to free an MDL that was previously allocated by calling either [IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl) or [IPortWaveRTStream::AllocateContiguousPagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatecontiguouspagesformdl).

`FreePagesFromMdl` frees both the physical memory pages described in the MDL and the MDL itself. On return, the MDL pointer value in the *MemoryDescriptorList* parameter is no longer valid.

## See also

[IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream)

[IPortWaveRTStream::AllocateContiguousPagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatecontiguouspagesformdl)

[IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl)
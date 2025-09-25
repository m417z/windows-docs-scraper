# IPortWaveRTStream::GetPhysicalPagesCount

## Description

The `GetPhysicalPagesCount` method returns the count of the physical pages in a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)).

## Parameters

### `MemoryDescriptorList` [in]

Pointer to the MDL.

## Return value

`GetPhysicalPagesCount` method returns the count of physical pages in the MDL.

## Remarks

The miniport driver uses this call to determine the number of physical pages that are contained within an MDL. The count is typically used in the process of programming the DMA hardware.

## See also

[IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream)

[IPortWaveRTStream::AllocateContiguousPagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatecontiguouspagesformdl)

[IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl)

[IPortWaveRTStream::GetPhysicalPageAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-getphysicalpageaddress)
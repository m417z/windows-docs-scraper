# IPortWaveRTStream::GetPhysicalPageAddress

## Description

The `GetPhysicalPageAddress` method returns the physical address for a page within a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)).

## Parameters

### `MemoryDescriptorList` [in]

Pointer to the MDL.

### `Index` [in]

Index to the target page within the MDL.

## Return value

The `GetPhysicalPageAddress` method returns the physical address for a page within an MDL.

## Remarks

The miniport driver calls this method to determine the physical memory address for pages within an MDL that was previously allocated by calling either [IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl) or **IPortWaveRTStream::AllocateContiguousPagesForMdl**.

The miniport typically calls this for each page in the MDL in order to program the physical address into the DMA. The *Index* parameter is used to select the desired page, and can range from zero to the count returned by [GetPhysicalPagesCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-getphysicalpagescount).

## See also

[IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream)

[IPortWaveRTStream::AllocateContiguousPagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatecontiguouspagesformdl)

[IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl)

[IPortWaveRTStream::GetPhysicalPagesCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-getphysicalpagescount)
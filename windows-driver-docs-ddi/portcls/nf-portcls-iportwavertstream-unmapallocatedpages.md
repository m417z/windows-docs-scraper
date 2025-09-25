# IPortWaveRTStream::UnmapAllocatedPages

## Description

The `UnmapAllocatedPages` method releases a mapping.

## Parameters

### `BaseAddress` [in]

Pointer to the base virtual address to which the physical pages were mapped.

### `MemoryDescriptorList` [in]

Pointer to a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)) that describes the physical pages.

## Remarks

The miniport driver must call this method to release a mapping that was set up by a previous call to [IPortWaveRTStream::MapAllocatedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-mapallocatedpages). The driver must release the mapping before calling [IPortWaveRTStream::FreePagesFromMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-freepagesfrommdl)  to free the MDL.

This method is similar in operation to the [MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages) function.

## See also

[IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream)

[IPortWaveRTStream::FreePagesFromMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-freepagesfrommdl)

[IPortWaveRTStream::MapAllocatedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-mapallocatedpages)

[MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages)
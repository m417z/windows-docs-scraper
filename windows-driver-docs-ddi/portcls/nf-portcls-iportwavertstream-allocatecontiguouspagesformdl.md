# IPortWaveRTStream::AllocateContiguousPagesForMdl

## Description

The `AllocateContiguousPagesForMdl` method allocates a list of contiguous, nonpaged, physical memory pages and returns a pointer to a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)) that describes them.

## Parameters

### `LowAddress` [in]

Specifies the low end of the address range from which the storage for the MDL can be allocated.

### `HighAddress` [in]

Specifies the high end of the address range from which the storage for the MDL can be allocated.

### `TotalBytes` [in]

Specifies the total number of bytes to allocate for the MDL. This method always allocates an integral number of memory pages.

## Return value

`AllocateContiguousPagesForMdl` returns a pointer to an MDL (PMDL) that describes a list of physical memory pages. If the method is unable to allocate the requested buffer, it returns **NULL**.

## Remarks

The driver calls this method to allocate a block of physically contiguous memory pages. All of the physical memory pages in the MDL fall within the address range specified by the *LowAddress* and *HighAddress* parameters. If sufficient memory is available, the memory allocation is the requested size rounded up to the next page; otherwise, the call fails.

After a system has been running for some time, the system's pool of nonpaged memory tends to become fragmented, which increases the probability that a request to allocate a large block of contiguous physical memory will fail. If the DMA controller of the audio device does not require the physical memory pages to be contiguous, the driver must call [IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl) instead. Unlike `AllocateContiguousPagesForMdl`, the **AllocatePagesForMdl** method is not affected by memory fragmentation.

The `AllocateContiguousPagesforMdl` method allocates memory pages that are locked (nonpaged) but unmapped. If the miniport driver requires software access to this memory, the miniport driver must make a subsequent call to [IPortWaveRTStream::MapAllocatedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-mapallocatedpages) to map the pages into kernel-mode address space.

## See also

[IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream)

[IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl)

[IPortWaveRTStream::MapAllocatedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-mapallocatedpages)
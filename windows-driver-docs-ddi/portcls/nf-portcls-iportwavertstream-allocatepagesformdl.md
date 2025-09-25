# IPortWaveRTStream::AllocatePagesForMdl

## Description

The `AllocatePagesForMdl` method allocates a list of nonpaged physical memory pages and returns a pointer to a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)) that describes them.

## Parameters

### `HighAddress` [in]

Specifies the high end of the address range from which the storage for the MDL can be allocated. The low end of the address range is implicitly zero.

### `TotalBytes` [in]

Specifies the total number of bytes to allocate for the MDL. This method always allocates an integral number of memory pages.

## Return value

`AllocatePagesforMdl` returns a pointer to an MDL that describes a list of physical memory pages. If the method is unable to allocate the requested buffer, it returns **NULL**.

## Remarks

Since the Windows audio stack does not support a mechanism to express memory access alignment requirements for buffers, audio drivers must select a caching type for mapped memory buffers that does not impose platform-specific alignment requirements. In other words, the caching type used by the audio driver for mapped memory buffers, must not make assumptions about the memory alignment requirements for any specific platform.

The driver calls this method to allocate memory that can be mapped to user or kernel mode. The physical memory pages in the MDL are not necessarily contiguous in physical memory, but they all fall within the specified address range.

The method always allocates an integral number of pages. If sufficient memory is available, the memory allocation is the requested size rounded up to the next page. Otherwise, the memory allocation can be less than the requested size. The caller must verify how many bytes are actually allocated.

If the DMA controller of the audio device requires the physical memory pages in the buffer to be contiguous, the driver must call [IPortWaveRTStream::AllocateContiguousPagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatecontiguouspagesformdl)  instead.

Like the [MmAllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl)  function, the `AllocatePagesforMdl` method allocates memory pages that are locked (nonpaged) but unmapped. If the miniport driver wants to set up software access to this memory, the miniport driver must make a subsequent call to [IPortWaveRTStream::MapAllocatedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-mapallocatedpages)  to map the pages into kernel-mode address space.

## See also

[IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream)

[IPortWaveRTStream::AllocateContiguousPagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatecontiguouspagesformdl)

[IPortWaveRTStream::MapAllocatedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-mapallocatedpages)
# IPortWaveRTStream::MapAllocatedPages

## Description

The `MapAllocatedPages` method maps a list of previously allocated physical pages into a contiguous block of virtual memory that is accessible from kernel-mode.

## Parameters

### `MemoryDescriptorList` [in]

Pointer to the memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)) that will be mapped. The MDL can be allocated by calling either [IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl)  or [IPortWaveRTStream::AllocateContiguousPagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatecontiguouspagesformdl).

### `CacheType` [in]

Specifies the cache type. Set this parameter to one of the following [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) enumeration values: **MmNonCached**, **MmCached**, or **MmWriteCombined**.

## Return value

`MapAllocatedPages` returns the starting address of the mapped buffer in virtual memory. If the method is unable to map the buffer, it returns **NULL**.

## Remarks

Since the Windows audio stack does not support a mechanism to express memory access alignment requirements for buffers, audio drivers must select a caching type for mapped memory buffers that does not impose platform-specific alignment requirements. In other words, the caching type used by the audio driver for mapped memory buffers, must not make assumptions about the memory alignment requirements for any specific platform.

This method maps the physical memory pages in the MDL into kernel-mode virtual memory. Typically, the miniport driver calls this method if it requires software access to the scatter-gather list for an audio buffer. In this case, the storage for the scatter-gather list must have been allocated by the **IPortWaveRTStream::AllocatePagesForMdl** or **IPortWaveRTStream::AllocateContiguousPagesForMdl** method.

A WaveRT miniport driver should not require software access to the audio buffer itself.

`MapAllocatedPages` is similar in operation to the [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache) function. The miniport driver is responsible for unmapping the memory prior to freeing it. For more information, see [IPortWaveRTStream::UnmapAllocatedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-unmapallocatedpages).

## See also

[IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream)

[IPortWaveRTStream::AllocateContiguousPagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatecontiguouspagesformdl)

[IPortWaveRTStream::AllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-allocatepagesformdl)

[IPortWaveRTStream::UnmapAllocatedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavertstream-unmapallocatedpages)

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type)

[MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)
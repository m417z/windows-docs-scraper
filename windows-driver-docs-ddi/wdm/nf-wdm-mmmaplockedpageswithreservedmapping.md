# MmMapLockedPagesWithReservedMapping function

## Description

The **MmMapLockedPagesWithReservedMapping** routine maps all or part of an address range that was previously reserved by the [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress) routine.

## Parameters

### `MappingAddress` [in]

Pointer to the beginning of the reserved virtual memory range. This must be an address previously returned by [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress).

### `PoolTag` [in]

Specifies the pool tag for the reserved memory buffer. This must be identical to the value specified in the *PoolTag* parameter of the call to [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress) that reserved the buffer.

### `MemoryDescriptorList` [in]

A pointer to the MDL that is to be mapped. This MDL must describe physical pages that are locked down. A locked-down MDL can be built by the [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages) or [MmAllocatePagesForMdlEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex) routine.

### `CacheType` [in]

Specifies the [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) value to use to create the mapping.

## Return value

**MmMapLockedPagesWithReservedMapping** returns a pointer to the beginning of the mapped memory, or **NULL** if the system could not map the memory. This routine returns **NULL** only if there is an error in the function parameters (for example, the driver's mapping address is not large enough to span the supplied MDL). This function is intended to enable drivers to make forward progress even in low-resource scenarios.

## Remarks

The caller can use **MmMapLockedPagesWithReservedMapping** to map a subrange of the virtual memory range reserved by [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress) as follows:

- Use [IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl) to allocate an MDL. The returned MDL is built using the specified starting address and size of the subrange of the virtual memory range to map.

- Use [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages) to lock down the physical pages described by the MDL obtained in step 1.

- Use **MmMapLockedPagesWithReservedMapping** to actually map the virtual memory to the physical memory that was locked down in step 2. Note that the virtual address returned by this function does include the byte offset that the MDL specifies. However, the **MappedSystemVa** field of the MDL that is set by this function does not include the byte offset.

- Once the caller does not need to access the memory, it unmaps the memory with [MmUnmapReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapreservedmapping). The caller can map and unmap the memory buffer as needed, and must unmap it prior to freeing the mapping range with [MmFreeMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreemappingaddress).

Note that the *MappingAddress* parameter specifies the beginning of the range of memory previously reserved by the caller, not the beginning of the memory subrange to be mapped. The caller specifies the starting address and length of the buffer when it allocates the MDL with [IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl). The buffer must fit inside the reserved memory range, but it can be a strict subset.

The routine uses the *CacheType* parameter only if the pages that are described by the MDL do not already have a cache type associated with them. However, in nearly all cases, the pages already have an associated cache type, and this cache type is used by the new mapping. An exception to this rule is for pages that are allocated by [MmAllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl), which do not have a specific cache type associated with them. For such pages, the *CacheType* parameter determines the cache type of the mapping.

## See also

[IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl)

[MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type)

[MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress)

[MmAllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl)

[MmAllocatePagesForMdlEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex)

[MmFreeMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreemappingaddress)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

[MmUnmapReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapreservedmapping)
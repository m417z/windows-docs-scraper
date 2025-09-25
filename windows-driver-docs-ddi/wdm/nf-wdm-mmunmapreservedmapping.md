# MmUnmapReservedMapping function

## Description

The **MmUnmapReservedMapping** routine unmaps a memory buffer that was mapped by the [MmMapLockedPagesWithReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping) routine.

## Parameters

### `BaseAddress` [in]

Pointer to the beginning of the reserved virtual memory range. This must be an address returned by [MmMapLockedPagesWithReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping).

### `PoolTag` [in]

Specifies the pool tag for the reserved memory buffer. This must be identical to the value specified in the *PoolTag* parameter of the call to [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress) that initially reserved the buffer.

### `MemoryDescriptorList` [in]

Pointer to the MDL that describes the physical memory mapping.

## See also

[MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress)

[MmFreeMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreemappingaddress)

[MmMapLockedPagesWithReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping)
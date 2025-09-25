# MmFreeMappingAddress function

## Description

The **MmFreeMappingAddress** routine frees a range of virtual memory reserved by the [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress) routine.

## Parameters

### `BaseAddress` [in]

Pointer to the beginning of the reserved memory buffer to free. This must be an address previously returned by [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress).

### `PoolTag` [in]

Specifies the pool tag for the reserved memory buffer. This must be identical to the value specified in the *PoolTag* parameter of the call to [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress) that reserved the buffer.

## Remarks

**MmFreeMappingAddress** frees a range of memory reserved by [MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress). If the memory range has already been mapped by [MmMapLockedPagesWithReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping), it must first be unmapped with [MmUnmapReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapreservedmapping) before the memory range can be freed.

## See also

[MmAllocateMappingAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress)

[MmMapLockedPagesWithReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping)

[MmUnmapReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapreservedmapping)
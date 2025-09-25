# _MEMORY_CACHING_TYPE enumeration (miniport.h)

## Description

The **MEMORY_CACHING_TYPE** enumeration type specifies the permitted caching behavior when allocating or mapping memory.

## Constants

### `MmNonCached`

The requested memory should not be cached by the processor.

### `MmCached`

The processor should cache the requested memory.

### `MmWriteCombined`

The requested memory should not be cached by the processor, but writes to the memory can be combined by the processor.

### `MmHardwareCoherentCached`

Reserved for system use.

### `MmNonCachedUnordered`

Reserved for system use.

### `MmUSWCCached`

Reserved for system use.

### `MmMaximumCacheType`

Reserved for system use.

### `MmNotMapped`

## Remarks

Processor translation buffers cache virtual to physical address translations. These translation buffers allow many virtual addresses to map a single physical address. However, only one caching behavior is allowed for any given physical address translation. Therefore, if a driver maps two different virtual address ranges to the same physical address, it must ensure that it specifies the same caching behavior for both. Otherwise, the processor behavior is undefined with unpredictable system results.

## See also

[MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache)

[MmFreeContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemoryspecifycache)

[MmMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapiospace)

[MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)

[MmMapLockedPagesWithReservedMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping)
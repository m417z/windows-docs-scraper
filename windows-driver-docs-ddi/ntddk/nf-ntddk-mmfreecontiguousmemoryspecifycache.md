# MmFreeContiguousMemorySpecifyCache function (ntddk.h)

## Description

The **MmFreeContiguousMemorySpecifyCache** routine frees a buffer that was allocated by an **MmAllocateContiguousMemorySpecifyCache*Xxx*** routine.

## Parameters

### `BaseAddress` [in]

Specifies the base address of the buffer to be freed. Must match the address returned by the **MmAllocateContiguousMemorySpecifyCache*Xxx*** call that allocated the buffer.

### `NumberOfBytes` [in]

Specifies the size in bytes of the buffer to be freed. Must match the size requested when the buffer was allocated by the **MmAllocateContiguousMemorySpecifyCache*Xxx*** routine.

### `CacheType` [in]

Specifies the cache type of the buffer to be freed. Must match the cache type requested when the buffer was allocated by the **MmAllocateContiguousMemorySpecifyCache*Xxx*** routine.

## Remarks

The **MmFreeContiguousMemorySpecifyCache** routine frees a block of physically contiguous memory that was allocated by a previous call to the [MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache) or [MmAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycachenode) routine. However, [MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory) is the preferred routine to use to free memory that was allocated by an **MmAllocateContiguousMemorySpecifyCache*Xxx*** routine. **MmFreeContiguousMemory** is faster than **MmFreeContiguousMemorySpecifyCache** and requires fewer parameters.

## See also

[MmAllocateContiguousMemorySpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycache)

[MmAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatecontiguousmemoryspecifycachenode)

[MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory)
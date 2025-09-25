# NdisFreeMemory function

## Description

The
**NdisFreeMemory** function releases a block of memory that was previously allocated with the
[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) function.

## Parameters

### `VirtualAddress` [in]

A pointer to the base virtual address of the allocated memory. This address was returned by the
[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) function.

### `Length` [in]

The size, in bytes, of the memory block to be released. If the memory was allocated with [NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) or the *MemoryFlags* parameter is zero, this parameter is ignored.

### `MemoryFlags` [in]

A set of flags that specify the type of memory to free. This value must be zero if the memory was
allocated with
[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority). With NDIS 6.0 and later versions, the
**NdisAllocateMemoryWithTagPriority** is always used to allocate memory.

## Remarks

Because noncached memory and contiguous memory are seldom released until the allocating miniport
driver is unloading, a caller of
**NdisFreeMemory** usually is running at IRQL = PASSIVE_LEVEL for these types of deallocations. In any
case:

* When releasing contiguous memory, a caller of
  **NdisFreeMemory** must be running at IRQL = PASSIVE_LEVEL.
* When releasing noncached memory, a caller of
  **NdisFreeMemory** must be running at IRQL < DISPATCH_LEVEL.
* When releasing memory that is neither contiguous nor noncached, a caller of
  **NdisFreeMemory** must be running at IRQL <= DISPATCH_LEVEL.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)
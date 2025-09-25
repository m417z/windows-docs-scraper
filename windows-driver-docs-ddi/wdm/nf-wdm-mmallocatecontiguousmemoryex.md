## Description

The **MmAllocateContiguousMemoryEx** function allocates a range of physically contiguous non-paged memory and returns its virtual address.

## Parameters

### `NumberOfBytes` [in]

On entry, supplies the number of bytes to allocate. On successful return, receives the amount allocated.

### `LowestAcceptableAddress` [in]

Supplies the lowest physical address which is valid for the allocation. For example, if the device can only reference physical memory in the 8M to 16MB range, this value would be set to 0x800000 (8Mb).

### `HighestAcceptableAddress` [in]

Supplies the highest physical address which is valid for the allocation. For example, if the device can only reference physical memory below 16MB, this value would be set to 0xFFFFFF (16Mb - 1).

### `BoundaryAddressMultiple` [in]

Supplies the physical address multiple this allocation must not cross.

### `PreferredNode` [in]

Supplies the preferred node the allocation should be made from if pages are available on that node. MM_ANY_NODE_OK is used to signify no node preference.

### `Protect` [in]

Supplies the desired protection (including cache type) for the mapping.

### `PartitionObject` [in, optional]

If specified, supplies a partition object to allocate the physical memory from. If not specified, the memory will come from the system partition.

### `Tag` [in]

Supplies the tag for the allocation.

### `Flags` [in]

Various flags:

- **MM_ALLOCATE_CONTIGUOUS_MEMORY_FAST_ONLY** - Allocate desired contiguous memory only if it can be satisfied quickly. Fail if prolonged physical memory searching and trading must take place to satisfy the allocation.

### `BaseAddress` [out]

On success, receives the base virtual address of the contiguous memory.

## Return value

Returns an NTSTATUS code.

## Remarks

This memory must be freed with [**MmFreeContiguousMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory).

## See also

[MmFreeContiguousMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreecontiguousmemory)
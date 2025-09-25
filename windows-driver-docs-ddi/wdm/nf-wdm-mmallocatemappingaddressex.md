# MmAllocateMappingAddressEx function

## Description

The **MmAllocateMappingAddressEx** function allocates a system PTE mapping of the requested length that can be used later to map arbitrary addresses.

## Parameters

### `NumberOfBytes` [in]

Supplies the maximum number of bytes the mapping can span.

### `PoolTag` [in]

Specifies a four-character tag used to identify the buffer. Use a distinct **PoolTag** tag for each allocation code path. For a description of pool tags, see [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

### `Flags` [in]

Specifies flags for this operation. Set this parameter to zero or to the bitwise-OR of one or more of the following flag bits:

| Flag | Meaning |
| ---- | ------- |
| MM_MAPPING_ADDRESS_DIVISIBLE | Indicates that the mapping address must be divisible by the size of the mapping. This flag is useful for ensuring that the mapping address aligns with certain hardware requirements. |

## Return value

**MmAllocateMappingAddressEx** returns a pointer to the beginning of the reserved memory buffer if the operation is successful; otherwise, it returns NULL.

## Remarks

**MmAllocateMappingAddressEx** provides an extended version of [**MmAllocateMappingAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress) with additional flag support. This function reserves a range of system virtual address space that can be used for later mapping operations with [**MmMapLockedPagesWithReservedMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping).

No physical memory is allocated by this function; it only reserves virtual address space. The reserved memory can't be accessed until it is mapped using [**MmMapLockedPagesWithReservedMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping).

Callers must provide a non-zero **PoolTag** to identify the allocation.

The reserved address range should be freed using [**MmFreeMappingAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreemappingaddress) when no longer needed.

Very large allocations (>= 4GB pages) will fail. The function might fail if insufficient system PTEs are available

## See also

[**MmAllocateMappingAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemappingaddress)

[**MmFreeMappingAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreemappingaddress)

[**MmMapLockedPagesWithReservedMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpageswithreservedmapping)

[**MmUnmapReservedMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmapreservedmapping)
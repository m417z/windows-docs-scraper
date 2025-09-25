# DiscardVirtualMemory function

## Description

Discards the memory contents of a range of memory pages, without decommitting the memory.
The contents of discarded memory is undefined and must be rewritten by the application.

## Parameters

### `VirtualAddress` [in]

Page-aligned starting address of the memory to discard.

### `Size` [in]

Size, in bytes, of the memory region to discard. *Size* must be an integer multiple of the system page size.

## Return value

ERROR_SUCCESS if successful; a [System Error Code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) otherwise.

## Remarks

If **DiscardVirtualMemory** fails, the contents of the region is not altered.

Use this function to discard memory contents that are no longer needed, while keeping the memory region itself committed.
Discarding memory may give physical RAM back to the system.
When the region of memory is again accessed by the application, the backing RAM is restored, and the contents of the memory is undefined.

**Important** Calls to **DiscardVirtualMemory** will fail if the memory protection is not **PAGE_READWRITE**.

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[OfferVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-offervirtualmemory)

[ReclaimVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-reclaimvirtualmemory)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree)

[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)
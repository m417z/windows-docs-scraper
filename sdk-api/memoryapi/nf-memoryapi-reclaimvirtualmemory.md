# ReclaimVirtualMemory function

## Description

Reclaims a range of memory pages that were offered to the system with [OfferVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-offervirtualmemory).

If the offered memory has been discarded, the contents of the memory region is undefined and must be rewritten by the application.
If the offered memory has not been discarded, it is reclaimed intact.

## Parameters

### `VirtualAddress` [in]

Page-aligned starting address of the memory to reclaim.

### `Size` [in]

Size, in bytes, of the memory region to reclaim. *Size* must be an integer multiple of the system page size.

## Return value

Returns ERROR_SUCCESS if successful and the memory was reclaimed intact.

Returns ERROR_BUSY if successful but the memory was discarded and must be rewritten by the application. In this case, the contents of the memory region is undefined.

Returns a [System Error Code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) otherwise.

## Remarks

Reclaimed memory pages can be used by the application, and will be written to the system paging file if paging occurs.

If the function returns ERROR_SUCCESS, the data in the reclaimed pages is valid.
If the function returns ERROR_BUSY, the data in the reclaimed pages was discarded by the system and is no longer valid.
For this reason, memory should only be offered to the system if the application does not need or can regenerate the data.

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[OfferVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-offervirtualmemory)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree)

[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)
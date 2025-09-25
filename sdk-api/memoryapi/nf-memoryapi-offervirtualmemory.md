# OfferVirtualMemory function

## Description

Indicates that the data contained in a range of memory pages is no longer needed by the application and can be discarded by the system if necessary.

The specified pages will be marked as inaccessible, removed from the process working set, and will not be written to the paging file.

To later reclaim offered pages, call [ReclaimVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-reclaimvirtualmemory).

## Parameters

### `VirtualAddress` [in]

Page-aligned starting address of the memory to offer.

### `Size` [in]

Size, in bytes, of the memory region to offer. *Size* must be an integer multiple of the system page size.

### `Priority` [in]

*Priority* indicates how important the offered memory is to the application.
A higher priority increases the probability that the offered memory can be reclaimed intact when calling [ReclaimVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-reclaimvirtualmemory).
The system typically discards lower priority memory before discarding higher priority memory.
*Priority* must be one of the following values.

| Value | Meaning |
| --- | --- |
| VMOfferPriorityVeryLow 0x00000001 | The offered memory is very low priority, and should be the first discarded. |
| VMOfferPriorityLow 0x00000002 | The offered memory is low priority. |
| VMOfferPriorityBelowNormal 0x00000003 | The offered memory is below normal priority. |
| VMOfferPriorityNormal 0x00000004 | The offered memory is of normal priority to the application, and should be the last discarded. |

## Return value

ERROR_SUCCESS if successful; a [System Error Code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) otherwise.

## Remarks

To reclaim offered pages, call [ReclaimVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-reclaimvirtualmemory).
The data in reclaimed pages may have been discarded, in which case the contents of the memory region is undefined and must be rewritten by the application.

Do not call **OfferVirtualMemory** to offer virtual memory that is locked.
Doing so will unlock the specified range of pages.

Note that offering and reclaiming virtual memory is similar to using the MEM_RESET and MEM_RESET_UNDO memory allocation flags,
except that **OfferVirtualMemory** removes the memory from the process working set and restricts access to the offered pages until they are reclaimed.

## See also

[DiscardVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-discardvirtualmemory)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[ReclaimVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-reclaimvirtualmemory)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree)

[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)
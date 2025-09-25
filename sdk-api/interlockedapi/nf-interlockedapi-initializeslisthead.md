# InitializeSListHead function

## Description

Initializes the head of a singly linked list.

## Parameters

### `ListHead` [in, out]

A pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list. This structure is for system use only.

## Remarks

All list items must be aligned on a **MEMORY_ALLOCATION_ALIGNMENT** boundary. Unaligned items can cause unpredictable results. See **_aligned_malloc**.

To add items to the list, use the [InterlockedPushEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist) function. To remove items from the list, use the [InterlockedPopEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist) function.

#### Examples

For an example, see [Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/win32/Sync/interlocked-singly-linked-lists).

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/win32/Sync/interlocked-singly-linked-lists)

[InterlockedPopEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist)

[InterlockedPushEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)
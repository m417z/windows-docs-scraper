# InterlockedPushEntrySList function

## Description

Inserts an item at the front of a singly linked list. Access to the list is synchronized on a multiprocessor system.

## Parameters

### `ListHead` [in, out]

Pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list.

### `ListEntry` [in, out]

Pointer to an [SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry) structure that represents an item in a singly linked list.

## Return value

The return value is the previous first item in the list. If the list was previously empty, the return value is **NULL**.

## Remarks

All list items must be aligned on a **MEMORY_ALLOCATION_ALIGNMENT** boundary; otherwise, this function will behave unpredictably. See **_aligned_malloc**.

#### Examples

For an example, see [Using Singly Linked Lists](https://learn.microsoft.com/windows/win32/Sync/using-singly-linked-lists).

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/win32/Sync/interlocked-singly-linked-lists)

[InterlockedFlushSList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedflushslist)

[InterlockedPopEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist)

[InterlockedPushListSList](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh448545(v=vs.85))

[InterlockedPushListSListEx](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushlistslistex)

[SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry)

[Using Singly Linked Lists](https://learn.microsoft.com/windows/win32/Sync/using-singly-linked-lists)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)
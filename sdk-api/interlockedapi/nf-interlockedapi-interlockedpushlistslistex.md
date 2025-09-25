# InterlockedPushListSListEx function

## Description

Inserts a singly-linked list at the front of another singly linked list. Access to the lists is synchronized on a multiprocessor system. This version of the method does not use the [__fastcall](https://learn.microsoft.com/previous-versions/6xa169sk(v=vs.85)) calling convention.

## Parameters

### `ListHead` [in, out]

Pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list. The list specified by the *List* and *ListEnd* parameters is inserted at the front of this list.

### `List` [in, out]

Pointer to an [SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry) structure that represents the first item in the list to be inserted.

### `ListEnd` [in, out]

Pointer to an [SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry) structure that represents the last item in the list to be inserted.

### `Count` [in]

The number of items in the list to be inserted.

## Return value

The return value is the previous first item in the list specified by the *ListHead* parameter. If the list was previously empty, the return value is `NULL`.

## Remarks

All list items must be aligned on a **MEMORY_ALLOCATION_ALIGNMENT** boundary; otherwise, this function will behave unpredictably. See **_aligned_malloc**.

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/win32/Sync/interlocked-singly-linked-lists)

[InterlockedFlushSList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedflushslist)

[InterlockedPopEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist)

[InterlockedPushEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist)

[SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry)

[Using Singly Linked Lists](https://learn.microsoft.com/windows/win32/Sync/using-singly-linked-lists)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)
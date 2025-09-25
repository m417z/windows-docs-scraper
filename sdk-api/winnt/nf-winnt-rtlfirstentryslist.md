# RtlFirstEntrySList function

## Description

Retrieves the first entry in a singly linked list. Access to the list is synchronized on a multiprocessor system.

## Parameters

### `ListHead` [in]

A pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list. This structure is for system use only.

The list must be previously initialized with the [InitializeSListHead](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-initializeslisthead) function.

## Return value

The return value is a pointer to the first entry in the list. If the list is empty, the return value is **NULL**.

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/desktop/Sync/interlocked-singly-linked-lists)
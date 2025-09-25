# RtlInterlockedPushEntrySList function

## Description

Inserts an item at the front of a singly linked list. Access to the list is synchronized on a multiprocessor system.

## Parameters

### `ListHead` [in]

A pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list.

### `ListEntry` [in]

A pointer to an
[SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry) structure that represents an item in a singly linked list.

## Return value

The return value is the previous first item in the list. If the list was previously empty, the return value is **NULL**.

## Remarks

Calls to the [InterlockedPushEntrySList](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist) function are forwarded to the **RtlInterlockedPushEntrySList** function. Applications should call **InterlockedPushEntrySList** instead of calling this function directly.

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/desktop/Sync/interlocked-singly-linked-lists)
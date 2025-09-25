# RtlInterlockedPopEntrySList function

## Description

Removes an item from the front of a singly linked list. Access to the list is synchronized on a multiprocessor system.

## Parameters

### `ListHead` [in]

A pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list.

## Return value

The return value is a pointer to the item removed from the list. If the list is empty, the return value is **NULL**.

## Remarks

Calls to the [InterlockedPopEntrySList](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist) function are forwarded to the **RtlInterlockedPopEntrySList** function. Applications should call **InterlockedPopEntrySList** instead of calling this function directly.

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/desktop/Sync/interlocked-singly-linked-lists)
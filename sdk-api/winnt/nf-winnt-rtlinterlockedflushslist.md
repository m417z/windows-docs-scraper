# RtlInterlockedFlushSList function

## Description

Removes all items from a singly linked list. Access to the list is synchronized on a multiprocessor system.

## Parameters

### `ListHead` [in]

A pointer to an **SLIST_HEADER** structure that represents the head of the singly linked list. This structure is for system use only.

## Return value

The return value is a pointer to the items removed from the list. If the list is empty, the return value is **NULL**.

## Remarks

Calls to the [InterlockedFlushSList](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-interlockedflushslist) function are forwarded to the **RtlInterlockedFlushSList** function. Applications should call **InterlockedFlushSList** instead of calling this function directly.

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/desktop/Sync/interlocked-singly-linked-lists)
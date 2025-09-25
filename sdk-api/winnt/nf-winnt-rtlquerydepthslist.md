# RtlQueryDepthSList function

## Description

Retrieves the number of entries in the specified singly linked list.

## Parameters

### `ListHead` [in]

A pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list. This structure is for system use only.

The list must be previously initialized with the [InitializeSListHead](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-initializeslisthead) function.

## Return value

The function returns the number of entries in the list.

## Remarks

Calls to the [QueryDepthSList](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-querydepthslist) function are forwarded to the **RtlQueryDepthSList** function. Applications should call **QueryDepthSList** instead of calling this function directly.

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/desktop/Sync/interlocked-singly-linked-lists)
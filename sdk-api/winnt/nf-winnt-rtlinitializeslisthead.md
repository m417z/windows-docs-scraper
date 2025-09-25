# RtlInitializeSListHead function

## Description

Initializes the head of a singly linked list.

## Parameters

### `ListHead` [in]

A pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list. This structure is for system use only.

## Return value

This function does not return a value.

## Remarks

Calls to the [InitializeSListHead](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-initializeslisthead) function are forwarded to the **RtlInitializeSListHead** function. Applications should call **InitializeSListHead** instead of calling this function directly.

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/desktop/Sync/interlocked-singly-linked-lists)
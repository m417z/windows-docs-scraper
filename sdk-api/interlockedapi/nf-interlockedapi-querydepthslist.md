# QueryDepthSList function

## Description

Retrieves the number of entries in the specified singly linked list.

## Parameters

### `ListHead` [in]

A pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list. This structure is for system use only.

The list must be previously initialized with the [InitializeSListHead](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-initializeslisthead) function.

## Return value

The function returns the number of entries in the list, up to a maximum value of 65535.

## Remarks

The system does not limit the number of entries in a singly linked list. However, the return value of **QueryDepthSList** is truncated to 16 bits, so the maximum value it can return is 65535. If the specified singly linked list contains more than 65535 entries, **QueryDepthSList** returns the number of entries in the list modulo 65535. For example, if the specified list contains 65536 entries, **QueryDepthSList** returns zero.

The return value of **QueryDepthSList** should not be relied upon in multithreaded applications because the item count can be changed at any time by another thread.

## See also

[InitializeSListHead](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-initializeslisthead)

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/win32/Sync/interlocked-singly-linked-lists)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)
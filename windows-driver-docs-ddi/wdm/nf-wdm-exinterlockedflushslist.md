# ExInterlockedFlushSList macro

## Description

The **ExInterlockedFlushSList** routine atomically removes all entries from a sequenced singly linked list.

## Syntax

```cpp
NTKERNELAPI
PSLIST_ENTRY
FASTCALL
ExInterlockedFlushSList (
    _Inout_ PSLIST_HEADER ListHead
    );
```

## Parameters

### `ListHead` [in, out]

A pointer to the [SLIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that serves as the header for the sequenced singly linked list.

## Return value

If there were entries on the specified list, **ExInterlockedFlushSList** returns a pointer to the first [**SLIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_slist_entry) structure that was an entry on the list; otherwise, it returns NULL.

## Remarks

**ExInterlockedFlushSList** does not delete the [SLIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_slist_entry) structures that made up the list; it only sets the internal pointer of *ListHead* to the beginning of the list to **NULL**. The driver must free the entries explicitly.

The routine returns a pointer to the first **SLIST_ENTRY** structure that was on the list. The driver can use this pointer to iterate through the entries.

For more information about using this routine to implement a sequenced singly linked list, see [Singly and Doubly Linked Lists](https://learn.microsoft.com/windows-hardware/drivers/kernel/singly-and-doubly-linked-lists).

Callers of **ExInterlockedFlushSList** can be running at any IRQL. The storage for the *ListHead* parameter and the list entries must be resident at all IRQLs.

## See also

[ExInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializeslisthead)
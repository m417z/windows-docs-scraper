# SINGLE_LIST_ENTRY structure

## Description

Represents an item in a singly linked list.

## Members

### `Next`

A pointer to an
**SLIST_ENTRY** structure that represents the next item in a singly linked list.

## Remarks

All list items must be aligned on a **MEMORY_ALLOCATION_ALIGNMENT** boundary. Unaligned items can cause unpredictable results. See **_aligned_malloc**.

#### Examples

For an example, see
[Using Singly Linked Lists](https://learn.microsoft.com/windows/desktop/Sync/using-singly-linked-lists).

## See also

[InitializeSListHead](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-initializeslisthead)

[InterlockedFlushSList](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-interlockedflushslist)

[InterlockedPopEntrySList](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist)

[InterlockedPushEntrySList](https://learn.microsoft.com/windows/desktop/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist)
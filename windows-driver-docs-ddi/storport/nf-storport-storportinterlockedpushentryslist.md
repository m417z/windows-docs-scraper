# StorPortInterlockedPushEntrySList function

## Description

Inserts an item at the front of a Storport managed singly linked list. Access to the list is synchronized on a multiprocessor system.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `SListHead` [in, out]

A pointer to an **STOR_SLIST_HEADER** structure that represents the head of a singly linked list. This structure is considered opaque and is for use by the Storport driver only.

### `SListEntry` [in, out]

A pointer to an **STOR_SLIST_ENTRY** structure that represents the item to insert into the singly linked list.

### `Result` [out]

A pointer to a list entry pointer. The value returned is a pointer to the previous item that existed at the front of the list. This previous item remains in the list behind the item new item added from *SListEntry*. If the list is empty, then **NULL** is returned in value pointed to by *Result*.

## Return value

**StorPortInterlockedPushEntrySList** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The list item was successfully inserted into the list or is already empty. |
| **STOR_STATUS_INVALID_PARAMETER** | A pointer in *SListHead*, *SListEntry*, or *Result* is **NULL**. |

## Remarks

When allocated by the caller, the **STOR_SLIST_ENTRY** structure pointed to by *SListEntry* must be aligned at a **MEMORY_ALLOCATION_ALIGNMENT** boundary. **MEMORY_ALLOCATION_ALIGNMENT** is defined in *miniport.h*.

## See also

[StorPortInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeslisthead)

[StorPortInterlockedFlushSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedflushslist)

[StorPortInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpopentryslist)

[StorPortQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportquerydepthslist)
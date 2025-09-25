# StorPortInterlockedPopEntrySList function

## Description

Removes an item from the front of a Storport managed singly linked list. Access to the list is synchronized on a multiprocessor system.
Syntax

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `SListHead` [in, out]

A pointer to an **STOR_SLIST_HEADER** structure that represents the head of a singly linked list. This structure is considered opaque and is for use by the Storport driver only.

### `Result` [out]

A pointer to a list entry pointer. The value returned is a pointer to the item removed from the front of the list. If the list is empty, then **NULL** is returned in the value pointed to by *Result*.

## Return value

**StorPortInterlockedPopEntrySList** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The list item was successfully removed from the list or is already empty. |
| **STOR_STATUS_INVALID_PARAMETER** | A pointer in *SListHead* or *Result* is **NULL**. |

## Remarks

The **StorPortInterlockedPopEntrySList** will also return **STATUS_SUCCESS** when no entries are in the list. The pointer value referenced by *Result* must be evaluated for **NULL** to verify that no entry was returned.

**StorPortInterlockedPopEntrySList** does not free the list entry it returns. Any deallocation code for the list must take care to free memory allocated for a list entry at the location obtained prior to any adjustment for boundary alignment. The value pointed to by *Result* may not be the original buffer location allocated due to an adjustment for **MEMORY_ALLOCATION_ALIGNMENT**. See remarks for [StorPortInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpushentryslist).

## See also

[StorPortInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeslisthead)

[StorPortInterlockedFlushSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedflushslist)

[StorPortInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpushentryslist)

[StorPortQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportquerydepthslist)
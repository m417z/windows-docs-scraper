# StorPortInterlockedFlushSList function

## Description

Removes all items from a Storport managed singly linked list. Access to the list is synchronized on a multiprocessor system

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `SListHead` [in, out]

A pointer to an **STOR_SLIST_HEADER** structure that represents the head of a singly linked list. This structure is considered opaque and is for use by the Storport driver only.

### `Result` [out]

A pointer to a list entry pointer. The value returned is a pointer to the items removed from the list. If the list is empty, then **NULL** is returned in value pointed to by *Result*.

## Return value

**StorPortInterlockedFlushSList** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The list items were removed successfully or the list is already empty. |
| **STOR_STATUS_INVALID_PARAMETER** | A pointer in *SListHead* or *Result* is **NULL**. |

## Remarks

The **StorPortInterlockedFlushSList** will also return **STATUS_SUCCESS** when no entries are in the list. The pointer value referenced by *Result* must be evaluated for **NULL** to verify that no entries were returned.

## See also

[StorPortInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeslisthead)

[StorPortInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpopentryslist)

[StorPortInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpushentryslist)

[StorPortQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportquerydepthslist)
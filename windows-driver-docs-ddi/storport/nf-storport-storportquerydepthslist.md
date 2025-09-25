# StorPortQueryDepthSList function

## Description

Retrieves the number of entries in a Storport managed singly linked list.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `SListHead` [in, out]

A pointer to an **STOR_SLIST_HEADER** structure that represents the head of a singly linked list. This structure is considered opaque and is for use by the Storport driver only.

### `Result` [out]

A pointer to a **SHORT** value which receives the list depth count.

## Return value

**StorPortQueryDepthSList** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The list depth was successfully returned. |
| **STOR_STATUS_INVALID_PARAMETER** | A pointer in *SListHead* or *Result* is **NULL**. |

## Remarks

Since **StorPortQueryDepthSList** is not interlocked, the list depth value pointed to by *Result* on return is not reliable in when multiple threads are operating on the list.

## See also

[StorPortInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeslisthead)

[StorPortInterlockedFlushSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedflushslist)

[StorPortInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpopentryslist)

[StorPortInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpushentryslist)
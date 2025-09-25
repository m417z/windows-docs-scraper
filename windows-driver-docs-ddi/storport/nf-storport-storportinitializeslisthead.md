# StorPortInitializeSListHead function

## Description

Initializes the head of a Storport managed singly linked list.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `SListHead` [in, out]

A pointer to an **STOR_SLIST_HEADER** structure that represents the head of a singly linked list. This structure is considered opaque and is for use by the Storport driver only.

## Return value

**StorPortInitializeSListHead** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The list head pointed to by *SListHead* was initialized successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer in *SListHead* is **NULL**. |

## Remarks

When allocated by the caller, the **STOR_SLIST_HEADER** structure pointed to by *SListHead* must be aligned at a **MEMORY_ALLOCATION_ALIGNMENT** boundary. **MEMORY_ALLOCATION_ALIGNMENT** is defined in *miniport.h*.

When memory for the list head is freed, any deallocation code must account for the original location of the buffer containing the list head structure prior to the adjustment for **MEMORY_ALLOCATION_ALIGNMENT**.

## See also

[StorPortInterlockedFlushSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedflushslist)

[StorPortInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpopentryslist)

[StorPortInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedpushentryslist)

[StorPortQueryDepthSList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportquerydepthslist)
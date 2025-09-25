# NdisQueryDepthSList macro

## Description

The
**NdisQueryDepthSList** function returns the current number of entries in a given sequenced, singly
linked list.

## Parameters

### `SListHead` [in]

A pointer to the head of the S-List to be queried, which the caller already initialized with
[NdisInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializeslisthead).

## See also

[NdisInitializeSListHead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializeslisthead)

[NdisInterlockedPopEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedpopentryslist)

[NdisInterlockedPushEntrySList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedpushentryslist)
# NdisFreeToNPagedLookasideList macro

## Description

The
**NdisFreeToNPagedLookasideList** function returns an entry to the given lookaside list.

## Parameters

### `_L`

A pointer to the head of the lookaside list to which the entry will be returned.

### `_E`

A pointer to the entry to be freed.

## Remarks

If the lookaside list has not reached the system-determined maximum number of entries,
*Entry* is inserted at the front of the lookaside list. If the list has reached its maximum size,
*Entry* is released to nonpaged pool. That is,
**NdisFreeToNPagedLookasideList** either calls the driver's
*Free* function, specified in the
*Free* parameter if the driver provided one to the
[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist) function, or it frees the given entry itself.

## See also

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisDeleteNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdeletenpagedlookasidelist)

[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist)
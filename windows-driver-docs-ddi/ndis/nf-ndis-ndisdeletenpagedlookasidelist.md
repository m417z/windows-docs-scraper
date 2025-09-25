# NdisDeleteNPagedLookasideList macro

## Description

The
**NdisDeleteNPagedLookasideList** function removes a nonpaged lookaside list from the system.

## Parameters

### `_L`

A pointer to the head of the lookaside list to be deleted.

## Remarks

After freeing any remaining entries in the given lookaside list,
**NdisDeleteNPagedLookasideList** removes the list from the OS-maintained set of nonpaged lookaside
lists.

However,
**NdisDeleteNPagedLookasideList** does not free the list head, for which the caller originally
allocated the memory. An NDIS driver is responsible for calling the
[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory) function to release any
memory that it allocated.

## See also

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist)
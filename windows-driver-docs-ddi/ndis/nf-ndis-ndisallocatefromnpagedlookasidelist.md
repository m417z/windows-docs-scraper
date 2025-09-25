# NdisAllocateFromNPagedLookasideList macro

## Description

The
**NdisAllocateFromNPagedLookasideList** function removes the first entry from the given lookaside list
head. If the lookaside list currently is empty, an entry is allocated from nonpaged pool.

## Parameters

### `_L`

A pointer to the head of the lookaside list from which the entry will be allocated. The caller
already initialized the list head with the
[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist) function.

## Remarks

If the lookaside list is not empty,
**NdisAllocateFromNPagedLookasideList** removes the first entry from the list and returns its address
to the caller. If the lookaside list is empty,
**NdisAllocateFromNPagedLookasideList** either calls the
*Allocate* function, specified in the
*Allocate* parameter of the
[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist) function, that the caller specified at list initialization, if
any, or it allocates an entry on behalf of the caller.
**NdisAllocateFromNPagedLookasideList** returns **NULL** if the caller-supplied
*Allocate* function, if any, or if this function itself cannot allocate a nonpaged entry.

All entries that are allocated from a nonpaged lookaside list are of a fixed size, that was specified
when the driver originally called
**NdisInitializeNPagedLookasideList**. Consequently, a lookaside list is particularly useful to
drivers that must allocate fixed-size blocks in which to maintain state in response to dynamic I/O
demand. For example, any connection-oriented NDIS driver might allocate the VC context areas that it
needs from a lookaside list as VCs are created and release each such entry back to the lookaside list
with the
[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist) function as each VC is torn down.

## See also

[NdisDeleteNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdeletenpagedlookasidelist)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[NdisInitializeNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializenpagedlookasidelist)
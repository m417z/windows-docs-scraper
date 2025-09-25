# NdisAllocateReassembledNetBufferList function

## Description

Call the
**NdisAllocateReassembledNetBufferList** function to reassemble a fragmented
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `FragmentNetBufferList`

A pointer to the NET_BUFFER_LIST structure to reassemble.

### `NetBufferAndNetBufferListPoolHandle` [in, optional]

A NET_BUFFER_LIST structure pool handle that was previously returned from the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function. The
**fAllocateNetBuffer** member of the
[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters) structure that the caller passed to
**NdisAllocateNetBufferListPool** must have been set to **TRUE**, and the
**DataSize** member set to zero. If this parameter is **NULL**, NDIS uses an internal pool.

### `StartOffset` [in]

The amount of data to skip at the beginning of each source
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. This amount is in addition
to the value that is specified in the
**DataOffset** member of the NET_BUFFER structure.

### `DataOffsetDelta` [in]

The number of bytes of
*used data space* to add to in the reassembled NET_BUFFER structure.

### `DataBackFill` [in]

If allocation of
*unused data space* (backfill space) is required, this parameter specifies the number of bytes of
*unused data space* in addition to
*DataOffsetDelta* to allocate.

### `AllocateReassembleFlags` [in]

NDIS flags that can be combined with an OR operation. Set this parameter to zero. There are
currently no flags defined for this function.

## Return value

If the reassemble operation succeeds,
**NdisAllocateReassembledNetBufferList** returns a reassembled NET_BUFFER_LIST structure. If the
operation fails, it returns **NULL**.

## Remarks

**NdisAllocateReassembledNetBufferList** allocates, initializes, and returns a new
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that includes one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure and one MDL chain. The new
NET_BUFFER_LIST structure describes the same data as the fragmented source NET_BUFFER_LIST structure that
the driver passed at
*FragmentedNetBufferList*. After skipping the number of bytes specified in
*StartOffset* in every fragmented NET_BUFFER structure, NDIS concatenates the remaining data in each
fragmented NET_BUFFER structure into one reassembled NET_BUFFER structure. Reassembled NET_BUFFER_LIST
structures do not include an initial
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure.

Call the
[NdisFreeReassembledNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreereassemblednetbufferlist) function to free a reassembled NET_BUFFER_LIST structure and all
of the associated NET_BUFFER structures and MDL chains.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisFreeReassembledNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreereassemblednetbufferlist)
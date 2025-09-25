# NdisFreeReassembledNetBufferList function

## Description

Call the
**NdisFreeReassembledNetBufferList** function to free a reassembled
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure and the associated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure and MDL chain.

## Parameters

### `ReassembledNetBufferList` [in]

A pointer to a NET_BUFFER_LIST structure that the driver allocated by calling the
[NdisAllocateReassembledNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatereassemblednetbufferlist) function.

### `DataOffsetDelta` [in]

The number of bytes to advance (add to) the
**DataOffset** member of the reassembled NET_BUFFER structure before freeing the structure. This value
should match
*DataOffsetDelta* that the driver passed to
**NdisAllocateReassembledNetBufferList**.

### `FreeReassembleFlags` [in]

NDIS flags that can be combined with an OR operation. Set this parameter to zero. There are
currently no flags defined for this function.

## Remarks

**NdisFreeReassembledNetBufferList** frees a reassembled
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that the caller
allocated by calling
[NdisAllocateReassembledNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatereassemblednetbufferlist).

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateReassembledNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatereassemblednetbufferlist)
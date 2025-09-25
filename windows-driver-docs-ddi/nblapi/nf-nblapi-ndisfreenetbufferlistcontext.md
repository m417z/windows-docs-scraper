# NdisFreeNetBufferListContext function

## Description

Call the
**NdisFreeNetBufferListContext** function to release context space in the
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure of a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `NetBufferList` [in]

A pointer to a previously allocated NET_BUFFER_LIST structure.

### `ContextSize` [in]

The amount of context space to free.

## Remarks

**NdisFreeNetBufferListContext** releases context space that was allocated in a previous call to
[NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext). If
**NdisAllocateNetBufferListContext** allocated memory to satisfy in the call to
**NdisAllocateNetBufferListContext**,
**NdisFreeNetBufferListContext** frees the allocated memory.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext)
# NdisAllocateNetBufferList function

## Description

Call the
**NdisAllocateNetBufferList** function to allocate and initialize a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure from a
NET_BUFFER_LIST structure pool.

## Parameters

### `PoolHandle` [in]

A NET_BUFFER_LIST structure pool handle that was previously returned from a call to
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool).

### `ContextSize` [in]

The amount of
*used data space* in the
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure
to reserve for the caller. The
*ContextSize* must be a multiple of the value defined by MEMORY_ALLOCATION_ALIGNMENT.

### `ContextBackFill` [in]

The amount of
*unused data space* (backfill space) that the caller requires. NDIS adds this value to the
*ContextSize* and allocates additional space. The
*ContextBackFill* must be a multiple of the value defined by MEMORY_ALLOCATION_ALIGNMENT.

## Return value

**NdisAllocateNetBufferList** returns a pointer to the allocated NET_BUFFER_LIST structure. If the
allocation was unsuccessful, this pointer is **NULL**.

## Remarks

You can call the
**NdisAllocateNetBufferList** or
[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist) function to allocate a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure from a pool.

**Note** [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) and
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures must be allocated
from an NDIS buffer pool. A driver must not allocate and initialize a NET_BUFFER_LIST or NET_BUFFER
structure from its private memory pool or the stack.

If you call
**NdisAllocateNetBufferList** and the NET_BUFFER_LIST structure pool was allocated by calling the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function with the
**fAllocateNetBuffer** member of the
[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters) structure set to **TRUE**, NDIS allocates a
NET_BUFFER_LIST,
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer), MDL, and data.

Call the
[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist) function to
free a NET_BUFFER_LIST structure.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist)
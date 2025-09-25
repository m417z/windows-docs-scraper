# NdisAllocateNetBufferListPool function

## Description

Call the
**NdisAllocateNetBufferListPool** function to allocate a pool of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

## Parameters

### `NdisHandle` [in, optional]

An NDIS handle that was obtained during caller initialization.

### `Parameters` [in]

A pointer to a [NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters) structure that defines the parameters for the pool.

## Return value

**NdisAllocateNetBufferListPool** returns a handle to the NET_BUFFER_LIST structure pool that NDIS
allocates. If the allocation was unsuccessful, this handle is **NULL**. This handle is a required parameter
in subsequent calls to NDIS functions that allocate and free NET_BUFFER_LIST structures from this
pool.

## Remarks

In most cases, a caller that allocates a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure will allocate and
queue at least one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure on that NET_BUFFER_LIST
structure. It is more efficient to preallocate NET_BUFFER structures when you allocate a pool of
NET_BUFFER_LIST structures than allocating NET_BUFFER_LIST structures and NET_BUFFER structures
separately.

You can call the
**NdisAllocateNetBufferListPool** function with the
**fAllocateNetBuffer** value set to **TRUE** when creating a NET_BUFFER_LIST structure pool. In this case,
a NET_BUFFER structure is preallocated with each NET_BUFFER_LIST structure that the caller allocates from
the pool. You can call the
[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist) function or the
[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist) function to allocate NET_BUFFER_LIST structures from such a pool. Call
**NdisAllocateNetBufferAndNetBufferList** only if
**fAllocateNetBuffer** is **TRUE** and
**DataSize** is zero.

You can also call
**NdisAllocateNetBufferListPool** and set the
**DataSize** member to a nonzero value when creating a NET_BUFFER_LIST structure pool. In this case, a
NET_BUFFER structure, MDL, and data are preallocated with each NET_BUFFER_LIST structure that the caller
allocates from the pool.

NET_BUFFER structures, MDLs, and data buffers that are allocated with
[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist) or
[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist) should
not be freed separate from the NET_BUFFER_LIST structure. Such structures are freed with the
NET_BUFFER_LIST structure when you call the
[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist) function.

Call the
[NdisFreeNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistpool) function to free a NET_BUFFER_LIST structure pool.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)

[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist)

[NdisFreeNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistpool)
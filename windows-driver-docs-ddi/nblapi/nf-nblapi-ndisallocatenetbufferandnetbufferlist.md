# NdisAllocateNetBufferAndNetBufferList function

## Description

Call the
**NdisAllocateNetBufferAndNetBufferList** function to allocate and initialize a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that is initialized
with a preallocated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Parameters

### `PoolHandle` [in]

A NET_BUFFER_LIST structure pool handle that was previously returned from the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function. The
**fAllocateNetBuffer** member of the
[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters) structure that the caller passed to
**NdisAllocateNetBufferListPool** must have been set to **TRUE** and the
**DataSize** member set to zero.

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

### `MdlChain` [in, optional]

A pointer to an MDL chain that NDIS uses to initialize the preallocated NET_BUFFER structure.
*MdlChain* can be **NULL**.

### `DataOffset` [in]

The initial offset, in bytes, from the start of the buffer to the start of the
*used data space* in the MDL chain. Data space ahead of this offset is
*unused data space*. Therefore, this value also represents the initial amount of available backfill
space in the MDL chain. If
*MdlChain* is **NULL**,
*DataOffset* must be 0.

### `DataLength` [in]

The length, in bytes, of the
*used data space* in the MDL chain. If
*MdlChain* is **NULL**,
*DataLength* must be 0.

## Return value

**NdisAllocateNetBufferAndNetBufferList** returns a pointer to the allocated NET_BUFFER_LIST
structure. The NET_BUFFER_LIST structure includes a NET_BUFFER structure. If the allocation was
unsuccessful, this pointer is **NULL**.

## Remarks

The structures that the
**NdisAllocateNetBufferAndNetBufferList** function allocates must come from a pool that includes
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are paired
with preallocated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. To create such a pool, you
must call the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function with the
**fAllocateNetBuffer** member of the
[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters) structure set to **TRUE**, and the
**DataSize** member set to zero.

**Note** [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) and
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures must be allocated
from an NDIS buffer pool. A driver must not allocate and initialize a **NET_BUFFER_LIST** or **NET_BUFFER**
structure from its private memory pool or the stack.

Call the
[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist) function to
free a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

The preallocated [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) can be reused by reinitializing it with another MDL chain when it owns
**NET_BUFFER**, but the
*DataOffset*,
*DataLength*,
*CurrentMdl*, and
*CurrentMdlOffset* fields in the **NET_BUFFER** must be consistent with the new MDL chain.

For example, if the original MDL chain contains *X*
*DataLength* and *Y*
*DataOffset*, and
*CurrentMdl* starts with the second MDL (*M*) in the original MDL chain,
*CurrentMdlOffset* is *Z*. The
*MdlChain* field in [NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data) then needs to point to a new MDL chain that contains *X'*
*DataLength* and *Y'*
*DataOffset*. If
*CurrentMdl* starts with the third MDL (*M'*) in the new MDL chain,
*CurrentMdlOffset* is *Z'*, and the following macros need to be used to set fields in [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer):

```
NET_BUFFER_FIRST_MDL(_NB) = New MDL chain;
NET_BUFFER_DATA_LENGTH(_NB) = X';
NET_BUFFER_DATA_OFFSET(_NB) = Y';
NET_BUFFER_CURRENT_MDL(_NB) = M';
NET_BUFFER_CURRENT_MDL_OFFSET(_NB) = Z';
```

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist)
# NdisAllocateNetBuffer function

## Description

Call the
**NdisAllocateNetBuffer** function to allocate and initialize a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure from a **NET_BUFFER** structure
pool.

## Parameters

### `PoolHandle` [in]

A [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure pool handle that was previously returned from a call to
[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool).

### `MdlChain` [in, optional]

A pointer to an MDL chain that NDIS uses to initialize the new [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.
*MdlChain* can be **NULL**.

### `DataOffset` [in]

The initial offset, in bytes, from the start of the buffer to the start of the
*used data space* in the MDL chain. Data space ahead of this offset is
*unused data space*. Therefore, this value also represents the initial amount of available backfill
space in the MDL chain. If
*MdlChain* is **NULL**,
*DataOffset* must be 0.

### `DataLength` [in]

The length of the
*used data space*, in bytes, in the MDL chain. If
*MdlChain* is **NULL**,
*DataLength* must be 0.

## Return value

**NdisAllocateNetBuffer** returns a pointer to the [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure that NDIS allocated. If the
allocation was unsuccessful, this pointer is **NULL**.

## Remarks

Call
[NdisFreeNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbuffer) to free a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure that was allocated from a
**NET_BUFFER** structure pool.

**Note** [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) and
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures must be allocated
from an NDIS buffer pool. A driver must not allocate and initialize a **NET_BUFFER** or **NET_BUFFER_LIST**
structure from its private memory pool or the stack.

The preallocated [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) can be reused by reinitializing it with another MDL chain when it owns
**NET_BUFFER**, but the
*DataOffset*,
*DataLength*,
*CurrentMdl*, and
*CurrentMdlOffset* fields in **NET_BUFFER** must be consistent with the new MDL chain.

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

[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool)

[NdisFreeNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbuffer)
# NdisAllocateCloneNetBufferList function

## Description

Call the
**NdisAllocateCloneNetBufferList** function to create a new clone
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `OriginalNetBufferList` [in]

A pointer to an existing [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

### `NetBufferListPoolHandle` [in, optional]

A handle that was obtained from a call to the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function.

### `NetBufferPoolHandle` [in, optional]

A
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure pool handle that was
previously returned from a call to
[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool).

### `AllocateCloneFlags` [in]

NDIS flags that can be combined with an OR operation. The following flags are defined:

#### NDIS_CLONE_FLAGS_RESERVED

Reserved for NDIS.

#### NDIS_CLONE_FLAGS_USE_ORIGINAL_MDLS

If this flag is set, NDIS does not allocate new MDLs for the cloned [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list). Instead,
the cloned **NET_BUFFER_LIST** uses the same MDL chain as the original **NET_BUFFER_LIST**. If
NDIS_CLONE_FLAGS_USE_ORIGINAL_MDLS is cleared, NDIS allocates new MDLs to reference the original data
buffers.

## Return value

**NdisAllocateCloneNetBufferList** returns a pointer to the new clone [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. If
the allocation was unsuccessful, this pointer is **NULL**.

## Remarks

Call
**NdisAllocateCloneNetBufferList** to create a clone
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that you can use
to send duplicate data on a separate data path.

Each [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure in the original [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure is only cloned from the start of the used data space, not the start of the entire data space. To get the offset from the beginning of the data space to the start of the used data space, use the [NET_BUFFER_DATA_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-offset) macro.

If the cloned [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure should have attributes that are associated with a given pool,
the caller must specify the pool handle in the
*NetBufferListPoolHandle* or
*NetBufferPoolHandle* parameter. For example, the
**ProtocolType** member of the **NET_BUFFER_LIST** structure is associated with the pool.

The clone [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure describes the same data that is described by the **NET_BUFFER_LIST**
structure at
*OriginalNetBufferList*. NDIS does not copy the data that is described by the original MDLs to new
data buffers. Instead, the cloned structures reference the original data buffers. The clone
**NET_BUFFER_LIST** structure does not include an initial
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure.

Call the
[NdisFreeCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreeclonenetbufferlist) function to free a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure and all of the associated
structures and MDL chains that were allocated by calling
**NdisAllocateCloneNetBufferList**.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool)

[NdisFreeCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreeclonenetbufferlist)
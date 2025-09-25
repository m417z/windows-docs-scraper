# NdisFreeCloneNetBufferList function

## Description

Call the
**NdisFreeCloneNetBufferList** function to free a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure and all associated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures and MDL chains that were
previously allocated by calling the
[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist) function.

## Parameters

### `CloneNetBufferList` [in]

A pointer to a NET_BUFFER_LIST structure that was allocated by calling
**NdisAllocateCloneNetBufferList**.

### `FreeCloneFlags` [in]

NDIS flags that can be combined with an OR operation. The following flags are defined:

#### NDIS_CLONE_FLAGS_RESERVED

Reserved for NDIS.

#### NDIS_CLONE_FLAGS_USE_ORIGINAL_MDLS

If this flag is set, NDIS did not allocate new MDLs for the cloned NET_BUFFER_LIST in the
[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist) function. Instead, the cloned NET_BUFFER_LIST used the same MDL
chain as in the original NET_BUFFER_LIST. If NDIS_CLONE_FLAGS_USE_ORIGINAL_MDLS is cleared, NDIS
allocated new MDLs to reference the original data buffers.

## Remarks

The caller must specify the same flags that it specified in the
*AllocateCloneFlags* parameter when it called the
[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist) function.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)
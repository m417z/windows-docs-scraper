# NdisFreeFragmentNetBufferList function

## Description

Call the
**NdisFreeFragmentNetBufferList** function to free a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure and all associated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures and MDL chains that were
previously allocated by the calling
[NdisAllocateFragmentNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefragmentnetbufferlist) function.

## Parameters

### `FragmentNetBufferList` [in]

A pointer to a NET_BUFFER_LIST structure that was allocated by calling
**NdisAllocateFragmentNetBufferList**.

### `DataOffsetDelta` [in]

The amount, in bytes, to advance (add to the data offset) the fragment NET_BUFFER structures
before freeing them. This value should match the value of the
*DataOffsetDelta* parameter that was passed to
**NdisAllocateFragmentNetBufferList** when the NET_BUFFER_LIST structure was created.

### `FreeFragmentFlags` [in]

NDIS flags that can be combined with an OR operation. Set this parameter to zero. There are
currently no flags defined for this function.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateFragmentNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefragmentnetbufferlist)
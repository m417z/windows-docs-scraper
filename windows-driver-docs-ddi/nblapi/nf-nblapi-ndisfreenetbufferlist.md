# NdisFreeNetBufferList function

## Description

Call the
**NdisFreeNetBufferList** function to free a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that was previously
allocated from a NET_BUFFER_LIST structure pool.

## Parameters

### `NetBufferList` [in]

A pointer to a NET_BUFFER_LIST structure that was allocated by calling the
[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist) or
[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist) function.

## Remarks

To allocate a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure from a pool, call
the
[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist) or
[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist) function.

The
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that are associated with
the NET_BUFFER_LIST structure are not freed unless they were preallocated with the NET_BUFFER_LIST
structure. You can reuse any NET_BUFFER structures that were not preallocated or you should free such
structures separately.

If you allocated context space for a NET_BUFFER_LIST structure with the
[NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext) function, you must free such context space before you free the
NET_BUFFER_LIST structure. You must not attempt to free the context space that you allocated with
**NdisAllocateNetBufferList** or
**NdisAllocateNetBufferAndNetBufferList** by specifying the
*ContextSize* and
*ContextBackFill* parameters.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)

[NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext)
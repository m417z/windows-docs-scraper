# _NET_BUFFER_LIST_CONTEXT structure

## Description

The NET_BUFFER_LIST_CONTEXT structure stores context information for a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `Next`

A pointer to the next NET_BUFFER_LIST_CONTEXT structure in a linked list of
NET_BUFFER_LIST_CONTEXT structures.

### `Size`

The size, in bytes, of the entire context space in the NET_BUFFER_LIST_CONTEXT structure,
including the used and unused context space.

### `Offset`

The offset, in bytes, from the beginning of the context data buffer to the start of the context
data in the NET_BUFFER_LIST_CONTEXT structure. The
**Offset** member also specifies the size in bytes of the unused context space in the
NET_BUFFER_LIST_CONTEXT structure.

### `ContextData`

The context data buffer. The context data can include any information that a driver
requires.

## Remarks

Every
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure can include a
preallocated NET_BUFFER_LIST_CONTEXT structure. As a NET_BUFFER_LIST structure travels through the driver
stack, the linked list of NET_BUFFER_LIST_CONTEXT structures can expand to accommodate additional data
space for each driver.

Drivers should use the following NDIS macros and functions to access and manipulate members in a
NET_BUFFER_LIST_CONTEXT structure:

* [NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext)
* [NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext)
* [NET_BUFFER_LIST_CONTEXT_DATA_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_start)
* [NET_BUFFER_LIST_CONTEXT_DATA_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_size)

The
**ContextData** member of the NET_BUFFER_LIST_CONTEXT structure specifies the data portion of the
NET_BUFFER_LIST_CONTEXT structure. To improve system performance, a driver should preallocate any
required context data space when the driver allocates a NET_BUFFER_LIST structure pool. To preallocate
this data space, a driver calls the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function and then specifies the amount of data space required in the
*ContextSize* parameter. Preallocation of this data space saves NDIS from allocating memory in the
receive and send paths.

**Note** NDIS estimates the required context data space and, if necessary, adjusts the
allocated data space to meet the requirements for the entire driver stack.

The
**Offset** member specifies the amount of unused context space in the NET_BUFFER_LIST_CONTEXT
structure. The
**Offset** member also indicates the offset from the beginning of the
**ContextData** member to the start of the used context data space.

NDIS drivers call the
[NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext) function to allocate contiguous buffer space in the
NET_BUFFER_LIST_CONTEXT structure. If necessary, NDIS allocates a new NET_BUFFER_LIST_CONTEXT structure
with additional space to honor the request. NDIS drivers call the
[NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext) function to free the buffer space.

Use the
[NET_BUFFER_LIST_CONTEXT_DATA_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_size) macro to obtain the size of the used context space. Use the
[NET_BUFFER_LIST_CONTEXT_DATA_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_start) macro to get the starting address of the used context space.

For more information on how to use net buffers, see
[NET_BUFFER Architecture](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-architecture).

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT_DATA_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_size)

[NET_BUFFER_LIST_CONTEXT_DATA_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_start)

[NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext)
# _NET_BUFFER_LIST_POOL_PARAMETERS structure

## Description

The **NET_BUFFER_LIST_POOL_PARAMETERS** structure defines the parameters for a pool of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures.

## Members

### `Header`

The type, revision, and size of the **NET_BUFFER_LIST_POOL_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NET_BUFFER_LIST_POOL_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NET_BUFFER_LIST_POOL_PARAMETERS_REVISION_1

Original version for NDIS 6.0.

Set the **Size** member to NDIS_SIZEOF_NET_BUFFER_LIST_POOL_PARAMETERS_REVISION_1.

### `ProtocolId`

The type of caller. Miniport, filter, and intermediate drivers set this field to zero
(NDIS_PROTOCOL_ID_DEFAULT). Protocol drivers use one of the following values:

#### NDIS_PROTOCOL_ID_DEFAULT

Specifies a default protocol driver identifier.

#### NDIS_PROTOCOL_ID_TCP_IP

Specifies the TCP/IP protocol.

#### NDIS_PROTOCOL_ID_IPX

Specifies the IPX protocol.

#### NDIS_PROTOCOL_ID_NBF

Specifies the NetBEUI protocol.

### `fAllocateNetBuffer`

If this member is set to TRUE, NDIS allocates a pool of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. Each allocated **NET_BUFFER_LIST** structure is initialized with one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

If this member is set to FALSE, NDIS allocates a pool of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. Each allocated **NET_BUFFER_LIST** structure is not initialized to contain any
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures.

For more information, see the Remarks section.

### `ContextSize`

The size, in bytes, of the preallocated
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure
data that NDIS should provide for the NET_BUFFER_LIST structures in this pool. The
**ContextSize** must be a multiple of the value that is defined by MEMORY_ALLOCATION_ALIGNMENT.

### `PoolTag`

A kernel pool tag that the caller uses when it allocates NET_BUFFER_LIST structures from this
pool. The tag is a string, delimited by single quotation marks, with up to four characters, usually
specified in reversed order. The kernel pool tag helps NDIS to identify the owner of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are allocated from this pool.

### `DataSize`

The default data size, in bytes, for data buffers that are associated with this
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pool, if any. NDIS uses
this value to set the size of any data buffers that it allocates for any associated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures.

For more information, see the Remarks section.

### `Flags`
The following flag is defined:
#### NET_BUFFER_LIST_POOL_FLAG_VERIFY 0x00000001
If this flag is set, NDIS will not immediately reuse NET_BUFFER_LISTs from this pool. Instead, allocations will be marked as no-access when they are freed so that drivers can detect use-after-free bugs.

## Remarks

If
**fAllocateNetBuffer** is set to FALSE, NDIS will not allocate [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures, and
**DataSize** should be set to zero.

If
**DataSize** is not zero,
**fAllocateNetBuffer** must be set to TRUE. This causes NDIS to allocate the [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure with a data buffer
of the specified size.

If
**DataSize** is zero and
**fAllocateNetBuffer** is **TRUE**, NDIS allocates the [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure but not the data
buffer.

The *Parameters* parameter of the [NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function contains a pointer to an **NET_BUFFER_LIST_POOL_PARAMETERS** structure.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_data)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)
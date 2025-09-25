# _NET_BUFFER structure

## Description

The NET_BUFFER structure specifies data that is transmitted or received over the network.

## Members

### `Next`

A pointer to the next NET_BUFFER structure in a linked list of NET_BUFFER structures. If this structure is the last NET_BUFFER structure in the list, this member is NULL.

### `CurrentMdl`

A pointer to the first MDL that the current driver is using. This member provides an optimization that improves performance by skipping over any MDLs that the current driver is not using.

### `CurrentMdlOffset`

The offset, in bytes, to the beginning of the *used data space* in the MDL that is specified by the **CurrentMdl** member.

### `DataLength`

The length, in bytes, of the used data space in the MDL chain. The maximum length is 0xFFFFFFFF bytes.

### `stDataLength`

The length, in bytes, of the used data space in the MDL chain. The maximum length is 0xFFFFFFFF bytes. This member is the same as **DataLength**, but its type is **SIZE_T** instead of **ULONG**.

### `MdlChain`

A pointer to a linked list of MDLs that map a data buffer. The data buffer stores the network data.

### `DataOffset`

The offset, in bytes, from the beginning of the MDL chain to the beginning of the network data in the MDL chain. This offset is also the size, in bytes, of the *unused data space*.

### `Link`

Reserved for NDIS.

### `NetBufferHeader`

A
[NET_BUFFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_buffer_header) structure. This is a duplicate of the above union, for compatibility reasons.

### `ChecksumBias`

The number of bytes to skip over from the beginning of the data buffer when computing a checksum.
This member is used by the TCP/IP protocol.

### `Reserved`

Reserved for future use.

### `NdisPoolHandle`

A pool handle that identifies the NET_BUFFER pool from which the NET_BUFFER structure was
allocated.

### `NdisReserved`

Reserved for NDIS.

### `ProtocolReserved`

Reserved for use by protocol drivers. Protocol drivers and NDIS intermediate drivers can use this
area for their own purposes. Intermediate drivers can use this member only if it is not already in
use.

### `MiniportReserved`

Reserved for use by miniport drivers. Miniport drivers and NDIS intermediate drivers can use this
area for their own purposes.

### `DataPhysicalAddress`

**Note** The name of this member is
**NdisReserved1** for NDIS 6.0 drivers and is
**DataPhysicalAddress** for NDIS 6.1 and later drivers. For NDIS 6.0 drivers, this member is reserved
for NDIS.

The physical address of the data portion of a frame. This member should be to zero if the driver
that allocated NET_BUFFER does not specify the address. This member is valid only if the
NDIS_NBL_FLAGS_SPLIT_AT_UPPER_LAYER_PROTOCOL_HEADER or
NDIS_NBL_FLAGS_SPLIT_AT_UPPER_LAYER_PROTOCOL_PAYLOAD flag is set in the
**NblFlags** member of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that is
associated with the NET_BUFFER.

**Note** A miniport driver can set the
**DataPhysicalAddress** member of the NET_BUFFER structure, even if the structure is not associated
with a split frame. In this case,
**DataPhysicalAddress** contains the physical address of the header MDL.

### `SharedMemoryInfo`

A pointer to an
[NET_BUFFER_SHARED_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure.

### `ScatterGatherList`

The SCATTER_GATHER_LIST structure describes a scatter/gather list for DMA.

## Remarks

NDIS drivers can call the following functions to allocate and initialize a NET_BUFFER structure:

* [NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer)
* [NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

NDIS drivers can call the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function and then set the
**fAllocateNetBuffer** member of the
[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters) structure to **TRUE** when allocating a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure pool. In this
case, a NET_BUFFER structure is preallocated with each NET_BUFFER_LIST structure that the driver
allocates from the pool.

Chained to each NET_BUFFER structure are one or more buffer descriptors that map buffers that contain
network packet data. These buffer descriptors are specified as an MDL chain in the
**NetBufferHeader** member. Such network packet data either was received or will be transmitted.

To access additional data space in the MDL chain, NDIS drivers can call the following functions:

* [NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart)
* [NdisRetreatNetBufferListDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferlistdatastart)

NDIS drivers typically use the
**MiniportReserved** or
**ProtocolReserved** members of the NET_BUFFER structure to maintain NET_BUFFER structure context
information.

**Note** Only one driver can use
**MiniportReserved** or
**ProtocolReserved** members. Therefore, if another driver has used either of these members, an
intermediate driver cannot use them.

To access members of the NET_BUFFER structure, use the following macros and functions:

[NET_BUFFER_NEXT_NB](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-next-nb)

[NET_BUFFER_FIRST_MDL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-first-mdl)

[NET_BUFFER_DATA_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-offset)

[NET_BUFFER_DATA_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-length)

[NET_BUFFER_PROTOCOL_RESERVED](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-protocol-reserved)

[NET_BUFFER_MINIPORT_RESERVED](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-miniport-reserved)

[NET_BUFFER_CHECKSUM_BIAS](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-checksum-bias)

[NET_BUFFER_CURRENT_MDL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-current-mdl)

[NET_BUFFER_CURRENT_MDL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-current-mdl-offset)

[NdisGetPoolFromNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetpoolfromnetbuffer)

For more information on how to use net buffers, see
[NET_BUFFER Architecture](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-architecture).

## See also

[NET_BUFFER_CHECKSUM_BIAS](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-checksum-bias)

[NET_BUFFER_CURRENT_MDL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-current-mdl)

[NET_BUFFER_CURRENT_MDL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-current-mdl-offset)

[NET_BUFFER_DATA_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-length)

[NET_BUFFER_DATA_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-data-offset)

[NET_BUFFER_FIRST_MDL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-first-mdl)

[NET_BUFFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_buffer_header)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters)

[NET_BUFFER_MINIPORT_RESERVED](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-miniport-reserved)

[NET_BUFFER_NEXT_NB](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-next-nb)

[NET_BUFFER_PROTOCOL_RESERVED](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-protocol-reserved)

[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisGetPoolFromNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetpoolfromnetbuffer)

[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete)

[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart)

[NdisRetreatNetBufferListDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferlistdatastart)

[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)
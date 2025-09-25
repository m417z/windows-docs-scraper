# _NET_BUFFER_LIST structure

## Description

The NET_BUFFER_LIST structure specifies a linked list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures.

## Members

### `Next`

The next **NET_BUFFER_LIST** structure in the chain.

Drivers should not access this member directly. Instead, they should call the [**NET_BUFFER_LIST_NEXT_NBL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_next_nbl) macro.

### `FirstNetBuffer`

The first [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) on this **NET_BUFFER_LIST**.

Drivers should not access this member directly. Instead, they should call the [**NET_BUFFER_LIST_FIRST_NB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_first_nb) macro.

### `Link`

Reserved for NDIS.

### `NetBufferListHeader`

A [NET_BUFFER_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_buffer_list_header) structure.

### `Context`

A pointer to a
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure.
Protocol and miniport drivers use this structure to store information about the NET_BUFFER_LIST
structure. Information stored in the NET_BUFFER_LIST_CONTEXT structure is opaque to NDIS and other
drivers in the stack.

Use the following functions and macros to access data in the NET_BUFFER_LIST_CONTEXT structure:

[NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext)

[NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext)

[NET_BUFFER_LIST_CONTEXT_DATA_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_start)

[NET_BUFFER_LIST_CONTEXT_DATA_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_size)

### `ParentNetBufferList`

If this NET_BUFFER_LIST structure is a clone of another NET_BUFFER_LIST structure, this member
specifies a pointer to the parent NET_BUFFER_LIST structure. Otherwise, this parameter is **NULL**. A driver
uses the
[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist) function to create a clone.

### `NdisPoolHandle`

A pool handle that identifies the NET_BUFFER_LIST pool from which the NET_BUFFER_LIST structure
was allocated.

### `NdisReserved`

Reserved for use by NDIS.

### `ProtocolReserved`

Reserved for use by protocol drivers.

### `MiniportReserved`

Reserved for use by miniport drivers.

### `Scratch`

Data that is defined by the current owner of the NET_BUFFER_LIST structure. The current owner,
either NDIS or an NDIS driver, can use this member for their own purposes. When the NET_BUFFER_LIST
structure is initially allocated, this member is **NULL**. After the current owner relinquishes ownership,
NDIS or another driver can overwrite this member.

### `SourceHandle`

A handle that NDIS provided to the driver in a binding or attaching operation by using one of the
following driver-supplied routines:

#### Miniport Driver

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

#### Protocol Driver

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

#### Filter Driver

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

NDIS uses
**SourceHandle** to return the NET_BUFFER_LIST structure to the driver that sent the NET_BUFFER_LIST
structure.

### `NblFlags`

This member contains flags that can be combined with a bitwise OR operation.

Use the
[NdisTestNblFlag](https://learn.microsoft.com/windows-hardware/drivers/network/ndistestnblflag),
[NdisTestNblFlags](https://learn.microsoft.com/windows-hardware/drivers/network/ndistestnblflags),
[NdisSetNblFlag](https://learn.microsoft.com/windows-hardware/drivers/network/ndissetnblflag), and
[NdisClearNblFlag](https://learn.microsoft.com/windows-hardware/drivers/network/ndisclearnblflag) macros to access the
flags.

Intermediate drivers and filter drivers can set the following flags if they do not modify data that
is associated with a NET_BUFFER_LIST. For example, if the data did not change, NDIS might reuse the
original information from which the NET_BUFFER_LIST was created.

#### NDIS_NBL_FLAGS_SEND_READ_ONLY

If set, the NET_BUFFER_LIST structure and its data are read-only for send operations.

#### NDIS_NBL_FLAGS_RECV_READ_ONLY

If set, the NET_BUFFER_LIST structure and its data are read-only for receive operations.

A driver can set the following flags even if it does not split the associated Ethernet frame:

#### NDIS_NBL_FLAGS_IS_IPV4

All of the Ethernet frames in this NET_BUFFER_LIST structure are IPv4 frames. If this flag is
set, the header-data split provider must not set the NDIS_NBL_FLAGS_IS_IPV6 flag.

#### NDIS_NBL_FLAGS_IS_IPV6

All of the Ethernet frames in this NET_BUFFER_LIST structure are IPv6 frames. If this flag is
set, the header-data split provider must not set the NDIS_NBL_FLAGS_IS_IPV4 flag.

#### NDIS_NBL_FLAGS_IS_TCP

All of the Ethernet frames in this NET_BUFFER_LIST structure are TCP frames. If this flag is
set, the header-data split provider must not set the NDIS_NBL_FLAGS_IS_UDP flag, and the provider must
set the NDIS_NBL_FLAGS_IS_IPV4 flag or the NDIS_NBL_FLAGS_IS_IPV6 flag.

#### NDIS_NBL_FLAGS_IS_UDP

All of the Ethernet frames in this NET_BUFFER_LIST structure are UDP frames. If this flag is
set, the header-data split provider must not set the NDIS_NBL_FLAGS_IS_TCP flag, and the provider must
set the NDIS_NBL_FLAGS_IS_IPV4 flag or the NDIS_NBL_FLAGS_IS_IPV6 flag.

#### NDIS_NBL_FLAGS_IS_LOOPBACK_PACKET

All of the packets that are associated with this NET_BUFFER_LIST structure are loopback
packets.

If the header-data split provider does not split the associated Ethernet frame, the miniport driver
must indicate the NET_BUFFER_LIST structure with the following flags cleared:

#### NDIS_NBL_FLAGS_HD_SPLIT

The header and data are split in all of the Ethernet frames that are associated with this
NET_BUFFER_LIST structure.

#### NDIS_NBL_FLAGS_SPLIT_AT_UPPER_LAYER_PROTOCOL_HEADER

All of the Ethernet frames in this NET_BUFFER_LIST are split at the beginning of the upper layer
protocol header. If this flag is set, the header-data split provider must set the
NDIS_NBL_FLAGS_IS_IPV4 flag or the NDIS_NBL_FLAGS_IS_IPV6 flag. Also, the provider can set the
NDIS_NBL_FLAGS_IS_TCP flag or the NDIS_NBL_FLAGS_IS_UDP flag, but the provider must not set the
NDIS_NBL_FLAGS_SPLIT_AT_UPPER_LAYER_PROTOCOL_PAYLOAD flag.

#### NDIS_NBL_FLAGS_SPLIT_AT_UPPER_LAYER_PROTOCOL_PAYLOAD

All of the Ethernet frames in this NET_BUFFER_LIST structure are split at the beginning of the
TCP or UDP payload. If this flag is set, the header-data split provider must set the
NDIS_NBL_FLAGS_IS_IPV4 flag or the NDIS_NBL_FLAGS_IS_IPV6 flag. Also, the provider must set the
NDIS_NBL_FLAGS_IS_TCP flag or the NDIS_NBL_FLAGS_IS_UDP flag, but the provider must not set the
NDIS_NBL_FLAGS_SPLIT_AT_UPPER_LAYER_PROTOCOL_HEADER flag.

### `ChildRefCount`

If this NET_BUFFER_LIST structure has clones (is a parent), this member specifies the number of
outstanding clones. Otherwise, this member is zero.

### `Flags`

Attributes of the NET_BUFFER_LIST structure. The following definitions specify a bit mask for a set
of flags:

#### NBL_FLAGS_PROTOCOL_RESERVED

This set is reserved for protocol drivers.

**Note** Starting with NDIS 6.30, two additional bits are available for protocol use: 0x00000003. A NDIS 6.30 protocol may use these bits if and only if [NdisGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetversion) returns a value greater than or equal to **NDIS_RUNTIME_VERSION_630**. Protocols must not use these bits on earlier versions of NDIS, because prior to 6.30, NDIS uses them internally.

#### NBL_FLAGS_MINIPORT_RESERVED

This set is reserved for miniport drivers.

#### NBL_FLAGS_SCRATCH

The current owner of the NET_BUFFER_LIST structure, either NDIS or an NDIS driver, can use this
set. When the current owner relinquishes ownership, NDIS or another driver can overwrite these
flags.

#### NBL_FLAGS_NDIS_RESERVED

This set is reserved for NDIS.

### `Status`

The final completion status of a network data operation on this NET_BUFFER_LIST structure.
Miniport drivers write this value before calling the
[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) function. Miniport drivers specify one of the following values:

#### NDIS_STATUS_SUCCESS

All the network data described by NET_BUFFER structures associated with this NET_BUFFER_LIST
structure was successfully transmitted over the network.

#### NDIS_STATUS_INVALID_LENGTH

The size of the data in some NET_BUFFER structures associated with this NET_BUFFER_LIST
structure was too large for the underlying NIC.

#### NDIS_STATUS_RESOURCES

The send request for this NET_BUFFER_LIST structure failed due to insufficient resources.

#### NDIS_STATUS_FAILURE

This send request for this NET_BUFFER_LIST structure failed due to some reason other than those
stated in the previous three values.

#### NDIS_STATUS_SEND_ABORTED

NDIS called the
[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send) function to
cancel the send operation for this NET_BUFFER_LIST structure.

#### NDIS_STATUS_RESET_IN_PROGRESS

The miniport driver aborted the send request due to a reset.

#### NDIS_STATUS_PAUSED

If a driver must reject send requests because it is paused, it sets the complete status in each
affected NET_BUFFER_LIST to NDIS_STATUS_PAUSED.

### `NdisReserved2`

Reserved for NDIS.

### `NetBufferListInfo`

An array of values containing information that is common to all NET_BUFFER structures in the list.
This information is often referred to as "out-of-band (OOB) data."

Use the
[NDIS_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblinfo/ne-nblinfo-ndis_net_buffer_list_info) enumeration values with the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro to set and
get values in the
**NetBufferListInfo** array.

## Remarks

NDIS drivers can call any of the following functions to allocate and initialize a NET_BUFFER_LIST
structure:

[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)

[NdisAllocateFragmentNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefragmentnetbufferlist)

[NdisAllocateReassembledNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatereassemblednetbufferlist)

All NET_BUFFER structures associated with a NET_BUFFER_LIST structure have the attributes that are
specified by the
**NetBufferListInfo** and
**Context** members.

When a driver calls the
[NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists) or
[NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists) function,
it loses ownership of:

* The specified NET_BUFFER_LIST structure.
* The attached
  [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures and MDLs.
* Any attached NDIS_REQUEST_CONTROLs.
* All
  **NetBufferListInfo** data that is associated with the NET_BUFFER_LIST structure.

The current owner of a list of NET_BUFFER_LIST structures can move a NET_BUFFER_LIST structure to
another list. However, all NET_BUFFER structures associated with a NET_BUFFER_LIST structure should stay
with the same NET_BUFFER_LIST structure. Only the driver that created the NET_BUFFER structures can move
them to a different NET_BUFFER_LIST structure. The current owner cannot modify a NET_BUFFER structure's
**Next** member.

A list of NET_BUFFER_LIST structures is a simple singly linked and NULL-terminated list. To move a
NET_BUFFER_LIST structure to a different list, make appropriate updates to the
**Next** members in both the source and destination lists.

To access members of the NET_BUFFER_LIST structure, use the following macros and functions:

[NET_BUFFER_LIST_NEXT_NBL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-next-nbl)

[NET_BUFFER_LIST_FIRST_NB](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-first-nb)

[NET_BUFFER_LIST_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-flags)

[NET_BUFFER_LIST_MINIPORT_RESERVED](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT_DATA_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_start)

[NET_BUFFER_LIST_CONTEXT_DATA_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_size)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NET_BUFFER_LIST_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-status)

[NET_BUFFER_LIST_PROTOCOL_RESERVED](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisGetPoolFromNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetpoolfromnetbufferlist)

For more information on how to use net buffers, see
[NET_BUFFER Architecture](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-architecture).

## See also

[NDIS_NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblinfo/ne-nblinfo-ndis_net_buffer_list_info)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NET_BUFFER_LIST_CONTEXT_DATA_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_size)

[NET_BUFFER_LIST_CONTEXT_DATA_START](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_context_data_start)

[NET_BUFFER_LIST_FIRST_NB](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-first-nb)

[NET_BUFFER_LIST_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-flags)

[NET_BUFFER_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_buffer_list_header)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NET_BUFFER_LIST_MINIPORT_RESERVED](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_NEXT_NBL](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-next-nbl)

[NET_BUFFER_LIST_PROTOCOL_RESERVED](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-status)

[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist)

[NdisAllocateFragmentNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefragmentnetbufferlist)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlist)

[NdisAllocateNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferlistcontext)

[NdisAllocateReassembledNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatereassemblednetbufferlist)

[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists)

[NdisClearNblFlag](https://learn.microsoft.com/windows-hardware/drivers/network/ndisclearnblflag)

[NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext)

[NdisGeneratePartialCancelId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgeneratepartialcancelid)

[NdisGetPoolFromNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetpoolfromnetbufferlist)

[NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists)

[NdisSetNblFlag](https://learn.microsoft.com/windows-hardware/drivers/network/ndissetnblflag)

[NdisTestNblFlag](https://learn.microsoft.com/windows-hardware/drivers/network/ndistestnblflag)

[NdisTestNblFlags](https://learn.microsoft.com/windows-hardware/drivers/network/ndistestnblflags)
# _NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure is the basic building block of a TCP chimney offload
state tree. An offload state tree can contain one or more NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structures.

## Members

### `Header`

The header of the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure. The header is formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure. The
NDIS_OBJECT_HEADER structure contains the revision number of the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structure, the type of offload state that immediately follows the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structure in memory, and the size of the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure, including the
header, in bytes.

The
**Type** member of the NDIS_OBJECT_HEADER structure indicates the type of offload state, and by
implication, the specific offload state structure (or structures) that immediately follow the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in memory.

The following OFFLOAD_STATE_TYPE values are supported:

#### NeighborOffloadConstState

Specifies the constant neighbor state. This state is formatted as a
[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const) structure.

#### NeighborOffloadCachedState

Specifies the cached neighbor state. This state is formatted as a
[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached) structure.

#### NeighborOffloadDelegatedState

Specifies the delegated neighbor state. This state is formatted as a
[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated) structure.

#### NeighborOffloadState

Specifies all of the neighbor state information, including the constant, cached, and delegated
neighbor state. This state is formatted as a NEIGHBOR_OFFLOAD_STATE_CONST structure, followed by a
NEIGHBOR_OFFLOAD_STATE_CACHED structure, followed by a NEIGHBOR_OFFLOAD_STATE_DELEGATED
structure.

#### Ip4OffloadConstState

Specifies the constant path state (IPv4). This state is formatted as a
[PATH_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_const) structure.

#### Ip4OffloadCachedState

Specifies the cached path state (IPv4). This state is formatted as a
[PATH_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_cached) structure.

#### Ip4OffloadDelegatedState

Specifies the delegated path state (IPv4). This state is formatted as a
[PATH_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_delegated) structure. Currently there is no delegated path state. The
PATH_OFFLOAD_STATE_DELEGATED structure does not contain any variables.

#### Ip4OffloadState

Specifies all of the path state (IPv4), including the constant, cached, and delegated path
state. This state is formatted as a PATH_OFFLOAD_STATE_CONST structure, followed by a
PATH_OFFLOAD_STATE_CACHED structure, followed by a PATH_OFFLOAD_STATE_DELEGATED structure.

#### Ip6OffloadConstState

Specifies the constant path state (IPv6). This state is formatted as a PATH_OFFLOAD_STATE_CONST
structure.

#### Ip6OffloadCachedState

Specifies the cached path state (IPv6). This state is formatted as a PATH_OFFLOAD_STATE_CACHED
structure.

#### Ip6OffloadDelegatedState

Specifies the delegated path state (IPv6). This state is formatted as a
PATH_OFFLOAD_STATE_DELEGATED structure. Currently, there is no delegated path state. The
PATH_OFFLOAD_STATE_DELEGATED structure does not contain any variables.

#### Ip6OffloadState

Specifies all of the path state information(IPv6), including the constant, cached, and delegated
path state. This state is formatted as a PATH_OFFLOAD_STATE_CONST structure, followed by a
PATH_OFFLOAD_STATE_CACHED structure, followed by a PATH_OFFLOAD_STATE_DELEGATED structure.

#### TcpOffloadConstState

Specifies the constant TCP state. This state is formatted as a
[TCP_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_const) structure.

#### TcpOffloadCachedState

Specifies the cached TCP state. This state is formatted as a
[TCP_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_cached) structure.

#### TcpOffloadDelegatedState

Specifies the delegated TCP state. This state is formatted as a
[TCP_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated) structure.

#### TcpOffloadResourceState

Reserved. This OFFLOAD_STATE_TYPE value, as well as the TCP_OFFLOAD_RESOURCE_STATE structure,
are currently not used.

#### TcpOffloadState

Specifies all of the TCP state information, including the constant, cached, and delegated TCP
state. This state is formatted as a TCP_OFFLOAD_STATE_CONST structure, followed by a
TCP_OFFLOAD_STATE_CACHED structure, followed by a TCP_OFFLOAD_STATE_DELEGATED structure.

#### FilterReservedOffloadState

Reserved for filter drivers.

### `NextBlock`

A pointer to the next NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure at the offload state layer
(neighbor, path, or TCP) indicated by the
**Type** member of the
**Header** member. NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures that are linked through
**NextBlock** pointers are always at the same layer of the offload state. A
**NextBlock** value of **NULL** indicates that there is no additional next
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure at this level.

### `DependentBlockList`

A pointer to an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure that is at a dependent layer of the
offload state (a higher layer in the offload state tree). For TCP chimney offload:

* The
  **DependentBlockList** member of an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure at the neighbor layer
  can point only to an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure at the path layer.
* The
  **DependentBlockList** member of an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure at the path layer can
  point only to an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure at the TCP layer.
* The
  **DependentBlockList** member of an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure at the TCP layer is
  always **NULL**.

A
**DependentBlockList** value of **NULL** indicates that there is no dependent
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure.

### `_NDIS_MINIPORT_OFFLOAD_BLOCK_LIST`

### `Status`

The completion status of an initiate offload, query offload, update offload, invalidate offload,
or terminate offload operation that the offload target performed on the state associated with, or
referenced by, the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure. Depending on the operation, the offload
target writes one of the following NDIS_STATUS values to the
**Status** member:

#### NDIS_STATUS_SUCCESS

Initiate offload: The offload target successfully offloaded the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure and the state associated with all of the immediately
dependent NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures.

Query, update, invalidate, or terminate offload: The offload target successfully performed the
operation on the state associated with, or referenced by, the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structure.

#### NDIS_STATUS_OFFLOAD_PARTIAL_SUCCESS

Initiate offload: The offload target successfully offloaded the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure, but failed to offload the state associated with one or
more of the immediately dependent NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_FAILURE

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure. The cause of the failure cannot be categorized.

Query, update, invalidate, or terminate offload: The offload target failed to perform the operation
on the state associated with, or referenced by, the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structure.

#### NDIS_STATUS_RESOURCES

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the offload target could not allocate sufficient
host memory.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_TCP_ENTRIES

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the offload target could not allocate a TCP
connection state object.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_PATH_ENTRIES

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the offload target could not allocate a path state
object.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_NEIGHBOR_ENTRIES

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the offload target could not allocate a neighbor
state object.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_HW_ADDRESS_ENTRIES

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the host stack specified a non-**NULL****DlSourceAddress** member in the
[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const) structure, and the offload target either does not support
configurable source MAC addresses or cannot accept additional source MAC addresses.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_IP_ADDRESS_ENTRIES

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the offload target could not allocate a data
structure for the source IP address that is referenced by the
**SourceAddress** pointer in the
[PATH_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_const) structure.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_TCP_XMIT_BUFFER

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the offload target could not allocate enough TCP
transmit buffers.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_TCP_RCV_BUFFER

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the offload target could not allocate enough TCP
receive buffers.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_TCP_RCV_WINDOW

Initiate offload: The offload target failed to offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure because the
**InitialRcvWnd** member specified in the
[TCP_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_cached) structure is larger than the offload target can support.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_VLAN_ENTRIES

Initiate offload: The offload target has run out of resources for tracking additional VLAN IDs.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_VLAN_MISMATCH

Initiate offload: The neighbor
**VlanId** is non-zero and does not match one of the interface VLAN IDs.

Query, update, invalidate, or terminate offload: Not an allowed status value.

#### NDIS_STATUS_OFFLOAD_PATH_MTU

The path MTU for the TCP connection is larger than the offload target supports.

Query, update, invalidate, or terminate offload: Not an allowed status value.

### `NdisReserved`

Reserved for use by NDIS.

### `MiniportOffloadContext`

A pointer to a memory location into which the offload target writes a PVOID value. The PVOID value
references the offload context area in which the offload target stores the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure. If the state is a new state to be offloaded by the offload
target, the memory location pointed to by
**MiniportOffloadContext** contains a **NULL** value. After offloading the state, the offload target
writes a PVOID value to this memory location. The PVOID value supplied by the offload target references
the offload context area into which the state was offloaded. If the
**MiniportOffloadContext** member itself is **NULL**, the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure is a
placeholder in the offload state tree.

### `NdisOffloadHandle`

The handle that the offload target supplies in subsequent calls to the
[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate) function or the
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) function when making an indication on the offload state associated
with this NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure.

### `ProtocolReserved`

Reserved for use by protocol drivers, which can use this area for their own purposes. Offload
targets must not modify this value.

### `MiniportReserved`

Reserved for use by offload targets, which can use this area for their own purposes, such as
queuing up the offload state associated with the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure.

### `ImReserved`

Reserved for use by intermediate drivers, which can use this area for their own purposes. Offload
targets must not modify this value.

### `Scratch`

The offload target can use this area for internal tracking. The information in this area is valid
only while the offload target has ownership of the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST.

### `SourceHandle`

This member is not significant for an offload target. An offload target must not modify this
member.

### `PortNumber`

A port number that identifies a miniport adapter port. To assign a miniport adapter port number,
call the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function. A zero
value identifies the default port of a miniport adapter. Use the default port if the miniport driver has
not allocated ports for the specified adapter.

### `NetBufferListChain`

When the host stack specifies a **NULL** value,
**NetBufferListChain** is not significant and can be ignored by the offload target.

When the host stack specifies a non-**NULL** value,
**NetBufferListChain** points to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that can be a
stand-alone structure or the first structure in a linked list of such structures. Each NET_BUFFER_LIST
structure in the linked list describes one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. The NET_BUFFER structure
maps to a chain of memory descriptor lists (MDLs). The NET_BUFFER_LIST and associated structures are
locked so that they remain resident in physical memory. However, they are not mapped into system
memory.

The MDLs associated with the NET_BUFFER structures contain data that the host stack is passing to the
offload target as part of the offload operation. The offload target completes such data asynchronously
back to the host stack by calling the appropriate
**NdisTcpOffload*Xxx*Complete** function. At present, the linked list can contain just one type of data:
outstanding send data. For more information, see
[Handling Outstanding Send Data During and After an Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/handling-outstanding-send-data-during-and-after-an-offload-operation).

An offload target can pass outstanding send data to the host stack when terminating the offload of a
TCP connection. In this case, the offload target specifies a non-**NULL** value for the
**NetBufferListChain** member when calling the
[NdisMTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismterminateoffloadcomplete) function. If the offload target is not passing send data for a TCP
connection that is being terminated, it must specify a **NULL** value for the
**NetBufferListChain** member.

## Remarks

NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures can be linked together to build the framework of a TCP
chimney
[offload state tree](https://learn.microsoft.com/windows-hardware/drivers/network/offload-state-tree).

Through NDIS, the host stack passes an
*OffloadBlockList* pointer, which references an offload state tree to one of the following functions
of an offload target:

* [MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler)
* [MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler)
* [MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler)
* [MiniportInvalidateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_invalidate_offload_handler)
* [MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

The offload target returns the tree to the host stack by passing the same pointer to the corresponding
completion function:

* [NdisMInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminitiateoffloadcomplete)
* [NdisMQueryOffloadStateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismqueryoffloadstatecomplete)
* [NdisMUpdateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismupdateoffloadcomplete)
* [NdisMInvalidateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminvalidateoffloadcomplete)
* [NdisMTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismterminateoffloadcomplete)

An NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure can be immediately followed in memory by an
[offload state structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated) that contains
state to be offloaded, queried, updated, invalidated, or terminated. The
**Type** member of the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure's
**Header** specifies the type of offload state, and by implication, the specific offload state
structure (or structures) that follow the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in memory.

The host stack and offload target use the
***MiniportOffloadContext** and
**NdisOffloadHandle** members of an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure to reference offloaded
state. For more information, see
[Storing and Referencing
Offloaded State](https://learn.microsoft.com/windows-hardware/drivers/network/storing-and-referencing-offloaded-state).

An NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure can perform one of several functions in an offload state
tree. It can function as a placeholder, a linker, or it can convey new state to be offloaded by the
offload target. For more information, see
[Placeholders, Linkers, and
New Offloads](https://learn.microsoft.com/windows-hardware/drivers/network/placeholders--linkers--and-new-offloads).

Before completing an initiate offload, query offload, update offload, invalidate offload, or terminate
offload operation, an offload target must write the completion status to the
**Status** member of each NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in the state tree.

## See also

[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler)

[MiniportInvalidateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_invalidate_offload_handler)

[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler)

[MiniportTerminateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_terminate_offload_handler)

[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached)

[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)

[NdisMInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminitiateoffloadcomplete)

[NdisMInvalidateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminvalidateoffloadcomplete)

[NdisMQueryOffloadStateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismqueryoffloadstatecomplete)

[NdisMTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismterminateoffloadcomplete)

[NdisMUpdateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismupdateoffloadcomplete)

[NdisTcpOffloadEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_event_indicate)

[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate)

[PATH_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_cached)

[PATH_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_const)

[PATH_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_delegated)

[TCP_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_cached)

[TCP_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_const)

[TCP_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated)
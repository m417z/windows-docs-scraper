# INDICATE_OFFLOAD_EVENT_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls a protocol driver's or intermediate driver's
*ProtocolIndicateOffloadEvent* function to post an indication that was initiated by an underlying
driver's or offload target's call to the
[NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate) function.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a context area that was allocated by the protocol driver. The driver maintains the per
binding context information in this context area. The driver supplied this handle to NDIS when the
driver called the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `OffloadBlockList` [in]

A pointer to an
[NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_protocol_offload_block_list) structure. This structure identifies the offloaded state object
on which the indication is being made. Note that there is only one NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structure. There is not a linked list of such structures.

The underlying offload target supplies a valid
*OffloadBlockList* pointer when making a
**NeighborReachabilityQuery** indication. In this case, the offload target supplies a
[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const) structure, a
[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached) structure, and a
[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated) structure (in that order) immediately following the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure referenced by the
*OffloadBlockList* pointer.

### `IndicationCode` [in]

The event being indicated as one of the following INDICATE_OFFLOAD_EVENT values:

#### NeighborReachabilityQuery

Indicates that a neighbor cache entry (NCE) has become stale. For more information about NCEs,
see RFC 2461.

#### NeighborReachabilityInDoubt

Reserved.

## Remarks

The implementation of this function for intermediate drivers is to be determined.

## See also

[NDIS_PROTOCOL_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_protocol_offload_block_list)

[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached)

[NEIGHBOR_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_const)

[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated)

[NdisMOffloadEventIndicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismoffloadeventindicate)